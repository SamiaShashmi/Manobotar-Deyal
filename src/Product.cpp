#include "Product.h"
#include"Date.h"
#include<iostream>
using namespace std;
Product::Product()
{
    //ctor
}
void Product::setRemainingDay(int Day,int Month,int Year)
{
    date.setRemainingDay(Day,Month,Year);
}
void Product::placeOrder()
{

}

