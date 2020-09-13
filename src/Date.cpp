#include "Date.h"
#include<bits/stdc++.h>
Date::Date()
{

}

bool  Date::isLeap(int y)
{
    if (y%100 != 0 && y%4 == 0 || y %400 == 0)
        return true;

    return false;
}

int Date::countLeapYears()   //calculate total days from leap year
{
    int years = y;
    if (m <= 2)
        years--;
    return years / 4 - years / 100 + years / 400;
}

void Date::getDifference(Date dt1)
{
    int n1 = dt1.y*365 + dt1.d;   //adds days from year and date
    for (int i=0; i<dt1.m - 1; i++)
        n1 += dt1.monthDays[i];   //adds days from month
    n1 += dt1.countLeapYears();  //adds days of leap year
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

void  Date::addDays(int x)
{
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
    int offset1,offset2;//offset1 is the day count from the first day of that year
    offset1 = dt1.d;
    for (int i=0; i<dt1.m - 1; i++)
        {offset1 += dt1.monthDays[i]; }  //adds days from month
    if (isLeap(dt1.y) && m > 2)
    {offset1 += 1;}
    int remDays = isLeap(dt1.y)?(366-offset1):(365-offset1);
    if (x <= remDays)
    {
        y = dt1.y;
        offset2 = offset1 + x;
    }
    else
    {
        x -= remDays;
        y = dt1.y + 1;
        int y2days = isLeap(y)?366:365;
        while (x >= y2days)
        {
            x -= y2days;
            y++;
            y2days = isLeap(y)?366:365;
        }
        offset2 = x;
    }
    int i;
   for (i = 0; i < 12; i++)
    {
        if(isLeap(dt1.y) && i==1)
        {
            if (offset2 <= 29)
            {break;}
            offset2 = offset2 - 29;
        }

        else
        {
            if (offset2 <= monthDays[i])
            {break;}
            offset2 = offset2 - monthDays[i];
        }
    }
     d = offset2;
     m = i+1;
}

std::ostream& operator<<(std::ostream& os, const Date& dt)
{
    os << dt.d << '-' << dt.m << '-' << dt.y;
    return os;
}
