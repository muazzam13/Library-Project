
#ifndef Header_h
#define Header_h
#include <iostream>
#include <string>
using namespace std;
// Declaration of Base class
class material
{
public:
    material();
    void setName(string b);
    void setID(int a);
    void setStatus(int c);
    int getStatus() const;
    string getName() const;
    int getID() const;
private:
    int iD;
    string name;
    int status;
    
};
// Declaration of class books an inheritated class of class material
class books : public material
{
public:
    books(int a,string b ,int c, string d);
    books();
    void setAName(string a);
    string getAName() const;
    void print() const;
    
private:
    string authorName;
};
// Declaration of class journal an inheritated class of class material
class journal : public material
{
public:
    journal(int a,string b ,int c, int d);
    journal();
    void setVolume(int a);
    int getVolume() const;
    void print() const;

private:
    int volume;
};
// Declaration of class magazine an inheritated class of class material
class magazine : public material
{
public:
    magazine(int a,string b ,int c, int d);
    magazine();
    void setIssue(int a);
    int getIssue() const;
    void print()const;

private:
    
    int issueNumber;
};
#endif /* Header_h */
