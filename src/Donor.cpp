#include "Donor.h"
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

int productCount = -1;
extern unordered_map<int,long int>id_count;
long int Donor::stDonorID=12000;

void startMenu();
void frame(int n);
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
     cout<<"\n\nAccount successfully created..\nYour ID is "<< ID << endl << endl;
     submenu();
}

void Donor::submenu()
 {
    // system("cls");
     cout<<"\nWhat do you want?"<<endl;
     cout<<"a.View Profile"<<endl<<"b.View Donor List"<<endl<<"c.Upload Product"<<endl<<"d.Log Out"<<endl;
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
     else if(donorchoice=='d')
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
void Donor::storeInFile()
{
        ofstream fout;
        fout.open("Donor.txt", std::ios::out | std::ios::app);
        fout << setw(5) << donorID << setw(35) << name << setw(7) << age << setw(35) << email<<endl;
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
    string em;
    fin.open("Donor.txt",ios::in|ios::app);
    frame(82);
    cout << setw(5) << "ID" << setw(35) << "Name" << setw(7) << "Age" << setw(35) << "Email" <<endl;
    frame(82);
    while (getline(fin,em)) {
cout << em << endl ;
}
    fin.close();
}

void Donor::uploadProduct()
{
    Person::productMenu();
    vector<Product*>product;
    char productChoice;
    cin>>productChoice;
    if(productChoice=='a')
    {
        product.push_back(new Money);
        productCount++;
        product[productCount]->uploadProduct(getDonorID(),getName());
    }
    else if(productChoice=='b')
    {
        product.push_back(new Cloth);
        productCount++;
        product[productCount]->uploadProduct(getDonorID(),getName());
    }
    else if(productChoice=='c')
    {
        product.push_back(new Book);
        productCount++;
        product[productCount]->uploadProduct(getDonorID(),getName());
    }
    else if(productChoice=='d')
    {
        product.push_back(new Blood);
        productCount++;
        product[productCount]->uploadProduct(getDonorID(),getName());
    }
    else if(productChoice=='d')
    {
        product.push_back(new Blood);
        productCount++;
        product[productCount]->uploadProduct(getDonorID(),getName());
    }
    else if(productChoice=='e')
    {
        product.push_back(new MentalCounselling);
        productCount++;
        product[productCount]->uploadProduct(getDonorID(),getName());
    }
}
