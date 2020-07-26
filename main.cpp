#include <bits/stdc++.h>
#include<conio.h>
#include"Person.h"
#include"Doner.h"
#include"Functions.h"
using namespace std;
void startMenu()
{
    Person *person[10000];
    char donerOrDoneeChoice;
   int personCount=0;
   system("color b");
   system("cls");
   cout<<"\t\t\t\t\t***  Welcome to MANOBOTAR DEYAL  ***"<<endl;
   cout<<"\n\nEnter as :"<<endl;
   cout<<"a. Doner"<<endl;
   cout<<"b.Donee"<<endl;
   cout<<"Enter your choice :";
   cin>>donerOrDoneeChoice;
   if(donerOrDoneeChoice=='a')
   {
       person[personCount]=new Doner;
       person[personCount]->Menu();
   }
}

int main()
{
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



