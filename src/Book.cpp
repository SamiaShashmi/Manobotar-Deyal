#include<bits/stdc++.h>
#include<fstream>
#include<vector>
#include<cstring>
#include<algorithm>
#include"Book.h"
#include"Person.h"
#include"Product.h"
using namespace std;

Book::Book()
{

}
void delete_line(const char *file_name, int n)
{

    ifstream is(file_name);


    ofstream ofs;
    ofs.open("temp.txt", ofstream::out);


    char c;
    int line_no = 1;
    while (is.get(c))
    {
        if (c == '\n')
            line_no++;
        if (line_no != n)
            ofs << c;
    }

    ofs.close();
    is.close();
    remove(file_name);
    rename("temp.txt", file_name);
}

bool getFileContent(string fileName, vector<string> & vecOfStrs)
{

    ifstream in(fileName.c_str());
    if(!in)
    {
        cerr << "No entry yet for "<<fileName<<endl;
        return false;
    }
    string str;
    while (getline(in, str))
    {
        if(str.size() > 0)
            vecOfStrs.push_back(str);
    }

    in.close();
    return true;
}

void Book::uploadProduct(long int id,string name)
{
    cout<<"How many books you want to donate?"<<endl;
    int t,ss;
    cin>>t;
    string dummy;
    string bname;
    getline(cin, dummy);
    while(t--)
    {
        cout<<"Book genre : \n1.Novel\n2.Poetry\n3.Comics\n4.Others"<<endl;
        cin>>ss;
        if(ss==1)
        {
            ofstream file;
            string dummy;
            getline(cin, dummy);
            cout << "Enter name of the book :";
            getline(cin, bname);
            file.open("Novel.txt",std::ios::app);
            file<<bname<<endl;
            file.close();
            ofstream fbookout;
            fbookout.open("NovelDetails.txt",std::ios::out | std::ios::app);
            fbookout << setw(5) << bname << setw(36) << "Temporary" << setw(12) << id << setw(35) << name <<endl;
            fbookout.close();
        }

        else if (ss==2)
        {
            string dummy;
            getline(cin, dummy);
            ofstream file;
            string bname;
            cout << "Enter name of the book :";
            getline(cin, bname);
            file.open("Poetry.txt",std::ios::app);
            file<<bname<<endl;
            file.close();
            ofstream fbookout;
            fbookout.open("PoetryDetails.txt",std::ios::out | std::ios::app);
            fbookout << setw(5) << bname << setw(36) << "Temporary" << setw(12) << id << setw(35) << name <<endl;
            fbookout.close();
        }
        else if(ss==3)
        {
            string dummy;
            getline(cin, dummy);
            ofstream file;
            string bname;
            cout << "Enter name of the book :";
            getline(cin, bname);
            file.open("Comics.txt",std::ios::app);
            file<<bname<<endl;
            file.close();
             ofstream fbookout;
            fbookout.open("ComicsDetails.txt",std::ios::out | std::ios::app);
            fbookout << setw(5) << bname << setw(36) << "Temporary" << setw(12) << id << setw(35) << name <<endl;
            fbookout.close();
        }

        else if(ss==4)
        {
            string dummy;
            getline(cin, dummy);
            ofstream file;
            string bname;
            cout << "Enter name of the book :";
            getline(cin, bname);
            file.open("Others.txt",std::ios::app);
            file<<bname<<endl;
            file.close();
            ofstream fbookout;
            fbookout.open("OthersDetails.txt",std::ios::out | std::ios::app);
            fbookout << setw(5) << bname  << setw(36) << "Temporary" << setw(12) << id << setw(35) << name <<endl;
            fbookout.close();

        }

        else
            cout<<"Error! read the instructions carefully please ( select within 1-4)"<<endl;

    }

}

