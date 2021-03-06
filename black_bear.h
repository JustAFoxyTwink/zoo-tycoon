/********************************************************
 * Program Filename: black_bear.h
 * Author: Evan Garrison
 * Date: 05/14/2021
 * Description: Header file for BlackBear class
 * Input: Name, age of bear, current costs and bank size
 * Output: Revenue, price of bear
 ********************************************************/

//Begin header guard
#ifndef BLACK_BEAR_H
#define BLACK_BEAR_H

//includes base class
#include "animal.h"

/*
 * BlackBear class declaration.
 * This class inherits members from its base class, Animal.
 * It has members used to manipulate the more specific components of the BlackBear class
 */
class BlackBear : public Animal {
    //private members
    private:
        static const int price = 6000; //price of 1 bear
        static const int revenue = 600; //revenue generated by 1 bear
    
    //public members
    public:
        BlackBear(); //default constructor
        BlackBear(std::string n, int a=0); //Constructor with user-defined parameters

        /*
         * Public member functions(methods) for BlackBear class.
         * a detailed description of each function is given in the implementation file
         */
        int getRevenue() const; //gets revenue
        int getPrice() const; //gets price
        void advanceMonth(int &costs, int &rev, const int &bank); //advances month, adds costs and revenue
};

//End header guard
#endif