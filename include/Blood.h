#include<bits/stdc++.h>
#ifndef BLOOD_H
#define BLOOD_H
#include"Product.h"
#include"Donor.h"
using namespace std;
enum bloodGroup{A_positive,A_negative,B_positive,B_negative,O_positive,O_negative,AB_positive,AB_negative};

class Blood:public Product
{
    public:
        Blood();

        bloodGroup getGroup() { return Group; }
        void uploadProduct(long int id,string name);
        void placeOrder();
        void showBagList();
        void setGroup(bloodGroup val) { Group = val; }
        void storeBagNoIntoFile(bloodGroup,int);
        int getBagNoFromFile(bloodGroup);
        int checkBagNoFromFile(bloodGroup,int);
        int getNumBag()
        {
            return numBag;
        }
        void setNumBag(int bag)
        {
            numBag=bag;
        }
        void setType()
        {
            type = Parmanent;
        }
        int getType()
        {
            return type;
        }
    private:
        bloodGroup Group;
        int numBag;
        map<bloodGroup,int>totalBag;
        static int stTotalBagApos;
        static int stTotalBagAneg;
        static int stTotalBagBpos;
        static int stTotalBagBneg;
        static int stTotalBagABpos;
        static int stTotalBagABneg;
        static int stTotalBagOpos;
        static int stTotalBagOneg;
        static long int stProductID;

};

#endif // BLOOD_H
