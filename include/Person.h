#ifndef PERSON_H
#define PERSON_H
#include<bits/stdc++.h>
using namespace std;
void startMenu();
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
    virtual void signUp(int personCount);
    void displayProfile();
    virtual void submenu()=0;
    void productMenu();
protected:

    long int ID;
    string name;
    int age;
    string email;
    string password;
private:

};

#endif // PERSON_H
