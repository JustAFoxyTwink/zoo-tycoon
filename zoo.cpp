#include "zoo.h"

Zoo::Zoo() {
    std::string 
    prompt1 = "Which animals would you like to start with?\n",
    prompt2 = "(1) Lemur - $700 * 2\n",
    prompt3 = "(2) Tiger - $15000 * 2\n",
    prompt4 = "(3) Black Bear - $6000 * 2\n";

    int temp = getIntBounds(prompt1 + prompt2 + prompt3 + prompt4, 1, 3);

    std::string* names = getNames();

    switch (temp) {
        case 1:
            lemurs = new Lemur[2]{Lemur(names[0], 48), Lemur(names[1], 48)};
            numLemurs = 2;
            money -= 1400;
            break;
        case 2:
            tigers = new Tiger[2]{Tiger(names[0], 48), Tiger(names[1], 48)};
            numTigers = 2;
            money -= 30000;
            break;
        case 3:
            bBears = new BlackBear[2]{BlackBear(names[0], 48), BlackBear(names[1], 48)};
            numBBears = 2;
            money -= 12000;
            break;
    }

    delete [] names;
    names = NULL;
}

Zoo& Zoo::operator=(const Zoo &source) {
    if (this == &source)
        return *this;

    copyLemurs(source.lemurs, source.numLemurs);
    copyTigers(source.tigers, source.numTigers);
    copyBBears(source.bBears, source.numBBears);

    return *this;
}

Zoo::~Zoo() {
    if (lemurs != NULL) delete [] lemurs;
    if (tigers != NULL) delete [] tigers;
    if (bBears != NULL) delete [] bBears;

    lemurs = NULL;
    tigers = NULL;
    bBears = NULL;
}

std::string* Zoo::getNames() {
    std::string* names = new std::string[2];

    std::cout << "Enter Name for the first animal: \n";
    std::cin >> names[0];

    std::cout << "Enter name for second animal: \n";
    std::cin >> names[1];

    return names;
}

void Zoo::copyLemurs(Lemur* s, const int &n) {
    if (lemurs) {
        delete [] lemurs;
        lemurs = new Lemur[n];

        for (int i = 0; i < n; i++)
            lemurs[i] = s[i];
    }
}

void Zoo::copyTigers(Tiger* s, const int &n) {
    if (tigers) {
        delete [] tigers;
        tigers = new Tiger[n];

        for (int i = 0; i < n; i++)
            tigers[i] = s[i];
    }
}

void Zoo::copyBBears(BlackBear* s, const int &n) {
    if (bBears) {
        delete [] bBears;
        bBears = new BlackBear[n];

        for (int i = 0; i < n; i++)
            bBears[i] = s[i];
    }
}

int Zoo::getNumLemurs() const {
    return numLemurs;
}

int Zoo::getNumTigers() const {
    return numTigers;
}

int Zoo::getNumBBears() const {
    return numBBears;
}