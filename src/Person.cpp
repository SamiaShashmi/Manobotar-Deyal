#include "Person.h"
#include<bits/stdc++.h>
#include"Doner.h"
using namespace std;

Person::Person()
{
    //ctor
}

void Person::display()
    {
        cout<<"Name : "<<getName()<<endl;
        cout<<"Age : "<<getAge()<<endl;
        cout<<"Email : "<<getEmail()<<endl;
    }

void Person::signIn()
{
    system("cls");
    cout<<"Enter name : " ;
     cin.ignore();
    getline(cin,name);
    setName(name);
    cout<<"Enter age : " ;
    cin>>age;
    setAge(age);
    cout<<"Enter email : " ;
    cin>>email;
    setEmail(email);
    cout<<"Enter password : " ;
    cin>>password;
    setPassword(password);
    string passwordConfirmation;
    cout<<"Confirm password : ";
    cin>>passwordConfirmation;
    if(passwordConfirmation!=getPassword())
    {
        cout<<"Doesn't match";
       Menu();
    }
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
void Person::Show()
{
    cout<<"Name: "<<getName()<<"\nAge: "<<getAge()<<"\nEmail: "<<getEmail()<<endl;
}
void Person::submenu()
{

}
