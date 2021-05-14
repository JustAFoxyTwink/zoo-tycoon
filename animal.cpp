#include "animal.h"

Animal::Animal(std::string n, int a) {
    setAge(a);
    name = n;
}

Animal& Animal::operator=(const Animal& source) {
    if (this == &source)
        return *this;
    
    age = source.getAge();
    foodCost = source.getFoodCost();
    source.checkHealth(isSick, isDead);
    name = source.getName();

    return *this;
}

int Animal::getAge() const {
    return age;
}

void Animal::setAge(int a) {
    age = a;
}

int Animal::getFoodCost() const {
    return foodCost;
}

void Animal::advanceMonth(int &costs) {
    if (!isDead) {
        costs += foodCost;

        double randInt = (rand() % 41) + 80;
        double percentage = randInt / (double)100;

        foodCost *= percentage;

        setAge(age + 1);
    }
    
}

void Animal::makeSick() {
    isSick = true;
}

void Animal::heal(int &costs, const int &bank, const int &price) {
    if (getLifeStage() == LifeStage::BABY) {
        if (bank < price)
            costs += price;
        else   
            kill();
    }
    else {
        if (bank < price / 2)
            costs += price / 2;
        else
            kill();
    }

    isSick = false;
}

void Animal::kill() {
    isDead = true;
}

void Animal::checkHealth(bool &sick, bool &dead) const {
    sick = isSick;
    dead = isDead;
}

Animal::LifeStage Animal::getLifeStage() const {
    if (age < 5)
        return Animal::LifeStage::BABY;
    else if (age < 48)
        return Animal::LifeStage::ADOLESCENT;
    else
        return Animal::LifeStage::ADULT;
}

std::string Animal::getName() const {
    return name;
}

void Animal::setName(const std::string &n) {
    name = n;
}