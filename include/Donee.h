#ifndef DONEE_H
#define DONEE_H
#include"Person.h"

class Donee:public Person
{
    public:
        Donee();
        static long int stDoneeID;
        void signIn();
        void displayProfile();
        void Menu();
        void submenu();
        void placeOrder();
        void setDoneeID(int ID)
        {
            doneeID=ID;
        }
        long int getDoneeID()
        {
            return doneeID;
        }
    protected:

    private:
        long int doneeID;

};

#endif // DONEE_H
