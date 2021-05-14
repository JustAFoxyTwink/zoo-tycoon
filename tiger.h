#ifndef TIGER_H
#define TIGER_H

#include "animal.h"

class Tiger : public Animal {
    private:
        static const int price = 15000;
        static const int revenue = 1500;
    public:
        Tiger();
        Tiger(std::string n, int a=0);

        int getRevenue() const;
        int getPrice() const;
        void advanceMonth(int &costs, int &rev, const int &bank);
};

#endif