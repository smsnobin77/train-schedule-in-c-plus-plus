#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class user
{
protected:
    char name[100];
    char password[100];
public:
    user()
    {
        strcpy(name," ");
        strcpy(password," ");
    }
    user(char s[],char p[])
    {
        strcpy(name,s);
        strcpy(password,p);
    }
    void getdata()
    {
        cout<<"\tEnter your name: ";
        cin>>name;
        cout<<"\tEnter your password: ";
        cin>>password;
    }
    void displaydata()
    {
        cout<<"\tName: "<<name<<endl;
        cout<<"\tPassword: ";
        int l;

        l=strlen(password);
        for(int i=0; i<l; i++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    void in(int pn)
    {
        ifstream ifile;
        ifile.open("f.txt",ios::in|ios::out|ios::binary);
        ifile.seekg(pn*sizeof(user));
        ifile.read((char*)this,sizeof(*this));
    }
    void out()
    {
        ofstream ofile;
        ofile.open("f.txt",ios::app | ios::binary);
        ofile.write((char*)this, sizeof(*this));
    }
    bool operator ==(user uu) const
    {
        if((strcmp(name,uu.name)==0) && (strcmp(password,uu.password)==0))
        {
//            cout<<"kaisa"<<endl;
            return true;
        }
        else
        {
//            cout<<"na"<<endl;
            return false;
        }
    }
};

#endif // USER_H_INCLUDED
