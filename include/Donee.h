#ifndef DONEE_H
#define DONEE_H
#include"Person.h"

class Donee:public Person
{
    public:
        Donee();
        static long int stDoneeID;
        void signUp(int personCount);
        void storeInFile();
        void displayProfile();
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

};

#endif // DONEE_H