void Book::placeOrder()
{
    char placeOrderChoice;
    cout << "a. View amount\nb. Order" << endl;
    fflush(stdin);
    cin >> placeOrderChoice;
    if(placeOrderChoice == 'a')
    {
        showBookList();
    }
    else if(placeOrderChoice == 'b')
    {
        cout<<"How many books you want to take?"<<endl;
        int t;
        cin>>t;
        while(t--)
        {
            cout<<"Which Genre you want to pick?\nBook genre : \n1.Novel\n2.Poetry\n3.Comics\n4.Others"<<endl;
            int ss;
            cin>>ss;
            if(ss==1)
            {
                cout<<"Here is all the books from your choosen genre"<<endl;
                string dummy;
                getline(cin, dummy);
                vector<string>names;
                bool result = getFileContent("Novel.txt", names);
                if(result)
                {
                    int i=0;
                    for(string & line :names)
                    {
                        i+=1;
                        cout<<i<<"."<<line<<endl;
                    }
                }
                cout<<"Which one you want to pick?"<<endl;
                int n;
                cin>>n;
                delete_line("Novel.txt", n);
            }

            else if (ss==2)
            {
                cout<<"Here is all the books from your choosen genre"<<endl;
                string dummy;
                getline(cin, dummy);
                vector<string>names;
                bool result = getFileContent("Poetry.txt", names);
                if(result)
                {
                    int i=0;
                    for(string & line :names)
                    {
                        i+=1;
                        cout<<i<<"."<<line<<endl;
                    }

                }

                cout<<"Which one you want to pick?"<<endl;
                int n;
                cin>>n;
                delete_line("Poetry.txt", n);
            }
            else if(ss==3)
            {
                cout<<"Here is all the books from your choosen genre"<<endl;
                string dummy;
                getline(cin, dummy);
                vector<string>names;
                bool result = getFileContent("Comics.txt", names);
                if(result)
                {
                    int i=0;
                    for(string & line :names)
                    {
                        i+=1;
                        cout<<i<<"."<<line<<endl;
                    }

                }
                cout<<"Which one you want to pick?"<<endl;
                int n;
                cin>>n;
                delete_line("Comics.txt", n);
            }
            else if(ss==4)
            {
                cout<<"Here is all the books from your choosen genre"<<endl;
                string dummy;
                getline(cin, dummy);
                vector<string>names;
                bool result = getFileContent("Others.txt", names);
                if(result)
                {
                    int i=0;
                    for(string & line :names)
                    {
                        i+=1;
                        cout<<i<<"."<<line<<endl;
                    }

                }
                cout<<"Which one you want to pick?"<<endl;
                int n;
                cin>>n;
                delete_line("Others.txt", n);
            }
            else
                cout<<"Error! read the instructions carefully please ( select within 1-4)"<<endl;
        }
        int daysToReturn;
        cout<<"Enter estimated days to return within :";
        cin >> daysToReturn;
        date.addDays(daysToReturn);
        cout<<"Order placed..."<<endl;
        cout<<"You have to return within " << date << endl;
    }
    else
    {
        cout << "Invalid Choice!!!" << endl;
    }


}


void Book::showBookList()
{

    cout<<"Here is all the book we have:"<<endl;
    cout<<endl;
    string dummy;
    getline(cin, dummy);
    vector<string>names;

    cout<<"Our Novel  collection:"<<endl;
    bool result = getFileContent("Novel.txt", names);
    if(result)
    {

        int i=0;
        for(string & line :names)
        {
            i+=1;
            cout<<i<<"."<<line<<endl;
        }

    }

    cout<<endl;

    vector<string>ames;
    cout<<"Our Poetry collection:"<<endl;

    bool result1 = getFileContent("Poetry.txt", ames);
    if(result1)
    {

        int i=0;
        for(string & line :ames)
        {
            i+=1;
            cout<<i<<"."<<line<<endl;
        }

    }

    cout<<endl;

    vector<string>mes;
    cout<<"Our comics collection:"<<endl;

    bool result2 = getFileContent("Comics.txt", mes);
    if(result2)
    {

        int i=0;
        for(string & line :mes)
        {
            i+=1;
            cout<<i<<"."<<line<<endl;
        }

    }

    vector<string>es;
    cout<<endl;

    cout<<"Our Other collections:"<<endl;
    bool result3 = getFileContent("Others.txt", es);
    if(result3)
    {

        int i=0;
        for(string & line :es)
        {
            i+=1;
            cout<<i<<"."<<line<<endl;
        }

    }


}

