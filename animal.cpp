/********************************************************
 * Program Filename: animal.cpp
 * Author: Evan Garrison
 * Date: 05/14/2021
 * Description: Implementation file for Animal Class
 * Input: Animal age, name, cost
 * Output: Current animal status, name, whether its sick or dead,
 * cost of food for animal, and lifestage.
 ********************************************************/

#include "animal.h" //include header file

/********************************************************
 * Function:Animal Constructor
 * Description:Creates a new animal with name n and age a
 * Parameters: n - animal name, a - animal age
 * Pre-Conditions: Animals age and name haven't been set
 * Post-Conditions: A new Animal has been created with age a
 * and name n
 ********************************************************/
Animal::Animal(std::string n, int a) {
    setAge(a); //set age to a
    name = n; //set name to n
}

/********************************************************
 * Function:Default animal constructor
 * Description:Creates a new animal with no name, age 0
 * Parameters: none
 * Pre-Conditions: Animal hasn't been created
 * Post-Conditions: A new animal with no name and age of 0
 * has been created.
 ********************************************************/
Animal::Animal() {
    age = 0;
}

/********************************************************
 * Function: getAge
 * Description: gets age of animal
 * Parameters: none
 * Pre-Conditions: age hasn't been returned to caller
 * Post-Conditions: caller now has age of the animal question
 ********************************************************/
int Animal::getAge() const {
    return age;
}

/********************************************************
 * Function: setAge
 * Description: sets age of animal
 * Parameters: a - age of animal
 * Pre-Conditions: animals age is nonexistant or outdated
 * Post-Conditions: Animals age has been set
 ********************************************************/
void Animal::setAge(int a) {
    age = a;
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
int Animal::getFoodCost() const {
    return foodCost;
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
void Animal::advanceMonth(int &costs) {
    if (!isDead) {
        costs += foodCost;

        double randInt = (rand() % 41) + 80;
        double percentage = randInt / (double)100;

        foodCost *= percentage;

        setAge(age + 1);
    }
    
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
void Animal::makeSick() {
    isSick = true;
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
void Animal::heal(int &costs, const int &bank, const int &price) {
    if (getLifeStage() == BABY) {
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

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
void Animal::kill() {
    isDead = true;

    std::cout << name << " got sick and died!\n";
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
bool Animal::getSick() const {
    return isSick;
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
bool Animal::getDead() const {
    return isDead;
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
Animal::LifeStage Animal::getLifeStage() const {
    if (age < 5)
        return BABY;
    else if (age < 48)
        return ADOLESCENT;
    else
        return ADULT;
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
std::string Animal::getName() const {
    return name;
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
void Animal::setName(const std::string &n) {
    name = n;
}