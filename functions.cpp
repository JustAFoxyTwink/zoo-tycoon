/********************************************************
 * Program Filename: functions.cpp
 * Author: Evan Garrison
 * Date: 05/14/2021
 * Description: implementation file for functions
 * Input: prompts for input from user
 * Output: input from user, a random name from a list
 ********************************************************/

#include "functions.h"

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
int getInt(std::string prompt) {
    int input;
    
    do {
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cout << "Invalid input. Please try again.\n";
        }

        std::cout << prompt;
        std::cin >> input;
    } while (std::cin.fail());

    return input;
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
int getIntBounds(std::string prompt, int a, int b) {
    int input;

    do {
        input = getInt(prompt);

        if (input < a || input > b)
            std::cout << "Invalid input. Please try again.\n";
    } while (input < a || input > b);

    return input;
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
std::string getRandName() {
    std::ifstream list("names.txt");
    std::string temp;

    int randInt = (rand() % 255) + 1;

    for (int i = 0; i <= randInt; i++)
        list >> temp;

    list.close();

    return temp;
}