#include "Money.h"
#include"Product.h"
#include"Person.h"
#include"Donor.h"
#include<bits/stdc++.h>
using namespace std;
double Money::stTotalAmount=0;
Money::Money()
{
    //ctor
}
void Money::uploadProduct()
{
    cout<<"Enter amount : ";
    double Amount;
    int date,month,year,tdate,tmonth,tyear;
    cin>>Amount;
    setAmount(Amount);
    stTotalAmount = stTotalAmount + Amount;
    totalAmount = stTotalAmount;
    cout<<"Enter today's date : (DD MM YYYY)"<<endl;
    cin>>tdate>>tmonth>>tyear;
    cout<<"Enter estmated date to return : (DD MM YYYY)"<<endl;
    cin>>date>>month>>year;
    cout<<"\n\nUploaded...";
//    type = "Temporary";
}

void Money::displayTotalAmount()
{
    cout<<"Available money : BDT "<<getTotalAmount()<<endl;
}
