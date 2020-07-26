#include "Doner.h"
#include "Person.h"
#include<bits/stdc++.h>
#include<iostream>
#include"Functions.h"

using namespace std;

long int Doner::stDonerID=12000;




Doner::Doner()/*:DonerID(++stDonerID)*/
{
   /* stDonerID=stDonerID+1;
    DonerID=stDonerID;*/
    /*DonerID=12000+stDonerID;
    stDonerID++;*/
    //ctor
}
 void Doner::Menu()
 {
     Person::Menu();
    //DonerView();
 }

void Doner::signIn()
{

    //stDonerID=stDonerID+1;
    //aDonerID=stDonerID;
     Person::signIn();
     submenu();
    //Doner_StoreInFile();
}

void Doner::submenu()
 {
    // system("cls");
     cout<<"What do you want?"<<endl;
     cout<<"a.View Profile"<<endl<<"b.View Doner List"<<endl<<"c.Upload Product"<<endl<<"d.Edit Product"<<endl<<"e.Delete Product"<<endl<<"f.Log Out"<<endl;
     cout<<"Enter your choice : ";
     char donerchoice;
     cin>>donerchoice;
     if(donerchoice=='a')
     {
        Show();
        submenu();
     }
     else if(donerchoice=='b')
     {
       //  Doner_DisplayAll();
         submenu();
     }
     else if(donerchoice=='c')
     {

     }
     else if(donerchoice=='f')
     {

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

void Doner::Show()
{
    system("cls");
    Person::Show();}
    //cout<<"\n\nID : "<<DonerID<<"\n
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
