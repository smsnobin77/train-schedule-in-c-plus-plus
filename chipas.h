#ifndef CHIPAS_H_INCLUDED
#define CHIPAS_H_INCLUDED

#include <iostream>
#include <fstream>
#include "base.h"
#include "Passenger.h"
using namespace std;

class chipas: public base,public Passenger
{
    Traintime c1;
public:
    void input()
    {
        base::getinfo();
        c1.getdata();
        Passenger::input();
    }
    void output()
    {
        base::displayinfo();
        c1.displaydata(c1);
        c1.duration(c1);
        Passenger::output();
    }
    void diskin(int c)
    {
        ifstream chifile;
        chifile.open("chi.txt", ios::in|ios::out|ios::binary);
        chifile.seekg( c*sizeof(chipas) );
        chifile.read( (char*)this, sizeof(*this) );
    }
    void diskout()
    {
        ofstream outcfile;
        outcfile.open("chi.txt", ios::app | ios::binary);
        outcfile.write( (char*)this, sizeof(*this));
    }
    static int diskcount()
    {
        ifstream chifile;
        chifile.open("chi.txt", ios::in|ios::out|ios::binary);
        chifile.seekg(0, ios::end);
        return (int)chifile.tellg() / sizeof(chipas);
    }
};



#endif // CHIPAS_H_INCLUDED
