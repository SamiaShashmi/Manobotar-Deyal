#ifndef PRODUCT_H
#define PRODUCT_H
#include<bits/stdc++.h>
#include"Date.h"
enum Product_Type{Parmanent,Temporary};
class Product
{
    public:
        Product();
        virtual void uploadProduct();
        void setDate(int Day,int Month,int Year)
        {
            date.d=Day;
            date.m=Month;
            date.y=Year;
        }
        Date getDate()
        {
            return date;
        }
        int countLeapYears(Date d);
        int getDifference(Date dt1, Date dt2);
        void setRemainingDay(int Day,int Month,int Year);
    protected:
        Product_Type type;
        long int productID;
        int returnWithin;
        Date date;
    private:

};

#endif // PRODUCT_H
