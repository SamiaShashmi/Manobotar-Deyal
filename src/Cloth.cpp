#include "Cloth.h"
#include"Product.h"
#include<bits/stdc++.h>
using namespace std;
long int Cloth::stProductID=23000;
int Cloth::stLadiesCount=0;
int Cloth::stGentsCount=0;
Cloth::Cloth()
{
    //ctor
}
void Cloth::uploadProduct()
{
    clothType t;
    int am,tcloth,tp;
    cout<<"Enter type :\n1.Ladies  2.Gents";
    cin>>tp;
    if(tp==1)
    {
        t=Ladies;
    }
    else if(tp==2)
    {
        t=Gents;
    }
    setType(t);
    fflush(stdin);
    cout<<"Enter amount :";
    cin>>am;
    setAmount(am);
    tcloth=totalCloth[t]+getTotalClothFromFile(t,am);
    totalCloth[t]=tcloth;
    storeTotalClothIntoFile(t,am);
    ifstream fmn;
    fmn.open("totalCloth.txt");
    if(!fmn)
    {
        stProductID=23000;
    }
    else{
        while (fmn) {
        fmn>>stProductID;
    }
    }
    fmn.close();
   productID=++stProductID;
   ofstream fout;
   fout.open("totalCloth.txt");
        fout << productID << endl;
    fout.close();
    type = Parmanent;
    cout<<"\n\nUploaded...";

}

int Cloth::getTotalClothFromFile(clothType t,int am)
{
    ifstream fmn;
    if(t==Ladies)
    {
        fmn.open("totalLadiesCloth.txt");
        if(!fmn)
    {
        stLadiesCount=0;
    }
    else{
        while (fmn) {
        fmn>>stLadiesCount;
    }
    }
    fmn.close();
    return stLadiesCount;
    }
    else if(t==Gents)
    {
        fmn.open("totalGentsCloth.txt");
        if(!fmn)
    {
        stGentsCount=0;
    }
    else{
        while (fmn) {
        fmn>>stGentsCount;
    }
    }
    fmn.close();
    return stGentsCount;
    }
}

void Cloth::storeTotalClothIntoFile(clothType t,int am)
{
     if(t==Ladies)
   {
    ofstream fout;
    fout.open("totalLadiesCloth.txt");
    fout << am << endl;
    fout.close();
   }
   else if(t==Gents)
   {
    ofstream fout;
    fout.open("totalGentsCloth.txt");
    fout << am << endl;
    fout.close();
   }
}
