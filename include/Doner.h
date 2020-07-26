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
        void signIn();
        void Doner_StoreInFile();
        void Doner_ProfileDisplay();
        void Show();
        void Doner_DisplayAll();
        void Menu();
        void submenu();
        /*static long int getDonerID()
        {
            return DonerID;
        }*/
    protected:

    private:

};

#endif // DONER_H
