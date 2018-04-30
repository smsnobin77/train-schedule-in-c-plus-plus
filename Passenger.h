#ifndef PASSENGER_H_INCLUDED
#define PASSENGER_H_INCLUDED
#include <iostream>
using namespace std;

enum compart {A,B};
class Passenger
{
protected:
    compart ch;
public:
    void input()
    {
        char c;
        cout<<"\tEnter compartment: ";
        cin>>c;
        ch=(c=='A')? A : B;
    }
    void output()
    {
        cout<<((ch==A)? "\tFirst Class Compartment" : "\tSecond Class Compartment");
        if(ch==A)
            cout<<"\n\tPrice is: "<<295<<endl;
        else
            cout<<"\n\tPrice is: "<<180<<endl;
    }

};

#endif // PASSENGER_H_INCLUDED
