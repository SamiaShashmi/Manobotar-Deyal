#include "Donor.h"
#include "Person.h"
#include"Product.h"
#include"Money.h"
#include"Blood.h"
#include"Cloth.h"
#include"Book.h"
#include"MentalCounselling.h"
#include<bits/stdc++.h>
#include<iostream>
#include <conio.h>
using namespace std;
extern unordered_map<int,long int>id_count;
long int Donor::stDonorID=12000;

void startMenu();

Donor::Donor()
{

}


void Donor::signUp(int personCount)
{
    long int ID;
     Person::signUp(personCount);
     ifstream fin;
    fin.open("donorCount.txt");
    if(!fin)
    {
        stDonorID=12000;
    }
    else{
        while (fin) {
        fin>>stDonorID;
    }
    }

    fin.close();
     ID=++stDonorID;
     setDonorID(ID);
     id_count[personCount]=ID;
     ofstream fout;
    fout.open("donorCount.txt");
        fout << ID << endl;
    fout.close();
    ofstream fmut;
    fmut.open("id_count.txt", std::ios::out | std::ios::app);
    fmut << ID << " "<< personCount<< endl;
    fmut.close();
    ofstream fnut;
    fnut.open("donorPassword.txt", std::ios::out | std::ios::app);
    fnut << ID << " "<< getPassword()<< endl;
    fnut.close();
     storeInFile();
     submenu();
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
         viewDonorList();
         submenu();
     }
     else if(donorchoice=='c')
     {
        uploadProduct();
        submenu();
     }
     else if(donorchoice=='f')
     {
            startMenu();
     }
 }
void Donor::storeInFile()
{
        ofstream fout;
        fout.open("Donor.dat", ios::app|ios::binary);
        fout.write((char*)this,sizeof(*this));
        fout.close();
}

void Donor::displayProfile()
{
    //system("cls");
    cout<<"ID : "<<getDonorID()<<endl;
    this->Person::displayProfile();
}

void Donor::viewDonorList()
{
    ifstream fin;
    fin.open("Donor.dat",ios::in|ios::binary);
    fin.read((char*)this,sizeof(*this));
    while(!fin.eof()){
            displayProfile();
        fin.read((char*)this,sizeof(*this));
    }
    fin.close();
}

void Donor::uploadProduct()
{
    Person::productMenu();
    vector<Product*>product;
    int productCount=0;
    char productChoice;
    cin>>productChoice;
    if(productChoice=='a')
    {
        product.push_back(new Money);
        product[productCount]->uploadProduct();
    }
    else if(productChoice=='b')
    {
        product.push_back(new Cloth);
        product[productCount]->uploadProduct();
    }
    else if(productChoice=='d')
    {
        product.push_back(new Blood);
        product[productCount]->uploadProduct();
    }
    else if(productChoice=='d')
    {
        product.push_back(new Blood);
        product[productCount]->uploadProduct();
    }
    else if(productChoice=='e')
    {
        product.push_back(new MentalCounselling);
        product[productCount]->uploadProduct();
    }
}
