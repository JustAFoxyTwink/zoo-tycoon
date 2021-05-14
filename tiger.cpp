#include "tiger.h"

Tiger::Tiger(std::string n, int a) : Animal(n, a) {
}

int Tiger::getRevenue() const {
    return revenue;
}

int Tiger::getPrice() const {
    return price;
}

void Tiger::advanceMonth(int &costs, int &rev, const int &bank) {
    Animal::advanceMonth(costs);

    bool isSick;
    bool isDead;
    checkHealth(isSick, isDead);

    if (isSick)
        heal(costs, bank, getPrice());

    if (!isDead)
        rev = getRevenue();
}