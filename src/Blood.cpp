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
long int Blood::stProductID=22000;
Blood::Blood()
{
    //ctor
}

void Blood::uploadProduct()
{
    bloodGroup g;
    int bag,tbag,bg;
    cout<<"Enter group :\n1.A(+)ve 2.A(-)ve 3.B(+)ve 4.B(-)ve 5.O(+)ve 6.O(-)ve 7.AB(+)ve 8.AB(-)ve"<<endl;
    cin>>bg;
    if(bg==1)
    {
        g=A_positive;
    }
    else if(bg==2)
    {
        g=A_negative;
    }
    else if(bg==3)
    {
        g=B_positive;
    }
    else if(bg==4)
    {
        g=B_negative;
    }
    else if(bg==5)
    {
        g=O_positive;
    }
    else if(bg==6)
    {
        g=O_negative;
    }
    else if(bg==7)
    {
        g=AB_positive;
    }
    else if(bg==8)
    {
        g=AB_negative;
    }
    setGroup(g);
    fflush(stdin);
    cout<<"Enter number of bags :";
    cin>>bag;
    tbag = bag+getBagNoFromFile(g,bag);
    totalBag[g]= tbag;
    storeBagNoIntoFile(g,tbag);
    type = Parmanent;
    ifstream fmn;
    fmn.open("totalBag.txt");
    if(!fmn)
    {
        stProductID=22000;
    }
    else{
        while (fmn) {
        fmn>>stProductID;
    }
    }
    fmn.close();
    productID=++stProductID;
    ofstream fout;
    fout.open("totalBag.txt");
    fout << productID << endl;
    fout.close();
    cout<<"\n\nUploaded...";

    if(bg==1)
    {
        ofstream fbloodout;
        fbloodout.open("A+Details.txt", std::ios::out | std::ios::app);
        fbloodout << productID << "   " << bag << "       " << "Permanent" << endl;
        fbloodout.close();
    }
    else if(bg==2)
    {
        ofstream fbloodout;
        fbloodout.open("A-Details.txt", std::ios::out | std::ios::app);
        fbloodout << productID << "   " << bag << "       " << "Permanent" << endl;
        fbloodout.close();
    }
    else if(bg==3)
    {
        ofstream fbloodout;
        fbloodout.open("B+Details.txt", std::ios::out | std::ios::app);
        fbloodout << productID << "   " << bag << "       " << "Permanent" << endl;
        fbloodout.close();
    }
    else if(bg==4)
    {
        ofstream fbloodout;
        fbloodout.open("B-Details.txt", std::ios::out | std::ios::app);
        fbloodout << productID << "   " << bag << "       " << "Permanent" << endl;
        fbloodout.close();
    }
    else if(bg==5)
    {
        ofstream fbloodout;
        fbloodout.open("O+Details.txt", std::ios::out | std::ios::app);
        fbloodout << productID << "   " << bag << "       " << "Permanent" << endl;
        fbloodout.close();
    }
    else if(bg==6)
    {
        ofstream fmonout;
        fmonout.open("O-Details.txt", std::ios::out | std::ios::app);
        fmonout << productID << "   " << bag << "       " << "Permanent" << endl;
        fmonout.close();
    }
    else if(bg==7)
    {
        ofstream fmonout;
        fmonout.open("AB+Details.txt", std::ios::out | std::ios::app);
        fmonout << productID << "   " << bag << "       " << "Permanent" << endl;
        fmonout.close();
    }
    else if(bg==8)
    {
        ofstream fbloodout;
        fbloodout.open("AB-Details.txt", std::ios::out | std::ios::app);
        fbloodout << productID << "   " << bag << "       " << "Permanent" << endl;
        fbloodout.close();
    }

}

