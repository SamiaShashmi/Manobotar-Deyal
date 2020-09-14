#ifndef BOOK_H
#define BOOK_H
#include"Product.h"
#include<bits/stdc++.h>

class Book:public Product
{
    public:
        Book();
        void uploadProduct(long int id,string name);
        void placeOrder();
        void showBookList();

    protected:

    private:
        Date date;
};

#endif // BOOK_H
