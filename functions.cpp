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
 * Function: getInt
 * Description: gets an integer from user
 * Parameters: prompt - Prompt for input from user
 * Pre-Conditions: user hasn't been prompted
 * Post-Conditions: user is prompted, and inputs an integer
 * which is checked for validity
 ********************************************************/
int getInt(std::string prompt) {
    int input; //int to store input
    
    /*
     * Do while loop for checking validity of the inputted value.
     * runs until cin.fail() is false.
     */
    do {
        if (std::cin.fail()) {
            std::cin.clear(); //clear cin
            std::cin.ignore(256, '\n'); //ignore
            std::cout << "Invalid input. Please try again.\n"; //output error message
        }

        std::cout << prompt; //output promp
        std::cin >> input; //store input
    } while (std::cin.fail());

    return input; //return input to caller
}

/********************************************************
 * Function: getIntBounds
 * Description: gets an integer from the user within bounds
 * a and b
 * Parameters: prompt - prompt for the user, a - lowerbound,
 * b - upperbound
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
int getIntBounds(std::string prompt, int a, int b) {
    int input; //int to store input

    /*
     * do while loop for checking validity of the inputted value.
     * runs until the input is within bounds of a and b
     */
    do {
        input = getInt(prompt); //gets an int from user

        if (input < a || input > b) //checks if input is within bounds
            std::cout << "Invalid input. Please try again.\n"; //outputs error message
    } while (input < a || input > b);

    return input; //returns input to caller
}

/********************************************************
 * Function: getRandName
 * Description: gets a random name from the list of 255 names in
 * 'names.txt'.
 * Parameters: none
 * Pre-Conditions: No name has been received by caller
 * Post-Conditions: The caller has a random name
 ********************************************************/
std::string getRandName() {
    std::ifstream list("names.txt"); //creates an input file stream, opens 'names.txt'
    std::string temp; //string to store name

    int randInt = (rand() % 255) + 1; //gets a random integer between 1 and 255, stores it

    for (int i = 0; i <= randInt; i++) //this loop runs until i reaches randInt.
        list >> temp; //in each iteration, temp is replaced with the next line from list

    list.close(); //closes list

    return temp; //returns name
}