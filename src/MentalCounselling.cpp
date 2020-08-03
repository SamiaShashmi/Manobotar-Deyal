#include "MentalCounselling.h"
#include<bits/stdc++.h>
using namespace std;

MentalCounselling::MentalCounselling()
{
    //ctor
}

void MentalCounselling::uploadProduct()
{
    long int id;
    int day,month,year;
    cout<<"Enter your ID :";
    cin>>id;
    setConsultantID(id);
    cout<<"Enter when you will be free to counsel(DD MM YYYY) :";
    cin>>day>>month>>year;
    date.setDate(day,month,year);
    cout<<date.dayCountFromJanuary()<<endl;
    ofstream fout;
    fout.open("mentalCounsellingDates.txt",ios::out|ios::app);
    fout << date.dayCountFromJanuary() << endl;
    fout.close();
}
