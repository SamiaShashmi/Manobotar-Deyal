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

int Donee::matchPassword(long int id,string pass)
    {
        ifstream f;
        int ifMatch=0;
        f.open("Donee.dat",ios::in|ios::binary);
        f.read((char*)this,sizeof(*this));
        while(!f.eof())
        {
            if(doneeID==id)
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

void Donee::displayProduct()
{
    Person::productMenu();
    char option;
    cout << "Choose which product to be displayed:";
    cin >> option;
    if(option=='a')
    {
        ifstream fmoney("totalMoney.txt"); // open input file

        if(!fmoney)
        {
            cout << "No money available.\n";
            return ;
        }
        int i;

        fmoney >> i;
        cout << "Total Money Available:Tk." << i << endl;

        fmoney.close();
    }
    else if(option=='b')
    {
        ifstream fgcloth("totalGentsCloth.txt"); // open input file

        if(!fgcloth)
        {
            cout << "No cloths available.\n";
            return ;
        }
        int i;

        fgcloth >> i;
        cout << "Total Number of Gents Cloth Available:" << i << endl;

        fgcloth.close();

        ifstream flcloth("totalLadiesCloth.txt"); // open input file

        if(!flcloth)
        {
            cout << "No cloths available.\n";
            return ;
        }
        int j;

        flcloth >> j;
        cout << "Total Number of Ladies Cloth Available:" << j << endl;

        flcloth.close();
    }
    /*else if(option=='c')
    {

    }*/
    else if(option=='d')
    {
        string group;
        cout << "Enter Blood Group:";
        cin >> group;

        if(group=="A+")
        {
            ifstream fapos("totalBagA+.txt"); // open input file

            if(!fapos)
            {
                cout << "No bags available.\n";
                return ;
            }
            int i;

            fapos >> i;
            cout << "Total Number of A+ bags:" << i << "Bags" << endl;

            fapos.close();
        }
        else if(group=="A-")
        {
            ifstream faneg("totalBagA-.txt"); // open input file

            if(!faneg)
            {
                cout << "No bags available.\n";
                return ;
            }
            int i;

            faneg >> i;
            cout << "Total Number of A- bags:" << i << "Bags" << endl;

            faneg.close();
        }
        else if(group=="B+")
        {
            ifstream fbpos("totalBagB+.txt"); // open input file

            if(!fbpos)
            {
                cout << "No bags available.\n";
                return ;
            }
            int i;

            fbpos >> i;
            cout << "Total Number of B+ bags:" << i << "Bags" << endl;

            fbpos.close();
        }
        else if(group=="B-")
        {
            ifstream fbneg("totalBagB-.txt"); // open input file

            if(!fbneg)
            {
                cout << "No bags available.\n";
                return ;
            }
            int i;

            fbneg >> i;
            cout << "Total Number of B- bags:" << i << "Bags" << endl;

            fbneg.close();
        }
        else if(group=="O+")
        {
            ifstream fopos("totalBagO+.txt"); // open input file

            if(!fopos)
            {
                cout << "No bags available.\n";
                return ;
            }
            int i;

            fopos >> i;
            cout << "Total Number of O+ bags:" << i << "Bags" << endl;

            fopos.close();
        }
        else if(group=="O-")
        {
            ifstream foneg("totalBagO-.txt"); // open input file

            if(!foneg)
            {
                cout << "No bags available.\n";
                return ;
            }
            int i;

            foneg >> i;
            cout << "Total Number of O- bags:" << i << "Bags" << endl;

            foneg.close();
        }
        else if(group=="AB+")
        {
            ifstream fabpos("totalBagAB+.txt"); // open input file

            if(!fabpos)
            {
                cout << "No bags available.\n";
                return ;
            }
            int i;

            fabpos >> i;
            cout << "Total Number of AB+ bags:" << i << "Bags" << endl;

            fabpos.close();
        }
        else if(group=="AB-")
        {
            ifstream fabneg("totalBagAB-.txt"); // open input file

            if(!fabneg)
            {
                cout << "No bags available.\n";
                return ;
            }
            int i;

            fabneg >> i;
            cout << "Total Number of AB- bags:" << i << " Bags" << endl;

            fabneg.close();
        }
    }
    else if(option=='e')
    {
        ifstream fmcounsel("mentalCounsellingDetails.txt"); // open input file

        if(!fmcounsel)
        {
            cout << "No counselor available.\n";
            return ;
        }

        string str;
        int i;
        cout << "List of counselors:\n";
        while(getline(fmcounsel,str))
        {
            fmcounsel >> i >> str;
            cout << i << ' ' << str << endl;
        }

        fmcounsel.close();
    }

}
