/********************************************************
 * Program Filename: zoo_tycoon.cpp
 * Author: Evan Garrison
 * Date: 05/14/2021
 * Description: Driver file for Zoo Tycoon program.
 * Input: Takes input from user on which animals to buy,
 * on whether to buy.
 * Output: Outputs current status of Zoo, list of animals,
 * revenue, costs, and bank size.
 ********************************************************/

#include <iostream>

#include "zoo.h"
#include "functions.h"

using namespace std;

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
int main() {

    srand(time(NULL));

    cout << "Welcome to Zoo Tycoon! You currenly have 0 animals, and $100000 in the bank.\n\n";
    Zoo* zoo = new Zoo();
    zoo->showAnimals();

    string prompt1 = "Would you like to buy an animal this month?\n1\tLemurs\n2\tTigers\n3\tBlack Bears\n4\tNone\n";
    string prompt2 = "Would you like to buy 1 or 2?\n";
    
    do {
        int temp = getIntBounds(prompt1, 1, 4);

        switch (temp) {
            case 1:
                temp = getIntBounds(prompt2, 1, 2);
                zoo->addLemurs(temp, 48);
                break;
            case 2:
                temp = getIntBounds(prompt2, 1, 2);
                zoo->addTigers(temp, 48);
                break;
            case 3:
                temp = getIntBounds(prompt2, 1, 2);
                zoo->addBBears(temp, 48);
                break;
            case 4:
            default:
                cout << "no animals were purchased this month.\n";
        }
        zoo->advanceMonth();
        zoo->showAnimals();
    } while (zoo->getMoney() > 0);

    delete zoo;
    return 0;
}