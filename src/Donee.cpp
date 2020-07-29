#include "Donee.h"
#include "Person.h"
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

long int Donee:: stDoneeID = 14000;

void startMenu();

Donee::Donee()
{

}

void Donee::Menu()
{
    Person::Menu();
    //DoneeView();
}

void Donee::signIn()
{
     long int ID;
     Person::signIn();
     ID=++stDoneeID;
     setDoneeID(ID);
     submenu();
    //Donee_StoreInFile();
}

void Donee::submenu()
 {
    // system("cls");
     cout<<"What do you want?"<<endl;
     cout<<"a.View Profile"<<endl<<"b.View Donee List"<<endl<<"c.Display Product"<<endl<<"d.Place Order"<<endl<<"e.Log Out"<<endl;
     cout<<"Enter your choice : ";
     char doneechoice;
     cin>>doneechoice;
     if(doneechoice=='a')
     {
        displayProfile();
        submenu();
     }
     else if(doneechoice=='b')
     {
       //  Doner_DisplayAll();
         submenu();
     }
     else if(doneechoice=='c')
     {
        productMenu();
     }
     else if(doneechoice=='d')
     {

     }
     else if(doneechoice=='e')
     {
        startMenu();
     }
 }

/*void Donee::Donee_StoreInFile()
{
    ofstream file_donee;
    file_donee.open("Donee.txt", ios::app | ios::binary);
    file_donee.write((char*)this, sizeof(*this));
    file_donee.close();
    cout<<"Account created";
}*/

void Donee::displayProfile()
{
    system("cls");
    cout<<"ID : "<<getDoneeID()<<endl;
    Person::displayProfile();}
    //cout<<"\n\nID : "<<DoneeID<<"\n
/*void Donee::Donee_DisplayAll()
{*/
    /*ifstream file_donee;
    file_donee.open("Donee.txt",ios::in | ios:: binary);
    if(!file_donee)
    {
        cout<<"No Donee"<<endl;
    }
    else
    {
        file_donee.read((char*)this, sizeof(*this));
        while(!file_donee.eof())
        {
            Donee_Show();
            file_donee.read((char*)this, sizeof(*this));
        }
        file_donee.close();
    }*/

    /*cout<<stDonerID-14001;
}*/

void Donee::productMenu()
{
    Person::productMenu();
}
