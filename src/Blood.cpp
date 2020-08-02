#include "Blood.h"
#include"Product.h"
#include"Person.h"
#include"Donor.h"
#include<bits/stdc++.h>

int Blood::stTotalBagApos=0;
int Blood::stTotalBagAneg=0;
int Blood::stTotalBagBpos=0;
int Blood::stTotalBagBneg=0;
int Blood::stTotalBagABpos=0;
int Blood::stTotalBagABneg=0;
int Blood::stTotalBagOpos=0;
int Blood::stTotalBagOneg=0;
Blood::Blood()
{
    //ctor
}

void Blood::uploadProduct()
{
    bloodGroup g;
    int bag,tbag;
    cout<<"Enter group :";
    scanf("%d",&g);
    setGroup(g);
    cout<<"Enter number of bags :";
    cin>>bag;
    tbag = totalBag[g]+getBagNoFromFile(g,bag);
    totalBag[g]= tbag;
    storeBagNoIntoFile(g,tbag);

}

int Blood::getBagNoFromFile(bloodGroup g,int bag)
{
    ifstream fmn;
    if(g==A_positive)
    {
        fmn.open("totalBagA+.txt");
        if(!fmn)
    {
        stTotalBagApos=0;
    }
    else{
        while (fmn) {
        fmn>>stTotalBagApos;
    }
    }
    fmn.close();
    return stTotalBagApos;
    }
    else if(g==A_negative)
    {
        fmn.open("totalBagA-.txt");
        if(!fmn)
    {
        stTotalBagAneg=0;
    }
    else{
        while (fmn) {
        fmn>>stTotalBagAneg;
    }
    }
    fmn.close();
     return stTotalBagAneg;
    }
    else if(g==B_positive)
    {
        fmn.open("totalBagB+.txt");
        if(!fmn)
    {
        stTotalBagBpos=0;
    }
    else{
        while (fmn) {
        fmn>>stTotalBagBpos;
    }
    }
    fmn.close();
     return stTotalBagBpos;
    }
    else if(g==B_negative)
    {
        fmn.open("totalBagB-.txt");
        if(!fmn)
    {
        stTotalBagBneg=0;
    }
    else{
        while (fmn) {
        fmn>>stTotalBagBneg;
    }
    }
    fmn.close();
     return stTotalBagBneg;
    }
    else if(g==AB_positive)
    {
        fmn.open("totalBagAB+.txt");
        if(!fmn)
    {
        stTotalBagABpos=0;
    }
    else{
        while (fmn) {
        fmn>>stTotalBagABpos;
    }
    }
    fmn.close();
     return stTotalBagABpos;
    }
    else if(g==AB_negative)
    {
        fmn.open("totalBagAB-.txt");
        if(!fmn)
    {
        stTotalBagABneg=0;
    }
    else{
        while (fmn) {
        fmn>>stTotalBagABneg;
    }
    }
    fmn.close();
     return stTotalBagABneg;
    }
    else if(g==O_positive)
    {
        fmn.open("totalBagO+.txt");
        if(!fmn)
    {
        stTotalBagOpos=0;
    }
    else{
        while (fmn) {
        fmn>>stTotalBagOpos;
    }
    }
    fmn.close();
     return stTotalBagOpos;
    }
    else if(g==O_negative)
    {
        fmn.open("totalBagO-.txt");
        if(!fmn)
    {
        stTotalBagOneg=0;
    }
    else{
        while (fmn) {
        fmn>>stTotalBagOneg;
    }
    }
    fmn.close();
     return stTotalBagOneg;
    }


}
void Blood::storeBagNoIntoFile(bloodGroup g,int tbag)
{
   if(g==A_positive)
   {
    ofstream fout;
    fout.open("totalBagA+.txt");
    fout << tbag << endl;
    fout.close();
   }
   else if(g==A_negative)
   {
    ofstream fout;
    fout.open("totalBagA-.txt");
    fout << tbag << endl;
    fout.close();
   }
   else if(g==B_positive)
   {
    ofstream fout;
    fout.open("totalBagB+.txt");
    fout << tbag << endl;
    fout.close();
   }
   else if(g==B_negative)
   {
    ofstream fout;
    fout.open("totalBagB-.txt");
    fout << tbag << endl;
    fout.close();
   }
   else if(g==AB_positive)
   {
    ofstream fout;
    fout.open("totalBagAB+.txt");
    fout << tbag << endl;
    fout.close();
   }
   else if(g==AB_negative)
   {
    ofstream fout;
    fout.open("totalBagAB-.txt");
    fout << tbag << endl;
    fout.close();
   }
   else if(g==O_positive)
   {
    ofstream fout;
    fout.open("totalBagO+.txt");
    fout << tbag << endl;
    fout.close();
   }
   else if(g==O_negative)
   {
    ofstream fout;
    fout.open("totalBagO-.txt");
    fout << tbag << endl;
    fout.close();
   }
}
