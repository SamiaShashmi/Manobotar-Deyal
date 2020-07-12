#ifndef CLOTH_H
#define CLOTH_H

enum Cloth_Type{Ladies,Gents}
class Cloth
{
    public:
        Cloth();

        float Getamount() { return amount; }
        void Setamount(float val) { amount = val; }

    protected:
        float amount;
        Cloth_Type type;
    private:

};

#endif // CLOTH_H
