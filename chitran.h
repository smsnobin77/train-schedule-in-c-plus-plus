#ifndef CHITRAN_H_INCLUDED
#define CHITRAN_H_INCLUDED

#include <iostream>
#include <fstream>
#include "base.h"
#include "Transport.h"
using namespace std;

class chitran: public base,public Transport
{
    Traintime ct1;
public:
    void input()
    {
        base::getinfo();
        ct1.getdata();
        Transport::input();
    }
    void output()
    {
        base::displayinfo();
        ct1.displaydata(ct1);
        ct1.duration(ct1);
        Transport::output();
    }
    void disktin(int ct)
    {
        ifstream chitfile;
        chitfile.open("chit.txt",ios::in|ios::out|ios::binary);
        chitfile.seekg(ct*sizeof(chitran));
        chitfile.read((char*)this,sizeof(*this));
    }
    void disktout()
    {
        ofstream outctfile;
        outctfile.open("chit.txt",ios::app | ios::binary);
        outctfile.write((char*)this,sizeof(*this));
    }
    static int disktcount()
    {
        ifstream chitfile;
        chitfile.open("chit.txt",ios::in|ios::out|ios::binary);
        chitfile.seekg(0, ios::end);
        return (int)chitfile.tellg() / sizeof(chitran);
    }

};

#endif // CHITRAN_H_INCLUDED
