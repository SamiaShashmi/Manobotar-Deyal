#include"Product.h"
#include"Donor.h"
#ifndef MONEY_H
#define MONEY_H


class Money:public Product
{
    public:
        Money();
        void uploadProduct();
        static double stTotalAmount;
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
        void displayTotalAmount();

    protected:

    private:
        double amount;
        double totalAmount;
        int returnWithin;

};

#endif // MONEY_H
