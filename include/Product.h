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
        virtual void uploadProduct();
        int countLeapYears(Date d);
        int getDifference(Date dt1, Date dt2);
    protected:
        Product_Type type;
        int remainingDay;
        struct Date
        {
            int d, m, y;
        };
    private:

};

#endif // PRODUCT_H
