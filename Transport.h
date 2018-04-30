#ifndef TRANSPORT_H_INCLUDED
#define TRANSPORT_H_INCLUDED

#include <iostream>
using namespace std;
class Transport
{
protected:
    int number;
    float szt;
public:
    Transport()
    {
        number=0;
        szt=0.0;
    }
    Transport(int a,float b)
    {
        number=a;
        szt=b;
    }
    void input()
    {
        cout<<"\tEnter how many furniture: ";
        cin>>number;
        cout<<"\tEnter furniture size: ";
        cin>>szt;
    }
    void output()
    {
        cout<<"\tNumber of Furnitures & total size is: "<<number<<"  "<<szt<<endl;
        if(number<=5 && szt<=100.00)

            cout<<"\tPrice is: "<<450<<endl;

        else if((number>5 && number<=10) && (szt>100.00 && szt<=200.00))
            cout<<"\tPrice is: "<<1000<<endl;
        else
            cout<<"\tPrice is: "<<2000<<endl;
    }
};

#endif // TRANSPORT_H_INCLUDED
