#include <bits/stdc++.h>
#include<conio.h>
#include"Person.h"
#include"Donor.h"
#include"Donee.h"
#include<iostream>
#include<thread>
#include<chrono>
#include<windows.h>

using namespace std;


using std::this_thread::sleep_for;
using std::chrono::milliseconds;

void print(const string&,unsigned int);

void print(const string& messege, unsigned int mil)

{
    for(const char c:messege)
    {
        cout<< c << flush;
        sleep_for(milliseconds(mil));
    }
}

void gotoxy(int x,int y)
{
COORD c;
c.X =x;
c.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE) , c);
}

void startMenu()
{
    vector<Person *>person;
    char donorOrDoneeChoice;
   int personCount=0;
   system("color b");
   system("cls");
   gotoxy(60,10);
   cout<<"  Welcome to MANOBOTAR DEYAL  "<<endl;
   gotoxy(65,15);
   cout<<"Enter as :"<<endl;
   gotoxy(66,17);
   cout<<"a.Donor"<<endl;
   gotoxy(66,18);
   cout<<"b.Donee"<<endl;
   gotoxy(65,22);
   cout<<"Enter your choice :";
   cin>>donorOrDoneeChoice;
   if(donorOrDoneeChoice=='a')
   {
       person.push_back(new Donor);
       person[personCount]->Menu();
       personCount++;
   }
   else
   {
       person.push_back(new Donee);
       person[personCount]->Menu();
       personCount++;
   }
}

int main()
{

     string messege = " We cannot despair of humanity, since we ourselves are human beings. Albert Einstein.  ...";
     system("color F0");
     gotoxy(40,10);
    print(messege,140);
    //Person person;
    char c;

    while(true)
    {
        startMenu();
        c=getch();
        if (c==27)
          break;

    }

}



