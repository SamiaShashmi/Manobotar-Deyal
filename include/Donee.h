#ifndef DONEE_H
#define DONEE_H
#include"Person.h"

class Donee:public Person
{
    public:
        Donee();
        static long int stDoneeID;
        void signIn();
        void Donee_StoreInFile();
        void displayProfile();
        void Donee_DisplayAll();
        void Menu();
        void submenu();
        void productMenu();
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
