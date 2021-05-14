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