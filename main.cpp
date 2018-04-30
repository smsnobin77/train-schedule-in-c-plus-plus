#include <iostream>
#include <fstream>
#include <string.h>
#include "admin.h"
#include "user.h"
#include "detail.h"
#include "Passenger.h"
#include "Transport.h"
#include "Traintime.h"
#include "base.h"
#include "chipas.h"
#include "chitran.h"
#include "date.h"
using namespace std;

int main()
{
  admin a1="123456";
    admin a2;
    int choose1,choose2,choose6;
    char g1,gp,cf,ch,ch1,ct;
    chipas cn;
    chitran ctr;
    date d1,d2;
    user u1,u2;
    detail d3,dshow,dmatch;
    ifstream ifile;
    ifstream chifile;
    ifstream chitfile;

    cout<<"\n        WELCOME TO TRAIN SCHEDULE OF KAMLAPUR RAILWAY STATION\n\n";
    cout<<"                          Main Menu                 \n\n";
    cout<<"\t1.Admin-mode\n";
    cout<<"\t2.User-mode\n";
    cout<<"\t3.Exit\n";
    do
    {
        cout<<"\nEnter your choice: ";
        cin>>choose1;
        if(choose1==1)
        {
            cout<<"\n";
            a2.getid();
            a2.displayid();
            if(a1==a2)
            {
                cout<<"\nLogged in\n\n";
                cout<<"        ADMINISTRATOR MENU\n\n";
                cout<<"\t1.Add details\n";
                cout<<"\t2.Display details\n";
                cout<<"\t3.Passenger details\n";
                cout<<"\t4.Exit\n";
                do
                {
                    cout<<"\n\tAdmin choice: ";
                    cin>>choose6;
                    switch(choose6)
                    {
                    case 1:
                    {
                        cout<<"\n\tAdd details to which category?\n";
                        cout<<"\tp for Passenger and m for Mail train: ";
                        cin>>cf;
                        if(cf=='p')
                        {
                            cout<<"\n\tEnter data for Passenger train\n\n";

                            do
                            {
                                cn.input();
                                cn.diskout();
                                cout<<"\n\tDo another (y/n)?: ";
                                cin>>ch;
                            }
                            while(ch=='y');
                        }
                        else
                        {
                            cout<<"\n\tEnter data for Mail train\n\n";
                            do
                            {
                                ctr.input();
                                ctr.disktout();
                                cout<<"\n\tDo another (y/n)?: ";
                                cin>>ch1;
                            }
                            while(ch1=='y');
                        }
                        break;
                    }
                    case 2:
                    {
                        cout<<"\n\tDisplay details of which category?\n";
                        cout<<"\tp for Passenger and m for Mail train: ";
                        cin>>cf;
                        if(cf=='p')
                        {
                            int k = chipas::diskcount();
                            if(k==0)
                            {
                                cout<<"\n\tThere is no passenger train left!\n";
                            }
                            else
                            {
                                cout<<"\n\tThere are "<<k<<" passenger train in the file\n";
                            for(int j=0; j<k; j++)
                            {
                                cout<<"\n\tPassenger train "<<j+1<<endl;
                                cn.diskin(j);
                                cn.output();
                            }
                            }
                        }
                        else
                        {
                            int l=chitran::disktcount();
                            if(l==0)
                            {
                                cout<<"\n\tThere is no mail train left!\n";
                            }
                            else
                            {
                            cout<<"\n\tThere are "<<l<<" Mail train in the file\n";
                            for(int i=0; i<l; i++)
                            {
                                cout<<"\n\tMail train "<<i+1<<endl;
                                ctr.disktin(i);
                                ctr.output();
                            }
                            }
                        }
                        break;
                    }
                    case 3:

                    {
                        int choose7,h;
                        cout<<"\n\tOPTIONS\n\n";
                        cout<<"\t1.Display Id\n";
                        cout<<"\t2.Search for User\n";
                        cout<<"\t3.Exit\n";
                        do
                        {
                            cout<<"\n\tEnter Option: ";
                            cin>>choose7;

                            if(choose7==1)
                            {
                               // ifstream ifile;
                                ifile.open("f.txt",ios::in|ios::out|ios::binary);
                                ifile.seekg(0,ios::end);
                                int endp = ifile.tellg();
                                h = endp/sizeof(detail);
                                if(h==0)
                                {
                                    cout<<"\n\tThere is no user left\n";
                                }
                                else
                                {
                                    cout<<"\n\tThere are "<<h<<" Users in file\n";
                                for(int j=0; j<h; j++)
                                {
                                      cout<<endl<<"\tUser accounts: "<<j+1<<endl;
                                      dshow.ind(j);
                                      dshow.displaydata();

                                }
                                }
                                ifile.close();
                            }
                            else if(choose7==2)
                            {
                                //ifstream ifile;
                                ifile.open("f.txt",ios::in|ios::out|ios::binary);
                                cout<<"\n\tEnter User number: ";
                                cin>>h;
                                if(h==0)
                                {
                                    cout<<"\n\tYou pressed wrong number\n";
                                }
                                else
                                {
                                int pos;
                                pos=(h-1)*sizeof(detail);
                                ifile.seekg(pos);
                                ifile.read(reinterpret_cast<char*>(&dshow),sizeof(dshow));
                                cout<<endl;
                                dshow.displaydata();
                                ifile.close();
                                }
                            }
                            cout<<"\n\tWhat to do?";
                        }
                        while(choose7<3);
                        if(choose7==3)
                        {
                            cout<<"\n\tExit from this section\n";
                        }
                    }
                    break;
                    }
                    if(choose6<4)
                    {
                        cout<<"\n\tVisit more?: ";
                    cin>>gp;
                    }
                    else if(choose6==4)
                    {
                        cout<<"\n\tExit from ADMIN MODE\n\n";
                    }

                }
                while(gp=='y' && choose6<4);
            }
            else
            {
                cout<<"\n\tOOPS!!! "<<"Wrong password!!!\n\n";
            }
        }
        else if(choose1==2)
        {
                cout<<"\n\n        USER MODE         \n\n";
                cout<<"\t1.Login with user id\n";
                cout<<"\t2.Create new id\n";
                cout<<"\t3.Exit\n";
            do
            {
                cout<<"\nEnter choice: ";
                cin>>choose2;
                bool flag=false;
                if(choose2==1)
                {
                    ifstream ifile;
                    ifile.open("f.txt",ios::in|ios::out|ios::binary);
                    ifile.seekg(0,ios::end);
                    int endp = ifile.tellg();
                    int h = endp/sizeof(detail);
                    cout<<endl;
                    u2.getdata();
                    for(int j=0; j<h; j++)
                    {
                        dmatch.ind(j);
                        //        umatch.displaydata();
                        if(dmatch==u2)
                        {
                            cout<<"\nLogged in\n";
                            flag = true;
                            break;
                        }
                        else
                        {
                            flag = false;
                        }
                    }
                    if(flag==true)
                    {
                        int n,p;
                        int choose3,choose4,chois;
                        char cc;
                        char g3,g4,g5;
                        cout<<"\n\t1.Visit\n";
                        cout<<"\t2.Return\n";
                        cout<<"\n\tMake choice: ";
                        cin>>chois;
                        if(chois==1)
                        {
                            do
                            {
                                cout<<"\n\tEnter train category: ";
                                cin>>cc;
                                if(cc=='p')
                                {
                                    int count1=0;
                                    int ans1=0;
                                    cout<<"\n\t1.Show detail train schedule\n";
                                    cout<<"\t2.Reservation\n";
                                    cout<<"\t3.Cancellation\n";
                                    do
                                    {
                                        cout<<"\n\tEnter User choice: ";
                                        cin>>choose3;
                                        switch(choose3)
                                        {
                                        case 1:
                                        {
                                            int k = chipas::diskcount();
                                            if(k==0)
                                            {
                                                cout<<"\n\tThere is no passenger train left!\n";
                                            }
                                            else
                                            {
                                                cout<<"\n\tThere are "<<k<<" passenger train in the file\n";
                                            for(int j=0; j<k; j++)
                                            {
                                                cout<<"\n\tPassenger train "<<j+1<<endl;
                                                cn.diskin(j);
                                                cn.output();
                                            }
                                            }
                                            break;
                                        }
                                        case 2:
                                        {
                                            d1.input();
                                           // ifstream chifile;
                                            chifile.open("chi.txt",ios::in|ios::out|ios::binary);
                                            chifile.seekg(0,ios::end);
                                            int endn=chifile.tellg();
                                            n=endn/sizeof(chipas);
                                            cout<<"Enter which number: ";
                                            cin>>n;
                                            if(n==0)
                                            {
                                                cout<<"\n\tYou pressed wrong number\n";
                                            }
                                            else
                                            {
                                                int nos=(n-1)*sizeof(chipas);
                                            chifile.seekg(nos);
                                            chifile.read(reinterpret_cast<char*>(&cn),sizeof(cn));
                                            cout<<"\n\nTicket bought\n";
                                            cn.output();
                                            d1.output();
                                            count1++;
                                            cout<<endl<<count1<<" Ticket bought and money paid\n";
                                            }
                                            chifile.close();
                                        }
                                        break;
                                        case 3:
                                        {
                                                if(count1==0)

                                                   {
                                                    cout<<"\nNo ticket left\n";
                                                    break;
                                                   }

                                                else
                                                {
                                                    count1--;
                                                   ++ans1;
                                                    cout<<endl<<ans1<<" Ticket canceled and money returned\n";
                                                }

                                            break;
                                        }
                                        }
                                        cout<<"\n\tDo you want more? (y/n): ";
                                        cin>>g3;
                                    }
                                    while(g3=='y');
                                }
                                else
                                {
                                    int count2=0;
                                    int ans2=0;
                                    cout<<"\n\t1.Show detail train schedule\n";
                                    cout<<"\t2.Reservation\n";
                                    cout<<"\t3.Cancellation\n";
                                    do
                                    {
                                        cout<<"\n\tEnter User choice: ";
                                        cin>>choose4;
                                        switch(choose4)
                                        {
                                        case 1:
                                        {
                                            int l=chitran::disktcount();
                                            if(l==0)
                                            {
                                                cout<<"\n\tThere is no mail train left\n";
                                            }
                                            else
                                            {
                                                cout<<"\n\tThere are "<<l<<" Mail train in the file\n";
                                            for(int i=0; i<l; i++)
                                            {
                                                cout<<"\n\tMail train "<<i+1<<endl;
                                                ctr.disktin(i);
                                                ctr.output();
                                            }
                                            }
                                            break;
                                        }
                                        case 2:
                                        {
                                            d2.input();
                                            //ifstream chitfile;
                                            chitfile.open("chit.txt",ios::in|ios::out|ios::binary);
                                            chitfile.seekg(0,ios::end);
                                            int endp=chitfile.tellg();
                                            p=endp/sizeof(chitran);
                                            cout<<"Enter which number: ";
                                            cin>>p;
                                            if(p==0)
                                            {
                                                cout<<"\n\tYou pressed wrong number\n";
                                            }
                                            else
                                            {
                                            int pos=(p-1)*sizeof(chitran);
                                            chitfile.seekg(pos);
                                            chitfile.read(reinterpret_cast<char*>(&ctr),sizeof(ctr));
                                            cout<<"\n\nTicket bought\n";
                                            ctr.output();
                                            d2.output();
                                            count2++;
                                            cout<<endl<<count2<<" Ticket bought and money paid\n";
                                            }
                                            chitfile.close();
                                        }
                                        break;
                                        case 3:
                                        {
                                             if(count2==0)

                                                   {
                                                    cout<<"\nNo ticket left\n";
                                                    break;
                                                   }

                                                else
                                                {
                                                    count2--;
                                                   ++ans2;
                                                    cout<<endl<<ans2<<" Ticket canceled and money returned\n";
                                                }

                                            break;
                                        }
                                        }
                                        cout<<"\n\tDo you want more? (y/n): ";
                                        cin>>g4;
                                    }
                                    while(g4=='y');
                                }
                                cout<<"\n\tNeed more?: ";
                                cin>>g5;
                            }
                            while(g5=='y');
                        }
                    }
                   if(!flag)
                    {
                        cout<<"\n\tSORRY!!!..."<<"You are not a User!!!\n";
                    }
                    ifile.close();
                }
                else if(choose2==2)
                {
                    cout<<"\n\tCreate id\n\n";
                    d3.getdata();
                    d3.outd();
                    cout<<"\n\tNow login with your id\n";
                }
                if(choose2<3)
                {
                    cout<<"\n\tBack to USER MODE: ";
                    cin>>ct;
                }
                else if(choose2==3)
                {
                    cout<<"\n\tExit from USER MODE\n\n";
                }
            }
            while(ct=='y' && choose2<3);
        }
        else
        {
            cout<<"\n\tExit\n";
            return 0;
        }
        cout<<"\n\tBack to Main Menu: ";
        cin>>g1;
    }
    while(g1=='y');
    return 0;
}

