#ifndef DONER_H
#define DONER_H
#include "Person.h"
void startMenu();

class Donor:public Person
{
    public:
        Donor();
        void signUp(int personCount);
        void storeInFile();
        void displayProfile();
        void viewDonorList();
        void submenu();
        void uploadProduct();
        void setDonorID(long int ID)
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
        static long int stDonorID;
};

#endif // DONER_H
