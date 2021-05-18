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
    age = 0; //set age to 0
}

/********************************************************
 * Function: getAge
 * Description: gets age of animal
 * Parameters: none
 * Pre-Conditions: age hasn't been returned to caller
 * Post-Conditions: caller now has age of the animal question
 ********************************************************/
int Animal::getAge() const {
    return age; //return age to caller
}

/********************************************************
 * Function: setAge
 * Description: sets age of animal
 * Parameters: a - age of animal
 * Pre-Conditions: animals age is nonexistant or outdated
 * Post-Conditions: Animals age has been set
 ********************************************************/
void Animal::setAge(int a) {
    age = a; //set age to a
}

/********************************************************
 * Function: getFoodCost
 * Description: gets the current cost of food for this animal
 * Parameters: none
 * Pre-Conditions: caller doesn't have cost of food
 * Post-Conditions: caller has been given cost of food for animal
 ********************************************************/
int Animal::getFoodCost() const {
    return foodCost; //return cost of food
}

/********************************************************
 * Function: advanceMonth
 * Description: Advances the month, calculates fosts of food
 * and advances age of animal
 * Parameters: &costs - reference to a running tally of costs
 * from all animals in zoo.
 * Pre-Conditions: Animal still has values from previous month
 * Post-Conditions: Costs have been calculated, age of animal
 * has advanced one month.
 ********************************************************/
void Animal::advanceMonth(int &costs) {
    if (!isDead) {
        costs += foodCost; //cost of food has been added to running tally

        double randInt = (rand() % 41) + 80; //a random integer between 80 and 120 is generated
        double percentage = randInt / (double)100; //randInt is converted to a percentage

        foodCost *= percentage; //foodCost for next month is calulated, using percentage generated before

        setAge(age + 1); //advances age by one month
    }
    
}

/********************************************************
 * Function: makeSick
 * Description: makes animal sick
 * Parameters: none
 * Pre-Conditions: Animal is healthy
 * Post-Conditions: Animal is sick
 ********************************************************/
void Animal::makeSick() {
    isSick = true; //sets isSick to true
}

/********************************************************
 * Function: heal
 * Description: heals animal if there is enough money in the
 * bank, kills the animal otherwise
 * Parameters: &costs - reference to running tally of costs,
 * &bank - reference to amount of money in bank,
 * &price - reference to initial price of the animal
 * Pre-Conditions: Animal is sick, needs treatment
 * Post-Conditions: Animal has either been healed and cost of
 * treatment added to costs, or has died.
 ********************************************************/
void Animal::heal(int &costs, const int &bank, const int &price) {

    /*
     * if else block to determine how much it costs to heal the
     * animal, if its a baby, treatment will be the full price of
     * the animal. If its not, treatment costs half as much.
     */
    if (getLifeStage() == BABY) {
        /*
         * if else block to determine if baby lives or dies.
         * if there isn't enough money, it dies.
         */
        if (bank < price)
            costs += price;
        else   
            kill();
    }
    else {
        /*
         * if else block to determine if adult/adolescent lives or dies.
         * if there isn't enough money, it dies.
         */
        if (bank < price / 2)
            costs += price / 2;
        else
            kill();
    }

    isSick = false; //regardless of whether the animal is healed or not, it isn't sick anymore.
}

/********************************************************
 * Function: kill
 * Description: Kills the animal and outputs a message
 * Parameters: none
 * Pre-Conditions: animal is alive
 * Post-Conditions: Animal is dead, and a message is delivered 
 * to the user
 ********************************************************/
void Animal::kill() {
    isDead = true; //sets isDead to true

    std::cout << name << " got sick and died!\n"; //outputs death message with name of animal
}

/********************************************************
 * Function: getSick
 * Description: gets whether or not the animal is sick
 * Parameters: none
 * Pre-Conditions: caller doesn't know whether animal is sick
 * Post-Conditions: caller has been returned isSick
 ********************************************************/
bool Animal::getSick() const {
    return isSick; //returnes isSick to caller
}

/********************************************************
 * Function: getDead
 * Description: gets whether or not animal is dead
 * Parameters: none
 * Pre-Conditions: caller doesn't know if animal is dead
 * Post-Conditions: caller has been told if animal is dead
 ********************************************************/
bool Animal::getDead() const {
    return isDead; //returns isDead to caller
}

/********************************************************
 * Function: getLifeStage
 * Description: gets the current lifestage of the animal
 * Parameters: none
 * Pre-Conditions: caller doesn't know what stage of life
 * the animal is at
 * Post-Conditions: caller has been given animals stage of life
 ********************************************************/
Animal::LifeStage Animal::getLifeStage() const {
    
    /*
     * if the age of the animal is less than 5, it is
     * a baby. If its between 5 and 48, it is an adolescent.
     * if its 48 or older, its an adult
     */
    if (age < 5)
        return BABY;
    else if (age < 48)
        return ADOLESCENT;
    else
        return ADULT;
}

/********************************************************
 * Function: getName
 * Description: gets name of the animal
 * Parameters: none
 * Pre-Conditions: caller doesn't know animal's name
 * Post-Conditions: caller has been given the name of the animal
 ********************************************************/
std::string Animal::getName() const {
    return name; //returns name to caller
}

/********************************************************
 * Function: setName
 * Description: sets name of the animal
 * Parameters: &n - constant reference to the name the animal
 * will be given
 * Pre-Conditions: Animals name is outdated or has not been set
 * Post-Conditions: Animal's name has been set to n
 ********************************************************/
void Animal::setName(const std::string &n) {
    name = n; //assigns value of n to name
}