#include "Person.h"
#include<bits/stdc++.h>
#include <conio.h>
#include "windows.h"
#include"Doner.h"
using namespace std;
void startMenu();
Person::Person()
{
    //ctor
    password="";
}

void Person::display()
    {
        cout<<"Name : "<<getName()<<endl;
        cout<<"Age : "<<getAge()<<endl;
        cout<<"Email : "<<getEmail()<<endl;
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
    cout<<"Choose category :";
    char productChoice;
    if(productChoice=='a')
    {

    }
}
