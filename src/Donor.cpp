#include "Donor.h"
#include "Person.h"
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

long int Donor::stDonorID=12000;

void startMenu();

Donor::Donor()
{

}
 void Donor::Menu()
 {
     Person::Menu();
 }

void Donor::signIn()
{
    long int ID;
     Person::signIn();
     ID=++stDonorID;
     setDonorID(ID);
     submenu();
    //Donor_StoreInFile();
}

void Donor::submenu()
 {
    // system("cls");
     cout<<"What do you want?"<<endl;
     cout<<"a.View Profile"<<endl<<"b.View Donor List"<<endl<<"c.Upload Product"<<endl<<"d.Edit Product"<<endl<<"e.Delete Product"<<endl<<"f.Log Out"<<endl;
     cout<<"Enter your choice : ";
     char donorchoice;
     cin>>donorchoice;
     if(donorchoice=='a')
     {
        displayProfile();
        submenu();
     }
     else if(donorchoice=='b')
     {

         submenu();
     }
     else if(donorchoice=='c')
     {
        productMenu();
     }
     else if(donorchoice=='f')
     {
            startMenu();
     }
 }
/*void Donor::Donor_StoreInFile()
{
    ofstream file_donor;
    file_donor.open("Donor.txt", ios::app | ios::binary);
    file_donor.write((char*)this, sizeof(*this));
    file_donor.close();
    cout<<"Account created";
}*/

void Donor::displayProfile()
{
    system("cls");
    cout<<"ID : "<<getDonorID()<<endl;
    Person::displayProfile();}


void Donor::productMenu()
{
    Person::productMenu();
}
