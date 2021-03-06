#include "MentalCounselling.h"
#include<bits/stdc++.h>
using namespace std;

void frame(int n);
MentalCounselling::MentalCounselling()
{
    //ctor
}

void MentalCounselling::uploadProduct(long int id,string name)
{
    int day,month,year;
    setConsultantID(id);
    cout<<"Enter when you will be free to counsel(DD MM YYYY) :";
    cin>>day>>month>>year;
    date.setDate(day,month,year);
    date.setRemainingDay(day,month,year);
    //cout<<date.dayCountFromJanuary()<<endl;
    ofstream fout;
    fout.open("mentalCounsellingDates.txt",ios::out|ios::app);
    fout << date.getReturnWithin() << endl;
    fout.close();
    //string str = to_string(day)+" "+to_string(month)+" "+to_string(year);
    ofstream fmut;
    fmut.open("mentalCounsellingDetails.txt",ios::out|ios::app);
    fmut << setw(5) << id<< setw(40)<<name<< setw(8) << day << "-" << month << "-"<< year << endl;
    fmut.close();
    ofstream fnut;
    fnut.open("mentalCounsellingAvailable.txt",ios::out|ios::app);
    fnut <<day<<"-"<<month<<"-"<<year<<endl;
    fnut.close();

}

void MentalCounselling::placeOrder()
{
    cout<<"1. Appoinment\n2. View Counsellor List\n3. Display available dates\n4. Exit\n";
    int counsellingChoice;
    cin>>counsellingChoice;
    if(counsellingChoice == 1)
    {
        createAppoinment();
    }
    else if(counsellingChoice == 2)
    {
        displayCounsellorDetails();
    }
    else if(counsellingChoice == 3)
    {
        displayAvailableDates();
    }
    else if(counsellingChoice == 4)
    {
        return;
    }
}

void MentalCounselling::createAppoinment()
{
    int day,month,year,available,isFound=0;
    cout<<"Enter when you want consultation(DD MM YYYY) :";
    cin>>day>>month>>year;
    date.setDate(day,month,year);
    date.setRemainingDay(day,month,year);
    ifstream fin;
	fin.open("mentalCounsellingDates.txt");
	if(!fin)
	{
		cout << "Sorry,no counsellor is available.\n";
	}
	while(!fin.eof())
	{
		fin>>available;
		if(available==date.getReturnWithin())
        {
            isFound++;
            cout<<"Appoinment created..."<<endl;
            fin.close();
            break;
        }
	}
	if(isFound==0)
    {
        cout << "Sorry,no counsellor is available on that day.\n";
        placeOrder();
    }
    else
    {
        ifstream fout;
        int check;
   fout.open("mentalCounsellingDates.txt");
    ofstream temp;
    temp.open("temp.txt");
    while (fout>>check)
    {
      if (check != available)
        {temp << check << endl;}
    }
    fout.close();
    temp.close();
    remove("mentalCounsellingDates.txt");
    rename("temp.txt", "mentalCounsellingDates.txt");

    ifstream fmut;
   fmut.open("mentalCounsellingAvailable.txt");
    ofstream temp2;
    temp2.open("temp2.txt");
    int dt,mn,yr;
    while (fmut>>dt)
    {
        if(fmut>>mn)
        {
            if(fmut>>yr)
            {
                if (dt != day && mn!=month && yr!=year)
                    temp2 << dt << mn << yr <<endl;
            }
        }

    }
    fmut.close();
    temp2.close();
    remove("mentalCounsellingAvailable.txt");
    rename("temp2.txt", "mentalCounsellingAvailable.txt");
    }
}

void MentalCounselling::displayCounsellorDetails()
{
    string line;
    ifstream file("mentalCounsellingDetails.txt");
    frame(61);
    cout<< setw(5) << "ID" << setw(40) << "Name" << setw(16) << "Date" << endl;
    frame(61);
    while(getline(file,line))
    {
        cout<<line<<endl;
    }
    file.close();
    placeOrder();
}

void MentalCounselling::displayAvailableDates()
{
    string line;
    ifstream file("mentalCounsellingAvailable.txt");
    frame(10);
    cout<<"DD-MM-YYYY\n";
    frame(10);
    while(getline(file,line))
    {
        cout<<line<<endl;
    }
    file.close();
    placeOrder();
}

