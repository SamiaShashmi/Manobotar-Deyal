#include<bits/stdc++.h>
enum clothType{Ladies,Gents};
class Cloth
{
    public:
        Cloth();

        float getAmount() { return amount; }
        void getAmount(float val) { amount = val; }

    protected:
        float amount;
        clothType type;
    private:

};
