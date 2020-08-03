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
        void logIn();
        int matchPassword(long int id,string pass);
        void storeInFile();
        void displayProfile();
        void viewDonorList();
        void Menu();
        void submenu();
        void uploadProduct();
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
