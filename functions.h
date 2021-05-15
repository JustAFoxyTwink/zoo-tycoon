/********************************************************
 * Program Filename: functions.h
 * Author: Evan Garrison
 * Date: 05/14/2021
 * Description: Header file for functions, a collection of
 * misc. functions useful for all classes
 * Input: prompts for input from user
 * Output: input from user, a random name from a list
 ********************************************************/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>

int getInt(std::string prompt);
int getIntBounds(std::string prompt, int a, int b);
std::string getRandName();

#endif