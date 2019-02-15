#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Header.h"
using namespace std;
// File loading/unloading functions
void loadIt(vector <books> &a, vector <journal> &b, vector <magazine> &c)
{
    ifstream inFile;
    inFile.open ("librarystor.txt");
    books tempb; // temp variable of book type to add books
    journal tempj; // temp variable to add journals
    magazine tempm; // temp variable to add magazine
    // following are temp variables to add items
    int size;
    int iD;
    int status;
    string name;
    string garbage; // used to go to next line when trying to input string name
    string aName;
    int volume;
    int issueNumber;
    int check; // do differentiate between book(1), magazine(3) and journal(2)
    inFile >> size; // to find the number of times the loop needs to be used to input data
    for (int i = 0; i< size; i++)
    {
        inFile >> check;
        if (check == 1)
        {
            inFile >> iD >> status;
            getline(inFile,garbage);
            getline(inFile,name);
            getline(inFile,aName);
        
            tempb.setID(iD);
            tempb.setName(name);
            tempb.setAName(aName);
            tempb.setStatus(status);
            a.push_back(tempb);
        }
        if (check == 2)
        {
            inFile >> iD >> status>> volume;
            getline(inFile,garbage);
            getline(inFile,name);
            tempj.setID(iD);
            tempj.setName(name);
            tempj.setVolume(volume);
            tempj.setStatus(status);
            b.push_back(tempj);
        }
        if ( check == 3)
        {
            inFile >> iD >> status >> issueNumber;
            getline(inFile,garbage);
            getline(inFile,name);
            tempm.setID(iD);
            tempm.setName(name);
            tempm.setIssue(issueNumber);
            tempm.setStatus(status);
            c.push_back(tempm);
        }
    }
}
void unloadIT(vector <books> &a, vector <journal> &b, vector <magazine> &c)
{
    double totalSize = a.size()+b.size()+c.size();
    ofstream outfile;
    outfile.open("librarystor.txt");
    outfile << totalSize << endl;
    // in the following loops the numbers 1,2,3 are used to differentiate between types when loading items for next time
    for (int i = 0; i < a.size(); i++)
    {
        outfile << "1" <<endl;
        outfile << a[i].getID() << " "<< a[i].getStatus() << endl;
        outfile << a[i].getName() << endl;
        outfile << a[i].getAName() << endl;
    }
    for (int j = 0; j < b.size(); j++)
    {
        outfile << "2" <<endl;
        outfile << b[j].getID() << " "<< b[j].getStatus() << " " << b[j].getVolume() << endl;
        outfile << b[j].getName() << endl;
    }
    for (int m = 0; m < c.size(); m++)
    {
        outfile << "3" <<endl;
        outfile << c[m].getID() << " "<< c[m].getStatus() << " " << c[m].getIssue()<< endl;
        outfile << c[m].getName() << endl;
    }
}

// Functions used for Search catalog
// template to output all the books/magazine/journal available
template <class Type>
void putOut (vector <Type> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        a[i].print();
        cout << endl;
    }
}
// function to search book by author name
void searchAuthor (vector<books> &a)
{
    books temp;
    string tempName;
    bool eMessage = false;
    cout <<"Enter the name of the author: ";
    cin.ignore (numeric_limits<streamsize>::max(), '\n'); // used to ignore previous inputs when taking the current input
    getline(cin, tempName);
    temp.setAName(tempName);
    for (int i = 0; i < a.size(); i++)
    {
        if ( temp.getAName() == a[i].getAName())
        {
            a[i].print();
            cout << endl;
            eMessage = true;
        }
    }
    if (eMessage == false)
    {
        cout <<"The author "<< tempName << " was not found." << endl;
    }
}
// function template to search for a book/magazine/journal
template <class Type>
void searchIt(vector<Type> &a)
{
    Type temp;
    string litName;
    bool eMessage= false; // used to output not found when looking for something
    cout << "Enter the name of the literature you want to look for: ";
    cin.ignore (numeric_limits<streamsize>::max(), '\n');// used to ignore previous inputs when taking the current input
    getline(cin, litName);
    temp.setName(litName);
    for (int i = 0; i < a.size(); i++)
    {
        if (temp.getName() == a[i].getName())
        {
            cout << litName <<" was found." <<endl;
            a[i].print();
            eMessage = true;
        }
    }
    if (eMessage== false)
    {
        cout << litName<<" not found." <<endl;
    }

}

