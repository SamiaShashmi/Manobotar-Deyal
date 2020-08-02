#include "Product.h"
#include"Date.h"
#include<iostream>
using namespace std;
Product::Product()
{
    //ctor
}
void Product::uploadProduct()
{

}
int Product::countLeapYears(Date d)
{
    int years = d.y;
    if (d.m <= 2)
        years--;
    return years / 4 - years / 100 + years / 400;
}
int Product::getDifference(Date dt1, Date dt2)
{
    int n1 = dt1.y*365 + dt1.d;
    for (int i=0; i<dt1.m - 1; i++)
        n1 += dt1.monthDays[i];
    n1 += countLeapYears(dt1);
    int n2 = dt2.y*365 + dt2.d;
    for (int i=0; i<dt2.m - 1; i++)
        n2 += dt1.monthDays[i];
    n2 += countLeapYears(dt2);
    return (n2 - n1);
}

void Product::setRemainingDay(int Day,int Month,int Year)
        {
            date.d=Day;
            date.m=Month;
            date.y=Year;
            time_t now;
            struct tm nowlocal;
            now = time(NULL);
            nowlocal = *localtime(&now);
            struct currentDate
            {
                int dt, mnth, yr;
            };
            currentDate cdt= {nowlocal.tm_mday, nowlocal.tm_mon+1, nowlocal.tm_year+1900};
            Date dt1;
            dt1.d = cdt.dt;
            dt1.m = cdt.mnth;
            dt1.y = cdt.yr;
            returnWithin = getDifference(dt1,date);
        }
