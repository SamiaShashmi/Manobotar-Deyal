#include "Person.h"
#include<bits/stdc++.h>
#include <conio.h>
#include "windows.h"
#include"Donor.h"
#include "Donee.h"
#include"Product.h"
#include"Money.h"
#include "Donee.h"
#include"Blood.h"
#include"Cloth.h"
using namespace std;
void startMenu();
void gotoxy(int x,int y);
Person::Person()
{
    //ctor
    password="";
}


void Person::signIn()
{
    string Name;
    int Age;
    string Email;
    string pass;
    system("cls");
    cout<<"Enter name : " ;
     cin.ignore();
    getline(cin,Name);
    setName(Name);
    cout<<"Enter age : " ;
    cin>>Age;
    setAge(Age);
    cout<<"Enter email : " ;
    cin>>Email;
    setEmail(Email);
    cout<<"Enter password : " ;
    char ch;
   ch = _getch(); //* will be shown without character
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   cout<<endl;
    setPassword(pass);
}


void Person::Menu()
{
    system("cls");
     cout<<"\n\n1. Sign in :"<<endl;
       cout<<"2. Log in :"<<endl;
       int signOrLogInchoice;
        cin>>signOrLogInchoice;
    if(signOrLogInchoice==1)
    {
        signIn();
    }
    else if(signOrLogInchoice==2)
    {
        logIn();
    }
}
void Person::displayProfile()
{
    cout<<"Name: "<<getName()<<"\nAge: "<<getAge()<<"\nEmail: "<<getEmail()<<endl;
}
void Person::submenu()
{

}
void Person::productMenu()
{
    system("cls");
    cout<<"Choose category :\n";
    cout<<"a.Money\nb.Cloth\nc.Book\nd.Blood\ne.Mental Counseling\n";
}
int Person::matchPassword(long int id,string pass)
{

}
void Person::logIn()
{

}

