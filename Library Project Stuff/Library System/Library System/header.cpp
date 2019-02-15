//
//  header.cpp
//  Library System
//
//  Created by Mohammed Shaheryar on 4/1/18.
//  Copyright © 2018 Muazzam Shaheryar. All rights reserved.
//

#include <iostream>
#include <string>
#include "Header.h"
using namespace std;
// class material definitions
material:: material()
{
    iD = 0;
    name = " ";
    status = 3;
}
void material:: setID(int a)
{
    iD = a;
}

void material:: setStatus(int c)
{
    status = c;
}
void material::setName(string b)
{
    name = b;
}
string material::getName() const
{
    return name;
}
int material::getStatus() const
{
    return status;
}
int material::getID() const
{
    return iD;
}
// class books definitions
books:: books(int a, string b, int c, string d)
{
    setName(b);
    setStatus(c);
    setID(a);
    authorName = d;
}
books:: books ()
{
    setName(" ");
    setStatus(3);
    setID(0);
    authorName = " ";
}
void books::setAName(string a)
{
    authorName  = a;
}
string books::getAName() const
{
    return authorName;
}
void books::print() const
{
    cout << "Book ID: " << getID() <<endl;
    cout << "Book Name: " << getName() <<endl;
    if (getStatus() == 1)
    {
        cout << "Status: Checked Out" <<endl;
    }
    else if (getStatus() == 0)
    {
        cout << "Status: In the library" <<endl;
    }
    cout << "Author's Name: " << authorName <<endl;
}
// class journal definitions
journal::journal(int a,string b ,int c, int d)
{
    setName(b);
    setStatus(c);
    setID(a);
    volume = d;
}
journal::setID(int z)
{
    cout << "the first number is " << getID() << endl;
    
}
journal::journal()
{
    setName(" ");
    setStatus(3);
    setID(0);
    volume = 0;
}
void journal::setVolume(int a)
{
    volume = a;
}
int journal::getVolume() const
{
    return volume;
}
void journal::print() const
{
    cout << "Journal ID: " << getID() <<endl;
    cout << "Journal Name: " << getName() <<endl;
    if (getStatus() == 1)
    {
        cout << "Status: Checked Out" <<endl;
    }
    else if (getStatus() == 0)
    {
        cout << "Status: In the library" <<endl;
    }
    cout << "Volume: " << volume <<endl;
    
}
// class magazine definitions
magazine:: magazine(int a, string b, int c, int d)
{
    setID(a);
    setName(b);
    setStatus(c);
    issueNumber = d;
}
magazine:: magazine()
{
    setName(" ");
    setStatus(3);
    setID(0);
    issueNumber = 0;
}
void magazine::setIssue(int a)
{
    issueNumber = a;
}
int magazine::getIssue() const
{
    return issueNumber;
}
void magazine:: print() const
{
    cout << "Magazine ID: " << getID() <<endl;
    cout << "Magazine Name: " << getName() <<endl;
    if (getStatus() == 1)
    {
        cout << "Status: Checked Out" <<endl;
    }
    else if (getStatus() == 0)
    {
        cout << "Status: In the library" <<endl;
    }
    cout << "Issue Number: " << issueNumber <<endl;
}
