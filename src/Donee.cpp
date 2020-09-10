#include "Donee.h"
#include "Person.h"
#include"Product.h"
#include"Money.h"
#include"Blood.h"
#include"Cloth.h"
#include"Book.h"
#include"MentalCounselling.h"
#include<bits/stdc++.h>
#include<windows.h>
#include<chrono>
#include<thread>

using namespace std;
using std::chrono::seconds;
using std::this_thread::sleep_for;

extern unordered_map<int,long int>id_count;
long int Donee:: stDoneeID = 14000;

void startMenu();
void frame();
using namespace std;


void startMenu();

Donee::Donee()
{

}


void Donee::signUp(int personCount)
{
     long int ID;
     Person::signUp(personCount);
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
     id_count[personCount]=ID;
     ofstream fout;
    fout.open("doneeCount.txt");
        fout << ID << endl;
    fout.close();
    ofstream fmut;
    fmut.open("id_count.txt", std::ios::out | std::ios::app);
    fmut << ID << " "<< personCount<< endl;
    fmut.close();
    ofstream fnut;
    fnut.open("doneePassword.txt", std::ios::out | std::ios::app);
    fnut << ID << " "<< getPassword()<< endl;
    fnut.close();
    storeInFile();
    cout<<"\n\nAccount successfully created..\nYour ID is "<< ID << endl << endl;
     submenu();
}

void Donee::submenu()
 {
    // system("cls");
     cout<<"\nWhat do you want?"<<endl;
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
         viewDoneeList();
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
     else
     {
         cout<<"\n\nInvalid Choice!!!";
         sleep_for(seconds(2));
         submenu();
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
    else if(productChoice=='e')
    {
         product2.push_back(new MentalCounselling);
        product2[productCount]->placeOrder();
    }
}

void Donee::storeInFile()
{
        ofstream fout;
        fout.open("Donee.txt", std::ios::out | std::ios::app);
        fout << setw(5) << doneeID << setw(35) << name << setw(7) << age << setw(35) << email<<endl;
        fout.close();
}

void Donee::viewDoneeList()
{
    ifstream fin;
    string em;
    fin.open("Donee.txt",ios::in|ios::app);
    frame();
    cout << setw(5) << "ID" << setw(35) << "Name" << setw(7) << "Age" << setw(35) << "Email" <<endl;
    frame();
    while (getline(fin,em)) {
cout << em << endl ;
}
    fin.close();
}
