/********************************************************
 * Program Filename: zoo.h
 * Author: Evan Garrison
 * Date: 05/14/2021
 * Description: Header file for Zoo class
 * Input: starting animal, animals to add to zoo
 * Output: animals in zoo, revenue generated from zoo, 
 * costs from animals, size of bank, random events
 ********************************************************/

#ifndef ZOO_H
#define ZOO_H

#include "lemur.h"
#include "tiger.h"
#include "black_bear.h"
#include "functions.h"

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class Zoo {
    private:
        int numLemurs = 0;
        int numTigers = 0;
        int numBBears = 0;
        Lemur* lemurs = NULL;
        Tiger* tigers = NULL;
        BlackBear* bBears = NULL;

        void copyLemurs(Lemur* s, const int &n);
        void copyTigers(Tiger* s, const int &n);
        void copyBBears(BlackBear* s, const int &n);

        static int time;
        int money = 100000;
    public:
        Zoo();
        Zoo& operator=(const Zoo &source);
        ~Zoo();

        int getNumLemurs() const;
        int getNumTigers() const;
        int getNumBBears() const;
        int getMoney() const;

        void showAnimals() const;
        void showLemurs() const;
        void showTigers() const;
        void showBBears() const;

        void advanceMonth();
        void randEvent();
        void makeRandSick();
        void randBirth();

        void addLemurs(const int &n, const int &a);
        void removeLemur(const int &n);
        void addTigers(const int &n, const int &a);
        void removeTiger(const int &n);
        void addBBears(const int &n, const int &a);
        void removeBBear(const int &n);
};

#endif