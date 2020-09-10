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

void Money::uploadProduct()
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

    type = Parmanent;

    ofstream fmonout;
    fmonout.open("moneyDetails.txt", std::ios::out | std::ios::app);
    fmonout << productID << "   " << Amount << "       " << "Permanent" << endl;
    fmonout.close();
}

void Money::placeOrder()
{
    cout<<"Enter amount : ";
    double Amount;
    int dte,month,year;
    double available;
    cin>>Amount;
    setAmount(Amount);
    cout<<"Enter estimated date to return(DD MM YYYY) :";
    cin>>dte>>month>>year;
    date.setRemainingDay(dte,month,year);
    ifstream fmn;
    fmn.open("totalMoney.txt");
    if(!fmn)
    {
        cout<<"Sorry,no money available."<<endl;
    }
    else{
        while (fmn) {
        fmn>>available;
    }
    if(available>=Amount)
    {
        ofstream fout;
        fout.open("totalMoney.txt");
        fout << available-Amount << endl;
        fout.close();
        cout<<"Order placed..."<<endl;
        cout<<"You have to return within " << date.getReturnWithin() << " days.." << endl;
    }
    else
    {
        cout<<"Sorry,only "<<available<<"tk is available."<<endl;
        placeOrder();
    }
    }

    fmn.close();

}

void Money::displayTotalAmount()
{
    cout<<"Available money : BDT "<<getTotalAmount()<<endl;
}
