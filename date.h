#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>
using namespace std;
class date
{
private:
    int day,month,year;
    char r;
public:
    void input()
    {
        cout<<"\nEnter date: ";
        cin>>day>>r>>month>>r>>year;
    }
    void output()
    {
        cout<<"\nDate for reservation: ";
        cout<<day<<"/"<<month<<"/"<<year<<endl;
    }
};

#endif // DATE_H_INCLUDED
