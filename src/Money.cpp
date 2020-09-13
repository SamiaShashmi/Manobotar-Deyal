#include "Money.h"
#include"Product.h"
#include"Person.h"
#include"Date.h"
#include<bits/stdc++.h>
using namespace std;
double Money::stTotalAmount=0;
long int Money::stProductID=21000;
Money::Money()
{
    //ctor
}
void Money::uploadProduct(long int id,string name)
{
    cout<<"Enter amount : ";
    double Amount;
    int date,month,year;
    cin>>Amount;
    setAmount(Amount);
    ifstream fmn;
    fmn.open("totalMoney.txt");
    if(!fmn)
    {
        stTotalAmount=0;
    }
    else{
        while (fmn) {
        fmn>>stTotalAmount;
    }
    }

    fmn.close();
    stTotalAmount = stTotalAmount + Amount;
    totalAmount = stTotalAmount;
    ofstream fmut;
    fmut.open("totalMoney.txt");
    fmut << totalAmount << endl;
    fmut.close();
    ifstream fin;
    fin.open("moneyCount.txt");
    if(!fin)
    {
        stProductID=21000;
    }
    else{
        while (fin) {
        fin>>stProductID;
    }
    }

    fin.close();
    productID=++stProductID;
    ofstream fout;
    fout.open("moneyCount.txt");
        fout << productID << endl;
    fout.close();
    cout<<"\n\nUploaded...";
    type = Temporary;
    ofstream fmonout;
    fmonout.open("moneyDetails.txt", std::ios::out | std::ios::app);
    fmonout << setw(5 ) << productID << setw(15) << Amount << setw(36) << "Temporary" << setw(10) << id << setw(35) << name <<endl;
    fmonout.close();
}

void Money::placeOrder()
{
     ifstream fmn;
     fmn.open("totalMoney.txt");
    double available;
    if(!fmn)
    {
        cout<<"Sorry,no money available."<<endl;
    }
    else{
        while (fmn) {
        fmn>>available;}
    cout<<"Available BDT "<<available<<endl;
    }
    cout<<"Enter amount : ";
    double Amount;
    int daysToReturn;
    cin>>Amount;
    setAmount(Amount);
    if(available>=Amount)
    {
        ofstream fout;
        fout.open("totalMoney.txt");
        fout << available-Amount << endl;
        fout.close();
        cout<<"Enter estimated days to return within :";
        cin >> daysToReturn;
        date.addDays(daysToReturn);
        cout<<"Order placed..."<<endl;
        cout<<"You have to return within " << date << endl;
    }
    else
    {
        cout<<"Sorry, "<<Amount - available<<"tk should be reduced."<<endl;
        placeOrder();
    }
    fmn.close();
}

void Money::displayTotalAmount()
{
    cout<<"Available money : BDT "<<getTotalAmount()<<endl;
}
