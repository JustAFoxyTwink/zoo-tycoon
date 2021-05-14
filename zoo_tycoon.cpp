#include <iostream>

#include "zoo.h"
#include "functions.h"

using namespace std;

int main() {

    srand(time(NULL));

    cout << "Welcome to Zoo Tycoon! You currenly have 0 animals, and $100000 in the bank.\n\n";
    Zoo* zoo = new Zoo();
    zoo->showAnimals();
    delete zoo;
    return 0;
}