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
    tbag = bag+getBagNoFromFile(g);
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
        fbloodout << setw(5) << productID << setw(35) << bag << setw(42) << "Permanent" << endl;
        fbloodout.close();
    }
    else if(bg==2)
    {
        ofstream fbloodout;
        fbloodout.open("A-Details.txt", std::ios::out | std::ios::app);
        fbloodout << setw(5) << productID << setw(35) << bag << setw(42) << "Permanent" << endl;
        fbloodout.close();
    }
    else if(bg==3)
    {
        ofstream fbloodout;
        fbloodout.open("B+Details.txt", std::ios::out | std::ios::app);
        fbloodout << setw(5) << productID << setw(35) << bag << setw(42) << "Permanent" << endl;
        fbloodout.close();
    }
    else if(bg==4)
    {
        ofstream fbloodout;
        fbloodout.open("B-Details.txt", std::ios::out | std::ios::app);
        fbloodout << setw(5) << productID << setw(35) << bag << setw(42) << "Permanent" << endl;
        fbloodout.close();
    }
    else if(bg==5)
    {
        ofstream fbloodout;
        fbloodout.open("O+Details.txt", std::ios::out | std::ios::app);
        fbloodout << setw(5) << productID << setw(35) << bag << setw(42) << "Permanent" << endl;
        fbloodout.close();
    }
    else if(bg==6)
    {
        ofstream fmonout;
        fmonout.open("O-Details.txt", std::ios::out | std::ios::app);
        fmonout << setw(5) << productID << setw(35) << bag << setw(42) << "Permanent" << endl;
        fmonout.close();
    }
    else if(bg==7)
    {
        ofstream fmonout;
        fmonout.open("AB+Details.txt", std::ios::out | std::ios::app);
        fmonout << setw(5) << productID << setw(35) << bag << setw(42) << "Permanent" << endl;
        fmonout.close();
    }
    else if(bg==8)
    {
        ofstream fbloodout;
        fbloodout.open("AB-Details.txt", std::ios::out | std::ios::app);
        fbloodout << setw(5) << productID << setw(35) << bag << setw(42) << "Permanent" << endl;
        fbloodout.close();
    }
}

int Blood::getBagNoFromFile(bloodGroup g)
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

void Blood::placeOrder()
{
    bloodGroup g;
    char bag,tbag,bg;
    cout<<"Enter group :\n1.A(+)ve 2.A(-)ve 3.B(+)ve 4.B(-)ve 5.O(+)ve 6.O(-)ve 7.AB(+)ve 8.AB(-)ve"<<endl;
    cout<< "\n\nTo see the list of available bags, press 9" << endl;
    cin>>bg;
    if(bg=='1')
    {
        g=A_positive;
    }
    else if(bg=='2')
    {
        g=A_negative;
    }
    else if(bg=='3')
    {
        g=B_positive;
    }
    else if(bg=='4')
    {
        g=B_negative;
    }
    else if(bg=='5')
    {
        g=O_positive;
    }
    else if(bg=='6')
    {
        g=O_negative;
    }
    else if(bg=='7')
    {
        g=AB_positive;
    }
    else if(bg=='8')
    {
        g=AB_negative;
    }
    else if(bg == '9')
    {
        showBagList();
        placeOrder();
    }
    else
    {
        cout<<"Invalid choice!!!";
        placeOrder();
    }
    cout<<"Enter number of bags :";
    cin>>bag;
    int check = checkBagNoFromFile(g,bag);
    if(check == -1)
    {
        cout<<"Sorry,no bag is available."<<endl;
        placeOrder();
    }
    else if(check == 0)
    {
        cout<<"Order placed..."<<endl;
        return;
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

void Blood::showBagList()
{
    cout<<"1. A+\t"<<getBagNoFromFile(A_positive)<<endl;
    cout<<"2. A-\t"<<getBagNoFromFile(A_negative)<<endl;
    cout<<"3. B+\t"<<getBagNoFromFile(B_positive)<<endl;
    cout<<"4. B-\t"<<getBagNoFromFile(B_negative)<<endl;
    cout<<"5. O+\t"<<getBagNoFromFile(O_positive)<<endl;
    cout<<"6. O-\t"<<getBagNoFromFile(O_negative)<<endl;
    cout<<"7. AB+\t"<<getBagNoFromFile(AB_positive)<<endl;
    cout<<"8. AB-\t"<<getBagNoFromFile(AB_negative)<<endl;

}