// Function to check out a book/magazine/journal
template <class Type>
void checkOut (vector <Type> &a)
{
    Type temp;
    string litName;
    char choice;
    bool eMessage= false;
    bool checkRe = false; // to make sure response is either y or n
    cout << "Enter the name of the literature you want to look for: ";
    cin.ignore (numeric_limits<streamsize>::max(), '\n');// used to ignore previous inputs when taking the current input
    getline(cin, litName);
    temp.setName(litName);
    for (int i = 0; i < a.size(); i++)
    {
        if (temp.getName() == a[i].getName())
        {
            cout << litName <<" was found." <<endl;
            a[i].print();
            eMessage = true;
            if (a[i].getStatus() == 1)
            {
                cout << litName<<" is not available." << endl;
            }
            if (a[i].getStatus() == 0)
            {
                
                while (checkRe == false)
                {
                    cout << litName <<" is available\nDo you want to check it out(y for yes and n for no)?" <<endl;
                    cin >> choice;
                    switch (choice)
                    {
                        case 'y':
                        {
                            a[i].setStatus(1);
                            cout << "Book checked out." <<endl;
                            checkRe = true;
                            break;
                        }
                        case 'n':
                        {
                            checkRe = true;
                            break;
                        }
                        default:
                        {
                            cout << "error in input" << endl;
                            break;
                        }
                    }

                }
                
            }
            
        }
    }
    if (eMessage== false)
    {
        cout << litName<<" not found." <<endl;
    }
}
// Function to return a book/journal/magazine
template <class Type>
void returnIt (vector <Type> &a)
{
    Type temp;
    string litName;
    char choice;
    bool eMessage= false;
    bool checkRe = false; // to make sure response is either y or n
    cout << "Enter the name of the literature you want to look for: ";
    cin.ignore (numeric_limits<streamsize>::max(), '\n');// used to ignore previous inputs when taking the current input
    getline(cin, litName);
    temp.setName(litName);
    for (int i = 0; i < a.size(); i++)
    {
        if (temp.getName() == a[i].getName())
        {
            cout << litName <<" was found." << endl;
            a[i].print();
            eMessage = true;
            if (a[i].getStatus() == 0)
            {
                cout << litName<<" is already in the library." << endl;
            }
            if (a[i].getStatus() == 1)
            {
                
                while (checkRe == false)
                {
                    cout << "Do you want to return it? (press y to return and n to keep)" << endl;
                    cin >> choice;
                    switch (choice)
                    {
                        case 'y':
                        {
                            a[i].setStatus(0);
                            cout << "Book returned." <<endl;
                            checkRe = true;
                            break;
                        }
                        case 'n':
                        {
                            checkRe = true;
                            break;
                        }
                        default:
                        {
                            cout << "error in input" <<endl;
                            break;
                        }
                    }
                }
            }
            
        }
    }
    if (eMessage== false)
    {
        cout << litName<<" not found." <<endl;
    }
}
// function to add  an item
void addIT(vector <books> &a, vector <journal> &b, vector <magazine> &c, char d)
{
    // char d let's the program tell the difference between adding a book or magazine or journal
    books tempb;
    journal tempj;
    magazine tempm;
    int tempID;
    string tempAName;
    string tempName;
    int tempVolume;
    int tempIssue;
    cout << "Please enter the name of the item: ";
    cin.ignore (numeric_limits<streamsize>::max(), '\n');
    getline(cin,tempName);
    cout << "Please enter the ID of the item.";
    cin >> tempID;
    if (d == '1')
    {
        cout << "Please enter the name of the author: ";
        cin.ignore (numeric_limits<streamsize>::max(), '\n');
        getline(cin, tempAName);
        tempb.setAName(tempAName);
        tempb.setID(tempID);
        tempb.setName(tempName);
        tempb.setStatus(0);
        a.push_back(tempb);
    }
    if ( d== '2')
    {
        cout << "Please enter Volume number of the journal: ";
        cin >> tempVolume;
        tempj.setVolume(tempVolume);
        tempj.setID(tempID);
        tempj.setName(tempName);
        tempj.setStatus(0);
        b.push_back(tempj);
    }
    if ( d == '3')
    {
        cout << "Please enter Issue number of the magazine: ";
        cin >> tempIssue;
        tempm.setIssue(tempIssue);
        tempm.setID(tempID);
        tempm.setName(tempName);
        tempm.setStatus(0);
        c.push_back(tempm);
    }
}
int main()
{
    vector<books> a;
    vector<magazine> c;
    vector<journal> b;
    char choice = '0';
    char sChoice;
    char bChoice;
    char jChoice;
    char mChoice;
    // following bools are present to make sure the response is only the desired one
    bool sEnd = false;
    bool cEnd = false;
    bool rEnd = false;
    bool aEnd = false;
    loadIt(a, b, c); // to load the list of material the library has
    while(choice != '5')
    {
        cout << "Library System" << endl;
        cout << "1. Search Catalog" <<endl;
        cout << "2. Check Out" <<endl;
        cout << "3. Return" <<endl;
        cout << "4. Add a new item" <<endl;
        cout << "5. Exit" <<endl;
        cout << "Select an option from 1 - 5: ";
        cin >> choice;
        switch (choice)
        {
            case '1':// Case to search Catalog
            {
                sEnd = false;
                while (sEnd == false)
                {
                    cout << endl;
                    cout << "1. Book " << endl;
                    cout << "2. Journal " << endl;
                    cout << "3. Magazine " << endl;
                    cout << "4. Exit" <<endl;
                    cout << "Please select what you want to search for from option 1 - 3 or 4 for exit: ";
                    cin >> sChoice;
                    if (sChoice == '1')
                    {
                        cout << endl;
                        cout << "1. Search by book name" <<endl;
                        cout << "2. Search by author name" <<endl;
                        cout << "3. List out all the books" << endl;
                        cout << "Please select a choice from 1-3" <<endl;
                        cin >> bChoice;
                        if (bChoice == '1')
                        {
                            searchIt(a);
                        }
                        if (bChoice == '2')
                        {
                            searchAuthor(a);
                        }
                        if (bChoice == '3')
                        {
                            putOut(a);
                        }
                        else
                        {
                            cout << "Error in input." << endl;
                        }
                        sEnd = true;
                    }
                    if (sChoice == '2')
                    {
                        cout << endl;
                        cout << "1. Search by Journal name" <<endl;
                        cout << "2. List out all the Journals" << endl;
                        cout << "Please select a choice from 1-2" <<endl;
                        cin >> jChoice;
                        if (jChoice == '1')
                        {
                            searchIt(b);
                        }
                        if (jChoice == '2')
                        {
                            putOut(b);
                        }
                        else
                        {
                            cout << "Error in input" <<endl;
                        }
                        sEnd = true;
                        
                    }
                    if (sChoice == '3')
                    {
                        
                        cout << endl;
                        cout << "1. Search by Magazine name" <<endl;
                        cout << "2. List out all the Magazine" << endl;
                        cout << "Please select a choice from 1-2" <<endl;
                        cin >> mChoice;
                        if (mChoice == '1')
                        {
                            searchIt(c);
                        }
                        if (mChoice == '2')
                        {
                            putOut(c);
                        }
                        sEnd = true;
                    }
                    if (sChoice == '4')
                    {
                        sEnd = true;
                    }
                }
                break;
            }
            case '2': // Case to check out
            {
                cEnd = false;
                while (cEnd == false)
                {
                    cout << endl;
                    cout << "1. Book " << endl;
                    cout << "2. Journal " << endl;
                    cout << "3. Magazine " << endl;
                    cout << "4. Exit" <<endl;
                    cout << "Please select what you want to check out from option 1 - 3 or 4 for exit: ";
                    cin >> sChoice;
                    if (sChoice == '1')
                    {
                        checkOut(a);
                        cEnd = true;
                    }
                    if (sChoice == '2')
                    {
                        checkOut(b);
                        cEnd = true;
                    }
                    if (sChoice == '3')
                    {
                        
                        checkOut(c);
                        cEnd = true;
                    }
                    if (sChoice == '4')
                    {
                        cEnd = true;
                    }
                }
                break;
            }
            case '3': // Case to return
            {
                rEnd= false;
                while (rEnd == false)
                {
                    cout << endl;
                    cout << "1. Book " << endl;
                    cout << "2. Journal " << endl;
                    cout << "3. Magazine " << endl;
                    cout << "4. Exit" <<endl;
                    cout << "Please select what you want to check out from option 1 - 3 or 4 for exit: ";
                    cin >> sChoice;
                    if (sChoice == '1')
                    {
                        rEnd = true;
                        returnIt(a);
                    }
                    if (sChoice == '2')
                    {
                        rEnd = true;
                        returnIt(b);
                    }
                    if (sChoice == '3')
                    {
                        rEnd = true;
                        returnIt(c);
                    }
                    if (sChoice == '4')
                    {
                        rEnd = true;
                    }
                }
                break;
            }
            case '4': // Case to add an item
                aEnd = false;
            {
                while(aEnd == false)
                {
                    cout << endl;
                    cout << "1. Book " << endl;
                    cout << "2. Journal " << endl;
                    cout << "3. Magazine " << endl;
                    cout << "4. Exit" <<endl;
                    cout << "Please select what you want to check out from option 1 - 3 or 4 for exit: ";
                    cin >> sChoice;
                    if (sChoice == '1')
                    {
                        aEnd = true;
                        addIT(a, b, c, sChoice);
                        
                    }
                    if (sChoice == '2')
                    {
                        aEnd = true;
                        addIT(a, b, c, sChoice);
                        
                    }
                    if (sChoice == '3')
                    {
                        aEnd = true;
                        addIT(a, b, c, sChoice);
                        
                    }
                    if (sChoice == '4')
                    {
                        aEnd = true;
                    }
                }
                break;
            }
            case '5': //Case to exit
            {
                cout <<"Have a nice day" <<endl;
                unloadIT(a, b, c);
                break;
            }
            default:
            {
                cout << "Error in input.";
                break;
            }
        }
    }
    return 0;
}
