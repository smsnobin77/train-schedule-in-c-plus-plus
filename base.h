#ifndef BASE_H_INCLUDED
#define BASE_H_INCLUDED
#include <iostream>
#include <string.h>
using namespace std;

class base
{
protected:
    char name[100];
    char offday[100];
    char destin[100];
public:
    base()
    {
        strcpy(name," ");
        strcpy(offday," ");
        strcpy(destin," ");
    }
    base(char s[],char p[],char t[])
    {
        strcpy(name,s);
        strcpy(offday,p);
        strcpy(destin,t);
    }
    void getinfo()
    {
        cout<<"\tTrain name: ";
        cin>>name;
        cout<<"\tOffday : ";
        cin>>offday;
        cout<<"\tDestination: ";
        cin>>destin;
    }
    void displayinfo()
    {
        cout<<"\tName: "<<name<<endl;
        cout<<"\tOffday is: "<<offday<<endl;
        cout<<"\tDestination: "<<destin<<endl;
    }
    virtual void input()= 0;
    virtual void output()= 0;
};

#endif // BASE_H_INCLUDED
