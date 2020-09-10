#include "Donee.h"
#include "Person.h"
#include"Product.h"
#include"Money.h"
#include"Blood.h"
#include"Cloth.h"
#include"Book.h"
#include"MentalCounselling.h"
#include<bits/stdc++.h>
#include<iostream>

using namespace std;
extern unordered_map<int,long int>id_count;
long int Donee:: stDoneeID = 14000;

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
        displayProduct();
        submenu();
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

 void Donee::storeInFile()
{
        ofstream fout;
        fout.open("Donee.dat", ios::app|ios::binary);
        fout.write((char*)this,sizeof(*this));
        fout.close();
}

void Donee::displayProfile()
{
    //system("cls");
    cout<<"ID : "<<getDoneeID()<<endl;
    Person::displayProfile();
}

void Donee::viewDoneeList()
{
    ifstream fin;
    fin.open("Donee.dat",ios::in|ios::binary);
    fin.read((char*)this,sizeof(*this));
    while(!fin.eof()){
            displayProfile();
        fin.read((char*)this,sizeof(*this));
    }
    fin.close();
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

void Donee::displayProduct()
{
    Person::productMenu();
    char option;
    string line;
    cin >> option;
    if(option=='a')
    {
        cout << "Donation Details:" << endl;
        cout << " PID" << "   " << "Amount" << "   " << "Type of Donation" << endl;
        cout << "******************************************" << endl;
        ifstream fmonin("moneyDetails.txt");
        while(getline(fmonin,line))
        {
            cout << line << endl;
        }
        fmonin.close();
    }
    if(option=='b')
    {
        int tp;
        string line;
        cout<<"Enter type :\n1.Ladies  2.Gents" << endl;
        cin>>tp;
        cout << "Donation Details:" << endl;
        cout << " PID" << "   " << "Amount" << "   " << "Type of Donation" << endl;
        cout << "******************************************" << endl;

        if(tp==1)
        {
            ifstream fclothin("ladiesDetails.txt");
            while(getline(fclothin,line))
            {
                cout << line << endl;
            }
            fclothin.close();
        }
        else if(tp==2)
        {
            ifstream fclothin("gentsDetails.txt");
            while(getline(fclothin,line))
            {
                cout << line << endl;
            }
            fclothin.close();
        }
    }
    if(option=='d')
    {
        int bg;
        string line;
        cout<<"Enter group :\n1.A(+)ve 2.A(-)ve 3.B(+)ve 4.B(-)ve 5.O(+)ve 6.O(-)ve 7.AB(+)ve 8.AB(-)ve"<<endl;
        cin>>bg;

        cout << "Donation Details:" << endl;
        cout << " PID" << "   " << "Amount" << "   " << "Type of Donation" << endl;
        cout << "******************************************" << endl;

        if(bg==1)
        {
            ifstream fbloodin("A+Details.txt");
            while(getline(fbloodin,line))
            {
                cout << line << endl;
            }
            fbloodin.close();
        }
        else if(bg==1)
        {
            ifstream fbloodin("A+Details.txt");
            while(getline(fbloodin,line))
            {
                cout << line << endl;
            }
            fbloodin.close();
        }
        else if(bg==2)
        {
            ifstream fbloodin("A-Details.txt");
            while(getline(fbloodin,line))
            {
                cout << line << endl;
            }
            fbloodin.close();
        }
        else if(bg==3)
        {
            ifstream fbloodin("B+Details.txt");
            while(getline(fbloodin,line))
            {
                cout << line << endl;
            }
            fbloodin.close();
        }
        else if(bg==4)
        {
            ifstream fbloodin("B-Details.txt");
            while(getline(fbloodin,line))
            {
                cout << line << endl;
            }
            fbloodin.close();
        }
        else if(bg==5)
        {
            ifstream fbloodin("O+Details.txt");
            while(getline(fbloodin,line))
            {
                cout << line << endl;
            }
            fbloodin.close();
        }
        else if(bg==6)
        {
            ifstream fbloodin("O-Details.txt");
            while(getline(fbloodin,line))
            {
                cout << line << endl;
            }
            fbloodin.close();
        }
        else if(bg==7)
        {
            ifstream fbloodin("AB+Details.txt");
            while(getline(fbloodin,line))
            {
                cout << line << endl;
            }
            fbloodin.close();
        }
        else if(bg==8)
        {
            ifstream fbloodin("AB-Details.txt");
            while(getline(fbloodin,line))
            {
                cout << line << endl;
            }
            fbloodin.close();
        }
    }
    if(option=='e')
    {
        string line;
        cout << "Donation Details:" << endl;
        cout << " ID" << "     " << "Name" <<  endl;
        cout << "******************************************" << endl;

        ifstream fmcin("mentalCounsellingDetails.txt");
        while(getline(fmcin,line))
        {
            cout << line << endl;
        }
        fmcin.close();
    }

}