int Blood::getBagNoFromFile(bloodGroup g,int bag)
{
    ifstream fmn;
    if(g==A_positive)
    {
        fmn.open("totalBagA+.txt");
        if(!fmn)
    {
        stTotalBagApos=bag;
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

void Blood::placeOrder()
{
    bloodGroup g;
    int bag,tbag,bg;
    cout<<"Enter group :\n1.A(+)ve 2.A(-)ve 3.B(+)ve 4.B(-)ve 5.O(+)ve 6.O(-)ve 7.AB(+)ve 8.AB(-)ve"<<endl;
    cin>>bg;
    if(bg==1)
    {
        g=A_positive;
    }
    else if(bg==2)
    {
        g=A_negative;
    }
    else if(bg==3)
    {
        g=B_positive;
    }
    else if(bg==4)
    {
        g=B_negative;
    }
    else if(bg==5)
    {
        g=O_positive;
    }
    else if(bg==6)
    {
        g=O_negative;
    }
    else if(bg==7)
    {
        g=AB_positive;
    }
    else if(bg==8)
    {
        g=AB_negative;
    }
    cout<<"Enter number of bags :";
    cin>>bag;
    int check = checkBagNoFromFile(g,bag);
    if(check == -1)
    {
        cout<<"Sorry,no bag is available."<<endl;
    }
    else if(check == 0)
    {
        cout<<"Order placed..."<<endl;
    }
    else
    {
        cout<<"Sorry,only "<<check<<" bags are available."<<endl;
        placeOrder();
    }
}

int Blood::checkBagNoFromFile(bloodGroup g,int bag)
{
    ifstream fmn;
    int available;
    if(g==A_positive)
    {
        fmn.open("totalBagA+.txt");
        if(!fmn)
    {
        return -1;
    }
    else{
        while (fmn) {
        fmn>>available;
    }
    }
    fmn.close();
    if(available>bag)
    {
        storeBagNoIntoFile(g,available-bag);
        return 0;
    }
    else
    {
        return available;
    }
    }
    else if(g==A_negative)
    {
        fmn.open("totalBagA-.txt");
        if(!fmn)
    {
       return -1;
    }
    else{
        while (fmn) {
        fmn>>available;
    }
    }
    fmn.close();
     if(available>bag)
    {
        storeBagNoIntoFile(g,available-bag);
        return 0;
    }
    else
    {
        return available;
    }
    }
    else if(g==B_positive)
    {
        fmn.open("totalBagB+.txt");
        if(!fmn)
    {
        return -1;
    }
    else{
        while (fmn) {
        fmn>>available;
    }
    }
    fmn.close();
    if(available>bag)
    {
        storeBagNoIntoFile(g,available-bag);
        return 0;
    }
    else
    {
        return available;
    }
    }
    else if(g==B_negative)
    {
        fmn.open("totalBagB-.txt");
        if(!fmn)
    {
        return -1;
    }
    else{
        while (fmn) {
        fmn>>available;
    }
    }
    fmn.close();
     if(available>bag)
    {
        storeBagNoIntoFile(g,available-bag);
        return 0;
    }
    else
    {
        return available;
    }
    }
    else if(g==AB_positive)
    {
        fmn.open("totalBagAB+.txt");
        if(!fmn)
    {
        return -1;
    }
    else{
        while (fmn) {
        fmn>>available;
    }
    }
    fmn.close();
     if(available>bag)
    {
        storeBagNoIntoFile(g,available-bag);
        return 0;
    }
    else
    {
        return available;
    }
    }
    else if(g==AB_negative)
    {
        fmn.open("totalBagAB-.txt");
        if(!fmn)
    {
        return -1;
    }
    else{
        while (fmn) {
        fmn>>available;
    }
    }
    fmn.close();
    if(available>bag)
    {
        storeBagNoIntoFile(g,available-bag);
        return 0;
    }
    else
    {
        return available;
    }
    }
    else if(g==O_positive)
    {
        fmn.open("totalBagO+.txt");
        if(!fmn)
    {
        return -1;
    }
    else{
        while (fmn) {
        fmn>>available;
    }
    }
    fmn.close();
    if(available>bag)
    {
        storeBagNoIntoFile(g,available-bag);
        return 0;
    }
    else
    {
        return available;
    }
    }
    else if(g==O_negative)
    {
        fmn.open("totalBagO-.txt");
        if(!fmn)
    {
        return -1;
    }
    else{
        while (fmn) {
        fmn>>available;
    }
    }
    fmn.close();
    if(available>bag)
    {
        storeBagNoIntoFile(g,available-bag);
        return 0;
    }
    else
    {
        return available;
    }
    }


}
