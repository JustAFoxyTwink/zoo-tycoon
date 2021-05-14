#ifndef LEMUR_H
#define LEMUR_H

#include "animal.h"

class Lemur : public Animal {
    private:
        static const int price = 700;
        static const int revenue = 140;
    public:
        Lemur();
        Lemur& operator=(const Lemur &source);
        Lemur(std::string n, int a=0);

        int getRevenue() const;
        int getPrice() const;
        void advanceMonth(int &costs, int &rev, const int &bank);
};

#endif