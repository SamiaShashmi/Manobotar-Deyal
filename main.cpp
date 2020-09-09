#include <bits/stdc++.h>
#include<conio.h>
#include"Person.h"
#include"Donor.h"
#include"Donee.h"
#include<iostream>
#include<thread>
#include<chrono>
#include<windows.h>

using namespace std;


using std::this_thread::sleep_for;
using std::chrono::milliseconds;
using std::chrono::seconds;


void print(const string&,unsigned int);
unordered_map<int,long int>id_count;
void print(const string& messege, unsigned int mil)

{
    for(const char c:messege)
    {
        cout<< c << flush;
        sleep_for(milliseconds(mil));
    }
}

void gotoxy(int x,int y)
{
    COORD c;
    c.X =x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

long long int getCount()
{
    ifstream fmn;
    int count;
    fmn.open("personCount.txt");
    if(!fmn)
    {
        return 0;
    }
    else
    {
        while (fmn)
        {
            fmn>>count;
            return count;
        }
    }
}


void updateCount(int count)
{
    ofstream fout;
    fout.open("personCount.txt");
    fout << count << endl;
    fout.close();
}

void Menu(int donorOrDonee)
{
    Person* person[100000];
    int personCount;
    system("cls");
    cout<<"\n\n1. Sign up :"<<endl;
    cout<<"2. Log in :"<<endl;
    fflush(stdin);
    int signOrLogInchoice;
    cin>>signOrLogInchoice;
    if(signOrLogInchoice==1)
    {
        if(donorOrDonee == 1)
        {
            personCount = getCount();
            cout<<personCount;
            person[personCount] = new Donor;
            personCount++;
            updateCount(personCount);
            person[personCount-1]->signUp(personCount-1);
        }
        else if(donorOrDonee == 2)
        {
            personCount = getCount();
            person[personCount] = new Donee;
            personCount++;
            updateCount(personCount);
            person[personCount-1]->signUp(personCount-1);
        }
    }
    else if(signOrLogInchoice==2)
    {
        // logIn();
        long int id;
        int count;
        cout<<"Enter ID : ";
        cin>>id;
        /*unordered_map<int,long int>::iterator itr;
        for (itr = id_count.begin(); itr != id_count.end(); itr++)
            {
                if (itr->second == id)
                {
                      count = itr->first;
                      break;
                }
            }
            cout<<itr->first<<" "<<itr->second; */
        ifstream fin;
        fin.open("id_count.txt");
        long int idCheck;
        if(!fin)
        {
            cout << "Sorry,no account is available.\n";
            startMenu();
        }
        while(!fin.eof())
        {
            fin >> idCheck >> count;
            if(idCheck == id)
            {
                break;
            }
        }
        string pass,passCheck;
        char ch;
        if(donorOrDonee == 1)
        {
            ifstream fmn;
            fmn.open("donorPassword.txt");
            while(!fmn.eof())
            {
                fmn >> idCheck >> passCheck;
                if(idCheck == id)
                {
                    break;
                }
            }

            cout<<"Enter password : ";
            ch = _getch(); //* will be shown without character
            while(ch != 13) //character 13 is enter
            {
                pass.push_back(ch);
                cout << '*';
                ch = _getch();
            }
            if(pass==passCheck)
            {
                system("cls");
                cout<<"Login successful...\n\n\n";
                Donor d;
                d.submenu();
            }
            else if(pass!=passCheck)
            {
                cout<<"\n\nWrong password!!!";
                sleep_for(seconds(3));
                Menu(donorOrDonee);
            }
        }
        else if(donorOrDonee == 2)
        {
            ifstream fmn;
            fmn.open("doneePassword.txt");
            while(!fmn.eof())
            {
                fmn >> idCheck >> passCheck;
                if(idCheck == id)
                {
                    break;
                }
            }

            cout<<"Enter password : ";
            ch = _getch(); //* will be shown without character
            while(ch != 13) //character 13 is enter
            {
                pass.push_back(ch);
                cout << '*';
                ch = _getch();
            }
            if(pass==passCheck)
            {
                system("cls");
                cout<<"Login successful...\n";
                Donee d;
                d.submenu();
            }
            else if(pass!=passCheck)
            {
                cout<<"\n\nWrong password!!!";
                Menu(donorOrDonee);
            }
        }

    }
}

void startMenu()
{
    char donorOrDoneeChoice;
    system("color b");
    system("cls");
    gotoxy(60,10);
    cout<<"  Welcome to MANOBOTAR DEYAL  "<<endl;
    gotoxy(65,15);
    cout<<"Enter as :"<<endl;
    gotoxy(66,17);
    cout<<"a.Donor"<<endl;
    gotoxy(66,18);
    cout<<"b.Donee"<<endl;
    gotoxy(65,22);
    cout<<"Enter your choice :";
    cin>>donorOrDoneeChoice;
    if(donorOrDoneeChoice=='a')
    {
        Menu(1);
    }
    else
    {
        Menu(2);
    }
}

int main()
{

    string messege = " We cannot despair of humanity, since we ourselves are human beings. Albert Einstein.  ...";
    system("color F0");
    //gotoxy(40,10);
    //print(messege,140);
//     Person person;
    char c;

    while(true)
    {
        startMenu();
        c=getch();
        if (c==27)
            break;

    }

}



