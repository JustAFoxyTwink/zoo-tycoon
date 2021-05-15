/********************************************************
 * Program Filename: tiger.cpp
 * Author: Evan Garrison
 * Date: 05/14/2021
 * Description: Tiger class implementation file
 * Input: Tiger name, class, bank size
 * Output: Tiger status, price, revenue generated.
 ********************************************************/

#include "tiger.h"

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
Tiger::Tiger(std::string n, int a) : Animal(n, a) {
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
Tiger::Tiger() {
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
int Tiger::getRevenue() const {
    return revenue;
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
int Tiger::getPrice() const {
    return price;
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
void Tiger::advanceMonth(int &costs, int &rev, const int &bank) {
    Animal::advanceMonth(costs);

    if (getSick())
        heal(costs, bank, getPrice());

    if (!getDead()) {
        if (getLifeStage() == BABY)
            rev = getRevenue() * 2;
        else
            rev = getRevenue();
    }
}