#ifndef ZOO_H
#define ZOO_H

#include "lemur.h"
#include "tiger.h"
#include "black_bear.h"
#include "functions.h"

#include <iostream>
#include <string>

class Zoo {
    private:

        int numLemurs = 0;
        int numTigers = 0;
        int numBBears = 0;

        std::string* getNames();
        void copyLemurs(Lemur* s, const int &n);
        void copyTigers(Tiger* s, const int &n);
        void copyBBears(BlackBear* s, const int &n);

        static int time;
        int money = 100000;
    public:
        Zoo();
        Zoo& operator=(const Zoo &source);
        ~Zoo();

        Lemur* lemurs = NULL;
        Tiger* tigers = NULL;
        BlackBear* bBears = NULL;

        int getNumLemurs() const;
        int getNumTigers() const;
        int getNumBBears() const;
};

#endif