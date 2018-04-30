#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#include<iostream>
#include<string.h>

using namespace std;

class admin
{
protected:
    char pass[100];
public:
    admin()
    {
        strcpy(pass," ");
    }
    admin(char* p)
    {
        strcpy(pass,p);
    }
    void getid()
    {
        cout<<"\tEnter your password: ";
        cin>>pass;
    }
    void displayid()
    {
        cout<<"\n\tPassword: ";
        int l;

        l=strlen(pass);
        for(int i=0; i<l; i++)
        {
            cout<<"*";
        }
        cout<<endl;
    }

    bool operator == (admin ll) const
    {
        return(strcmp(pass,ll.pass)==0)? true:false;
    }
};

#endif // ADMIN_H_INCLUDED
