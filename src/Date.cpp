#include "Date.h"
#include<bits/stdc++.h>
Date::Date()
{

}

int Date::countLeapYears()
{
    int years = y;
    if (m <= 2)
        years--;
    return years / 4 - years / 100 + years / 400;
}

void Date::getDifference(Date dt1)
{
    int n1 = dt1.y*365 + dt1.d;
    for (int i=0; i<dt1.m - 1; i++)
        n1 += dt1.monthDays[i];
    n1 += dt1.countLeapYears();
    int n2 = y*365 + d;
    for (int i=0; i<m - 1; i++)
        n2 += dt1.monthDays[i];
    n2 += countLeapYears();
    returnWithin = n2 - n1;
}

void Date::setRemainingDay(int Day,int Month,int Year)
        {
            d=Day;
            m=Month;
            y=Year;
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
            getDifference(dt1);
        }

