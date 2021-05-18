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
 * Function: Lemur Constructor
 * Description: Constructor for Lemur class
 * Parameters: n - name of lemur, a - age of lemur
 * Pre-Conditions: Lemur has not been created
 * Post-Conditions: Lemur has been created with name n and age a
 ********************************************************/
Lemur::Lemur(std::string n, int a) : Animal(n, a) {
}

/********************************************************
 * Function: Lemur default Constructor
 * Description: Default Constructor for Lemur class
 * Parameters: none
 * Pre-Conditions: Lemur has not been created
 * Post-Conditions: Lemur is created with no name, age 0
 ********************************************************/
Lemur::Lemur() {
}

/********************************************************
 * Function: getRevenue
 * Description: gets revenue generated by lemurs
 * Parameters: none
 * Pre-Conditions: caller doesn't have revenue generated
 * Post-Conditions: caller has been given revenue value
 ********************************************************/
int Lemur::getRevenue() const {
    return revenue; //returns revenue to compiler
}

/********************************************************
 * Function: getPrice
 * Description: gets price of Lemur
 * Parameters: none
 * Pre-Conditions: caller doesn't have price of lemur
 * Post-Conditions: caller has been give price
 ********************************************************/
int Lemur::getPrice() const {
    return price; //returns price
}

/********************************************************
 * Function: advanceMonth
 * Description: advances month for Lemur, calculates cost and revenue generated,
 * heals/kills is sick.
 * Parameters: &costs - reference to running cost, &rev - reference to
 * running revenue, &bank - const reference to money in bank
 * Pre-Conditions: Lemur still has values and conditions from  last month
 * Post-Conditions: Lemurs condition has been advanced, revenue and cost
 * has been added to running tally
 ********************************************************/
void Lemur::advanceMonth(int &costs, int &rev, const int &bank) {
    Animal::advanceMonth(costs); //calls base function for advancing month

    if (getSick()) //if the animals sick, heal/kill it
        heal(costs, bank, getPrice());

    /*
     * If the animal isn't dead, this calculated revenue generated and adds it to the
     * to the running revenue. revenue generated for babies is double the normal.
     */
    if (!getDead()) {
        if (getLifeStage() == BABY)
            rev += getRevenue() * 2;
        else
            rev += getRevenue();
    }
}