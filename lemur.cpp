/********************************************************
 * Program Filename: lemur.cpp
 * Author: Evan Garrison
 * Date: 05/14/2021
 * Description: Lemur class implementation file
 * Input: Lemur name, class, bank size
 * Output: Lemur status, price, revenue generated.
 ********************************************************/

#include "lemur.h"

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
Lemur::Lemur(std::string n, int a) : Animal(n, a) {
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
Lemur::Lemur() {
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
int Lemur::getRevenue() const {
    return revenue;
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
int Lemur::getPrice() const {
    return price;
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
void Lemur::advanceMonth(int &costs, int &rev, const int &bank) {
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