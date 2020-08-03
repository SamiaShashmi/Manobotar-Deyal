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
     ofstream fout;
    fout.open("donorCount.txt");
        fout << ID << endl;
    fout.close();
     storeInFile();
     submenu();
}

void Donor::logIn()
{
    int id;
    char ch;
    string pass;
    cout<<"Enter ID : ";
    cin>>id;
    //fflush(stdin);
    cout<<"Enter password : ";
    ch = _getch(); //* will be shown without character
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   cout<<endl;
   int ifMatch = matchPassword(id,pass);
   if(ifMatch==0)
   {
       cout<<"Wrong password!!"<<endl;
       logIn();
   }
   else
   {
       submenu();
   }
   fflush(stdin);
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
int Donor::matchPassword(long int id,string pass)
    {
        ifstream f;
        int ifMatch=0;
        f.open("Donor.dat",ios::in|ios::binary);
        f.read((char*)this,sizeof(*this));
        while(!f.eof())
        {
            if(donorID==id)
            {
                if(getPassword()==pass)
                {
                    ifMatch=1;
                }
            }
            f.read((char*)this,sizeof(*this));
        }
        f.close();
        return ifMatch;
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
