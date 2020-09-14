#ifndef PRODUCT_H
#define PRODUCT_H
#include<bits/stdc++.h>
#include"Date.h"
using namespace std;
enum Product_Type{Parmanent,Temporary};
class Product
{
    public:
        Product();
        virtual void uploadProduct(long int id,string name)=0;
        virtual void placeOrder()=0;
    protected:
        Product_Type type;
        long int productID;
        static long int stProductID;
    private:

};

#endif // PRODUCT_H
