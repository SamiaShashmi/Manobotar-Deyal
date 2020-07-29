#ifndef DATE_H
#define DATE_H


class Date
{
    public:
        Date(int date,int month,int year);
        int countLeapYears(Date d);
        friend int countLeapYears(Date);
    protected:

    private:
        int d, m, y;
        const int monthDays[12] = {31, 28, 31, 30, 31, 30,
                           31, 31, 30, 31, 30, 31};
};

#endif // DATE_H
