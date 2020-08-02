#ifndef DATE_H
#define DATE_H

class Date
{
    public:
        Date();
        void setDate(int Day,int Month,int Year);
        int countLeapYears();
        void getDifference(Date dt1);
        void setRemainingDay(int Day,int Month,int Year);
        int getReturnWithin()
        {
            return returnWithin;
        }

    protected:

    private:
        int d, m, y;
        int returnWithin;
        const int monthDays[12] = {31, 28, 31, 30, 31, 30,
                           31, 31, 30, 31, 30, 31};

};

#endif // DATE_H
