/********************************************************
 * Program Filename: animal.h
 * Author: Evan Garrison
 * Date: 05/14/2021
 * Description: Header file for Animal class
 * Input: animal age, name
 * Output: status of animal, revenue generated, costs of food
 * and medical care
 ********************************************************/

//Header guard
#ifndef ANIMAL_H
#define ANIMAL_H

//include needed libraries for class
#include <iostream>
#include <stdlib.h>
#include <string>

/*
 * Animal class declaration.
 * This class is used as the base for other animals in the zoo.
 * It has classes used to manipulate the basic components of an animal.
 */
class Animal {
    //private members of class
    private:
        int age; //age of animal
        int foodCost = 80; //cost of animals food
        bool isSick = false; //is the animal sick?
        bool isDead = false; //is the animal dead?
        std::string name; //the animals name

    //public members of the classes
    public:

    /*
     * user-created type for the current stage of life
     * of the animal in question.
     */
    enum LifeStage {
        BABY,
        ADOLESCENT,
        ADULT
    };

    Animal(std::string n, int a=0); //Constructor for Animal class, with user-defined parameters
    Animal(); //Default Constructor for Animal class, no user parameters

    /*
     * Public member functions(methods) for Animal class.
     * a detailed description of each function is given in the implementation file
     */
    int getAge() const; //gets animal age
    void setAge(int a); //sets animal age
    int getFoodCost() const; //gets cost of food
    void advanceMonth(int &costs); //advances month, adds costs
    void makeSick(); //makes animal sick
    void heal(int &costs, const int &bank, const int &price); //heals animal
    void kill(); //there's a fun name! - kills the animal
    bool getSick() const; //gets health of animal
    bool getDead() const; //checks if animal is dead
    LifeStage getLifeStage() const; //gets lifestage of animal
    std::string getName() const; //gets name of animal
    void setName(const std::string &n); //sets name of animal
};

//end header guard
#endif