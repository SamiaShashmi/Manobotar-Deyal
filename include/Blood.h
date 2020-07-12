#ifndef BLOOD_H
#define BLOOD_H


class Blood
{
    public:
        Blood();

        string GetGroup() { return Group; }
        void SetGroup(string val) { Group = val; }

    protected:
        string Group;
        int Num_Bag;
    private:

};

#endif // BLOOD_H
