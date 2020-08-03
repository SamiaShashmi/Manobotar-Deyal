#include "Donee.h"
#include "Person.h"
#include"Product.h"
#include"Money.h"
#include"Blood.h"
#include"Cloth.h"
#include"Book.h"
#include"MentalHealth.h"
#include<bits/stdc++.h>
#include<iostream>

using namespace std;

long int Donee:: stDoneeID = 14000;

void startMenu();

using namespace std;


void startMenu();

Donee::Donee()
{

}

void Donee::Menu()
{
    Person::Menu();
}

void Donee::signIn()
{
     long int ID;
     Person::signIn();
      ifstream fin;
    fin.open("doneeCount.txt");
    if(!fin)
    {
        stDoneeID=14000;
    }
    else{
        while (fin) {
        fin>>stDoneeID;
    }
    }

    fin.close();
     ID=++stDoneeID;
     setDoneeID(ID);
     ofstream fout;
    fout.open("doneeCount.txt");
        fout << ID << endl;
    fout.close();
     //storeInFile();
     submenu();
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
         submenu();
     }
     else if(doneechoice=='c')
     {

     }
     else if(doneechoice=='d')
     {
        placeOrder();
        submenu();
     }
     else if(doneechoice=='e')
     {
        startMenu();
     }
 }

void Donee::displayProfile()
{
    //system("cls");
    cout<<"ID : "<<getDoneeID()<<endl;
    Person::displayProfile();
}

void Donee::placeOrder()
{
    Person::productMenu();
    vector<Product*>product2;
    int productCount=0;
    char productChoice;
    cin>>productChoice;
    if(productChoice=='a')
    {
        product2.push_back(new Money);
        product2[productCount]->placeOrder();
    }
    else if(productChoice=='b')
    {
        product2.push_back(new Cloth);
        product2[productCount]->placeOrder();
    }
    else if(productChoice=='c')
    {

    }
    else if(productChoice=='d')
    {
         product2.push_back(new Blood);
        product2[productCount]->placeOrder();
    }
}


