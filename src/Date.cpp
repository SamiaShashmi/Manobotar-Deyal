#include "Date.h"

Date::Date(int date,int month,int year)
{
    d = date;
    m = month;
    y = year;
}

int Date::countLeapYears(Date d)
{
    int years = d.y;

    // Check if the current year needs to be considered
    // for the count of leap years or not
    if (d.m <= 2)
        years--;

    // An year is a leap year if it is a multiple of 4,
    // multiple of 400 and not a multiple of 100.
    return years / 4 - years / 100 + years / 400;
}
