#include "Doner.h"
#include "Person.h"
#include<bits/stdc++.h>
#include<iostream>
#include"Functions.h"

using namespace std;

long int Doner::stDonerID=12000;

void startMenu()
{
    Doner doner[100000];
    char donerOrDoneeChoice;
   int donerCount=0;
   system("color b");
   cout<<"\t\t\t\t\t***  Welcome to MANOBOTAR DEYAL  ***"<<endl;
   cout<<"\n\nEnter as :"<<endl;
   cout<<"a. Doner"<<endl;
   cout<<"b.Donee"<<endl;
   cout<<"Enter your choice :";
   cin>>donerOrDoneeChoice;
   if(donerOrDoneeChoice=='a')
   {
       doner[donerCount].DonerMenu();
   }
}



Doner::Doner()/*:DonerID(++stDonerID)*/
{
   /* stDonerID=stDonerID+1;
    DonerID=stDonerID;*/
    /*DonerID=12000+stDonerID;
    stDonerID++;*/
    //ctor
}
 void Doner::DonerMenu()
 {
     system("cls");
     cout<<"\n\n1. Sign in :"<<endl;
       cout<<"2. Log in :"<<endl;
       int signOrLogInchoice;
        cin>>signOrLogInchoice;
    if(signOrLogInchoice==1)
    {
        Doner_Signin();
    }
    DonerView();
 }

void Doner::Doner_Signin()
{
    system("cls");
    stDonerID=stDonerID+1;
    DonerID=stDonerID;
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
        DonerMenu();
    }
    else
    {
        cout<<"Account created\n";
    }

    //Doner_StoreInFile();
}

void Doner::DonerView()
 {
    // system("cls");
     cout<<"What do you want?"<<endl;
     cout<<"a.View Profile"<<endl<<"b.View Doner List"<<endl<<"c.Upload Product"<<endl<<"d.Edit Product"<<endl<<"e.Delete Product"<<endl<<"f.Exit"<<endl;
     cout<<"Enter your choice : ";
     char donerchoice;
     cin>>donerchoice;
     if(donerchoice=='a')
     {
        Doner_Show();
        DonerView();
     }
     else if(donerchoice=='b')
     {
       //  Doner_DisplayAll();
         DonerView();
     }
     else if(donerchoice=='c')
     {

     }
     else if(donerchoice=='f')
     {
        startMenu();
     }
 }
/*void Doner::Doner_StoreInFile()
{
    ofstream file_doner;
    file_doner.open("Doner.txt", ios::app | ios::binary);
    file_doner.write((char*)this, sizeof(*this));
    file_doner.close();
    cout<<"Account created";
}*/

void Doner::Doner_Show()
{
    system("cls");
    cout<<"\n\nID : "<<DonerID<<"\nName: "<<getName()<<"\nAge: "<<getAge()<<"\nEmail: "<<getEmail()<<endl;
}
/*void Doner::Doner_DisplayAll()
{*/
    /*ifstream file_doner;
    file_doner.open("Doner.txt",ios::in | ios:: binary);
    if(!file_doner)
    {
        cout<<"No Doner"<<endl;
    }
    else
    {
        file_doner.read((char*)this, sizeof(*this));
        while(!file_doner.eof())
        {
            Doner_Show();
            file_doner.read((char*)this, sizeof(*this));
        }
        file_doner.close();
    }*/

    /*cout<<stDonerID-12001;
}*/


void Doner::Doner_ProfileDisplay()
{

}
