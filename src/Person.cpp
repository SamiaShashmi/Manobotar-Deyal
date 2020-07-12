#include "Person.h"
#include<bits/stdc++.h>
#include"Doner.h"
using namespace std;

Person::Person()
{
    //ctor
}

void Person::display()
    {
        cout<<"Name : "<<getName()<<endl;
        cout<<"Age : "<<getAge()<<endl;
        cout<<"Email : "<<getEmail()<<endl;
    }



