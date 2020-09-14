#include"Product.h"
#include"Donor.h"
#ifndef MONEY_H
#define MONEY_H


class Money:public Product
{
    public:
        Money();
        void uploadProduct(long int id,string name);
        void placeOrder();
        void setAmount(int Amount)
        {
            amount = Amount;
        }
        double getAmount()
        {
            return amount;
        }
        double getTotalAmount()
        {
            return totalAmount;
        }
        void setType()
        {
            type = Temporary;
        }
        int getType()
        {
            return type;
        }
        void displayTotalAmount();
    protected:

    private:
        double amount;
        double totalAmount;
        static double stTotalAmount;
        static long int stProductID;
        Date date;
};

#endif // MONEY_H
