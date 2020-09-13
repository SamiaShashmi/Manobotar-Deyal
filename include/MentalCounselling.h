#ifndef MENTALCOUNSELLING_H
#define MENTALCOUNSELLING_H
#include"Date.h"
#include"Product.h"

class MentalCounselling:public Product
{
    public:
        MentalCounselling();
        void uploadProduct(long int id, string name);
        void placeOrder();
        void displayCounsellorDetails();
        void displayAvailableDates();
        void createAppoinment();
        void setConsultantID(long int id)
        {
            consultantID = id;
        }
        long int getConsultantID()
        {
            return consultantID;
        }
        void setType()
        {
            type = Parmanent;
        }
        int getType()
        {
            return type;
        }
    protected:

    private:
        long int consultantID;
        Date date;
        int dayCountFromJanuary;
};

#endif // MENTALCOUNSELLING_H
