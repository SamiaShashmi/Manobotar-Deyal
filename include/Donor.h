#ifndef DONER_H
#define DONER_H
#include "Person.h"
void startMenu();

class Donor:public Person
{
    public:
        Donor();
        static long int stDonorID;
        void signIn();
        void Donor_StoreInFile();
        void displayProfile();
        void Donor_DisplayAll();
        void Menu();
        void submenu();
        void productMenu();
        void setDonorID(int ID)
        {
            donorID=ID;
        }
        long int getDonorID()
        {
            return donorID;
        }
    protected:

    private:
        long int donorID;
};

#endif // DONER_H
