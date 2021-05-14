#include "black_bear.h"

BlackBear::BlackBear(std::string n, int a) : Animal(n, a) {
    
}

BlackBear::BlackBear() {
    
}

int BlackBear::getRevenue() const {
    return revenue;
}

int BlackBear::getPrice() const {
    return price;
}

void BlackBear::advanceMonth(int &costs, int &rev, const int &bank) {
    Animal::advanceMonth(costs);

    bool isSick;
    bool isDead;
    checkHealth(isSick, isDead);

    if (isSick)
        heal(costs, bank, getPrice());

    if (!isDead)
        rev = getRevenue();
}