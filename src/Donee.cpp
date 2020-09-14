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
extern int productCount;
void startMenu();
void frame(int n);
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
        product2.push_back(new Book);
        product2[productCount]->placeOrder();
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
    frame(82);
    cout << setw(5) << "ID" << setw(35) << "Name" << setw(7) << "Age" << setw(35) << "Email" <<endl;
    frame(82);
    while (getline(fin,em)) {
cout << em << endl ;
}
    fin.close();
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
        frame(98);
        cout <<setw(5) << " PID" << setw(10) << "Amount" << setw(36) << "Type of Donation" << setw(12) << "Donors' ID" << setw(35)<< "Donors' Name" << endl;
        frame(98);
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
        frame(98);
        cout <<setw(5) << " PID" << setw(10) << "Amount" << setw(36) << "Type of Donation" << setw(12) << "Donors' ID" << setw(35)<< "Donors' Name" << endl;
        frame(98);

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
    if(option=='c')
    {
        int ss;
        string line;
        cout<<"Book genre : \n1.Novel\n2.Poetry\n3.Comics\n4.Others"<<endl;
        cin >> ss;

        cout << "Donation Details:" << endl;
        frame(88);
        cout <<setw(5) << " Book Name"  << setw(36) << "Type of Donation" << setw(12) << "Donors' ID" << setw(35) << "Donors' Name" << endl;
        frame(88);

        if(ss==1)
        {
            ifstream fbookin("NovelDetails.txt");
            while(getline(fbookin,line))
            {
                cout << line << endl;
            }
            fbookin.close();
        }
        else if(ss==2)
        {
            ifstream fbookin("PoetryDetails.txt");
            while(getline(fbookin,line))
            {
                cout << line << endl;
            }
            fbookin.close();
        }
        else if(ss==3)
        {
            ifstream fbookin("ComicsDetails.txt");
            while(getline(fbookin,line))
            {
                cout << line << endl;
            }
            fbookin.close();
        }
        else if(ss==4)
        {
            ifstream fbookin("OthersDetails.txt");
            while(getline(fbookin,line))
            {
                cout << line << endl;
            }
            fbookin.close();
        }

    }
    if(option=='d')
    {
        int bg;
        string line;
        cout<<"Enter group :\n1.A(+)ve 2.A(-)ve 3.B(+)ve 4.B(-)ve 5.O(+)ve 6.O(-)ve 7.AB(+)ve 8.AB(-)ve"<<endl;
        cin>>bg;

        cout << "Donation Details:" << endl;
        frame(98);
        cout <<setw(5) << " PID" << setw(10) << "Amount" << setw(36) << "Type of Donation" << setw(12) << "Donors' ID" << setw(35)<< "Donors' Name" << endl;
        frame(98);

        if(bg==1)
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
        frame(91);
        cout <<setw(20) << " Counsellor's ID" << setw(35) << "Name" << setw(36) << "Date" << endl;
        frame(91);
        ifstream fmcin("mentalCounsellingDetails.txt");
        while(getline(fmcin,line))
        {
            cout << line << endl;
        }
        fmcin.close();
    }

}
