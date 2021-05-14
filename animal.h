#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <stdlib.h>
#include <string>

class Animal {
    private:
        int age;
        int foodCost = 80;
        bool isSick;
        bool isDead;
        std::string name;
    public:

    enum LifeStage {
        BABY,
        ADOLESCENT,
        ADULT
    };

    Animal(std::string n, int a=0);
    Animal();

    int getAge() const;
    void setAge(int a);
    int getFoodCost() const;
    void advanceMonth(int &costs);
    void makeSick();
    void heal(int &costs, const int &bank, const int &price);
    void kill(); //there's a fun name!
    void checkHealth(bool &sick, bool &dead) const;
    LifeStage getLifeStage() const;
    std::string getName() const;
    void setName(const std::string &n);
};

#endif