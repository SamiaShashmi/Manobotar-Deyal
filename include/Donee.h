#ifndef DONEE_H
#define DONEE_H
#include"Person.h"

class Donee:public Person
{
    public:
        Donee();
        void signUp(int personCount);
        void storeInFile();
        void displayProfile();
        void displayProduct();
        void submenu();
        void placeOrder();
        void viewDoneeList();
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
        static long int stDoneeID;
};

#endif // DONEE_H
