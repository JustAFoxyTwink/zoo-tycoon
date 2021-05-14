#include "lemur.h"

Lemur::Lemur(std::string n, int a) : Animal(n, a) {
}

Lemur& Lemur::operator=(const Lemur &source) {
    *this = source;

    return *this;
}

int Lemur::getRevenue() const {
    return revenue;
}

int Lemur::getPrice() const {
    return price;
}

void Lemur::advanceMonth(int &costs, int &rev, const int &bank) {
    Animal::advanceMonth(costs);

    bool isSick;
    bool isDead;
    checkHealth(isSick, isDead);

    if (isSick)
        heal(costs, bank, getPrice());

    if (!isDead)
        if (getLifeStage() == BABY)
            rev = getRevenue() * 2;
        else
            rev = getRevenue();
}