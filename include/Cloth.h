#include<bits/stdc++.h>
#include"Product.h"
enum clothType{Ladies,Gents};
class Cloth:public Product
{
    public:
        Cloth();
        static int stLadiesCount;
        static int stGentsCount;
        static long int stProductID;
        void uploadProduct();
        void storeTotalClothIntoFile(clothType t,int am);
        int getTotalClothFromFile(clothType,int);
        clothType getType()
        {
            return type;
        }
        void setType(clothType c)
        {
            type=c;
        }
        int getAmount() { return amount; }
        void setAmount(float val) { amount = val; }

    protected:

    private:
        int amount;
        clothType type;
        map<clothType,int>totalCloth;
};
