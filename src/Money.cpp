#include "Money.h"
#include"Product.h"
#include"Person.h"
#include"Donor.h"
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
    stTotalAmount = stTotalAmount + Amount;
    totalAmount = stTotalAmount;
    ifstream fin;
    fin.open("moneyCount.txt");
    if(!fin)
    {
        stProductID=12000;
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
}

void Money::displayTotalAmount()
{
    cout<<"Available money : BDT "<<getTotalAmount()<<endl;
}
