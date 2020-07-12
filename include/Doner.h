#ifndef DONER_H
#define DONER_H
#include "Person.h"
#include"Functions.h"

class Doner:public Person
{
    public:
        Doner();
        static long int stDonerID;
        long int DonerID;
        void Doner_Signin();
        void Doner_StoreInFile();
        void Doner_ProfileDisplay();
        void Doner_Show();
        void Doner_DisplayAll();
        void DonerMenu();
        void DonerView();
        friend void startMenu();
        /*static long int getDonerID()
        {
            return DonerID;
        }*/
    protected:

    private:

};

#endif // DONER_H
