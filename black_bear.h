/********************************************************
 * Program Filename: black_bear.h
 * Author: Evan Garrison
 * Date: 05/14/2021
 * Description: Header file for BlackBear class
 * Input: Name, age of bear, current costs and bank size
 * Output: Revenue, price of bear
 ********************************************************/

#ifndef BLACK_BEAR_H
#define BLACK_BEAR_H

#include "animal.h"

class BlackBear : public Animal {
    private:
        static const int price = 6000;
        static const int revenue = 600;
    public:
        BlackBear();
        BlackBear(std::string n, int a=0);

        int getRevenue() const;
        int getPrice() const;
        void advanceMonth(int &costs, int &rev, const int &bank);
};

#endif