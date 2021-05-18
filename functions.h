/********************************************************
 * Program Filename: functions.h
 * Author: Evan Garrison
 * Date: 05/14/2021
 * Description: Header file for functions, a collection of
 * misc. functions useful for all classes
 * Input: prompts for input from user
 * Output: input from user, a random name from a list
 ********************************************************/

//Being header guard
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//needed header files for functions
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>

/*
 * Declarations for useful functions, more detailed descriptions
 * are available in the implementation file.
 */
int getInt(std::string prompt); //gets int from user
int getIntBounds(std::string prompt, int a, int b); //gets an int between bounds from user
std::string getRandName(); //gets a random name

//End header guard
#endif