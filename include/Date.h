#ifndef DATE_H
#define DATE_H
#include"Person.h"

class Date
{
    public:
        Date();
        friend void setDate(int Day,int Month,int Year);
        friend int countLeapYears(Date d);
        friend int getDifference(Date dt1, Date dt2);
        friend void setRemainingDay(int Day,int Month,int Year);
         int d, m, y;
        const int monthDays[12] = {31, 28, 31, 30, 31, 30,
                           31, 31, 30, 31, 30, 31};

    protected:

    private:


};

#endif // DATE_H
