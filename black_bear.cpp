/********************************************************
 * Program Filename: black_bear.cpp
 * Author: Evan Garrison
 * Date: 05/14/2021
 * Description: BlackBear class implementation file
 * Input: BlackBear name, class, bank size
 * Output: BlackBear status, price, revenue generated.
 ********************************************************/

#include "black_bear.h"

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
BlackBear::BlackBear(std::string n, int a) : Animal(n, a) {
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
BlackBear::BlackBear() {
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
int BlackBear::getRevenue() const {
    return revenue;
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
int BlackBear::getPrice() const {
    return price;
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
void BlackBear::advanceMonth(int &costs, int &rev, const int &bank) {
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