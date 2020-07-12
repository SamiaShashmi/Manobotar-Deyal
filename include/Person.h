#ifndef PERSON_H
#define PERSON_H
#include<bits/stdc++.h>
using namespace std;

class Person
{
public:
    Person();
    void setAge(int Age)
    {
        age=Age;
    }
    int getAge()
    {
        return age;
    }
    void setName(string Name)
    {
        name=Name;
    }
  string getName()
    {
        return name;
    }
     void setEmail(string em)
    {
        email=em;
    }
    string getEmail()
    {
        return email;
    }
     void setPassword(string pass)
    {
        password=pass;
    }
    string getPassword()
    {
        return password;
    }
    friend void startMenu();
    void display();
protected:

    string name;
    int age;
    string email;
    string password;
private:

};

#endif // PERSON_H
