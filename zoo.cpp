/********************************************************
 * Program Filename: zoo.cpp
 * Author: Evan Garrison
 * Date: 05/14/2021
 * Description: Implementation file for Zoo class
 * Input: starting animal, animals to add to zoo
 * Output: animals in zoo, revenue generated from zoo, 
 * costs from animals, size of bank.
 ********************************************************/

#include "zoo.h"

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
Zoo::Zoo() {
    string
    prompt1 = "Which animals would you like to start with?\n",
    prompt2 = "(1) Lemur - $700 * 2\n",
    prompt3 = "(2) Tiger - $15000 * 2\n",
    prompt4 = "(3) Black Bear - $6000 * 2\n";

    int temp = getIntBounds(prompt1 + prompt2 + prompt3 + prompt4, 1, 3);
    cout << endl;
    string names[2] {
        getRandName(),
        getRandName()
    };

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
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
Zoo& Zoo::operator=(const Zoo &source) {
    if (this == &source)
        return *this;

    copyLemurs(source.lemurs, source.numLemurs);
    copyTigers(source.tigers, source.numTigers);
    copyBBears(source.bBears, source.numBBears);

    return *this;
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
Zoo::~Zoo() {
    if (lemurs != NULL) delete [] lemurs;
    if (tigers != NULL) delete [] tigers;
    if (bBears != NULL) delete [] bBears;

    lemurs = NULL;
    tigers = NULL;
    bBears = NULL;
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
void Zoo::copyLemurs(Lemur* s, const int &n) {
    if (lemurs) {
        delete [] lemurs;
        lemurs = new Lemur[n];

        for (int i = 0; i < n; i++)
            lemurs[i] = s[i];
    }
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
void Zoo::copyTigers(Tiger* s, const int &n) {
    if (tigers) {
        delete [] tigers;
        tigers = new Tiger[n];

        for (int i = 0; i < n; i++)
            tigers[i] = s[i];
    }
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
void Zoo::copyBBears(BlackBear* s, const int &n) {
    if (bBears) {
        delete [] bBears;
        bBears = new BlackBear[n];

        for (int i = 0; i < n; i++)
            bBears[i] = s[i];
    }
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
int Zoo::getNumLemurs() const {
    return numLemurs;
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
int Zoo::getNumTigers() const {
    return numTigers;
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
int Zoo::getNumBBears() const {
    return numBBears;
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
int Zoo::getMoney() const {
    return money;
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
void Zoo::showAnimals() const {
    cout << getNumLemurs() << " Lemurs:\n";
    showLemurs();
    cout << endl;

    cout << getNumTigers() << " Tigers:\n";
    showTigers();
    cout << endl;

    cout << getNumBBears() << " Black Bears:\n";
    showBBears();
    cout << endl;
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
void Zoo::showLemurs() const {
    for (int i = 0; i < numLemurs; i++) {
        cout << "Age: " << lemurs[i].getAge() 
        << "\tFood Cost: " << lemurs[i].getFoodCost()
        << "\tName: " << lemurs[i].getName() << endl;
    }
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
void Zoo::showTigers() const {
    for (int i = 0; i < numTigers; i++) {
        cout << "Age: " << tigers[i].getAge() 
        << "\tFood Cost: " << tigers[i].getFoodCost()
        << "\tName: " << tigers[i].getName() << endl;
    }
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
void Zoo::showBBears() const {
    for (int i = 0; i < numBBears; i++) {
        cout << "Age: " << bBears[i].getAge() 
        << "\tFood Cost: " << bBears[i].getFoodCost()
        << "\tName: " << bBears[i].getName() << endl;
    }
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
void Zoo::advanceMonth() {
    int
    costs = 0,
    revenue = 0;

    for (int i = 0; i < numLemurs; i++)
        lemurs[i].advanceMonth(costs, revenue, money);

    for (int i = 0; i < numTigers; i++)
        tigers[i].advanceMonth(costs, revenue, money);

    for (int i = 0; i < numBBears; i++)
        bBears[i].advanceMonth(costs, revenue, money);

    randEvent();

    money += revenue - costs;

    cout << '$' << revenue << " in revenue generated this month.\n"
    << '$' << costs << " in costs from food and medical care.\n"
    << '$' << money << " left in the bank.\n";
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
void Zoo::randEvent() {
    int randInt = rand() % 3;

    switch (randInt) {
        case 0:
            makeRandSick();
            break;
        case 1:
            randBirth();
            break;
        case 2:
        default:
            cout << "No random events happened this month.\n";
    }
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
void Zoo::makeRandSick() {
    int a = rand() % 3;
    int c;

    switch (a) {
        case 0:
            if (numLemurs == 0) goto t;
            c = rand() % numLemurs;
            lemurs[c].makeSick();
            cout << lemurs[c].getName() << " is sick!\n";
            break;
        case 1:
        t:
            if (numTigers == 0) goto b;
            c = rand() % numTigers;
            tigers[c].makeSick();
            cout << tigers[c].getName() << " is sick!\n";
            break;
        case 2:
        default:
        b:
            if (numBBears == 0) cout << "Nothing happened this month.\n";
            else {
                c = rand() % numBBears;
                bBears[c].makeSick();
                cout << bBears[c].getName() << " is sick!\n";
            }
    }
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
void Zoo::randBirth() {
    int a = rand() % 3;

    switch (a) {
        case 0:
            if (numLemurs < 2) goto t;
            addLemurs(1, 0);
            cout << lemurs[numLemurs - 1].getName() << " the lemur was born!\n";
            break;
        case 1:
        t:
            if (numTigers < 2) goto b;
            addTigers(1, 0);
            cout << tigers[numTigers - 1].getName() << " the tiger was born!\n";
            break;
        case 2:
        default:
        b:
            if (numBBears < 2) cout << "Nothing happened this month.\n";
            else {
                addBBears(1, 0);
                cout << bBears[numBBears - 1].getName() << " the black bear was born!\n";
            }
    }
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
void Zoo::addLemurs(const int &n, const int &a) {
    Lemur* newL = new Lemur[numLemurs];

    for (int i = 0; i < numLemurs; i++)
        newL[i] = lemurs[i];

    delete [] lemurs;
    lemurs = new Lemur[numLemurs + n];

    for (int i = 0; i < numLemurs; i++)
        lemurs[i] = newL[i];

    delete [] newL;
    newL = NULL;

    for (int i = numLemurs; i < numLemurs + n; i++)
        lemurs[i] = Lemur{getRandName(), a};

    numLemurs += n;
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
void Zoo::removeLemur(const int &n) {
    Lemur* newL = new Lemur[numLemurs - 1];
    int temp = 0;

    for (int i = 0; i < numLemurs; i++) {
        if (i != n)
            newL[i - temp] = lemurs[i];
        else
            temp = 1;
    }

    delete [] lemurs;
    lemurs = new Lemur[numLemurs - 1];

    for (int i = 0; i < numLemurs - 1; i++)
        lemurs[i] = newL[i];

    delete [] newL;
    newL = NULL;

    numLemurs--;
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
void Zoo::addTigers(const int &n, const int &a) {
    Tiger* newT = new Tiger[numTigers];

    for (int i = 0; i < numTigers; i++)
        newT[i] = tigers[i];

    delete [] tigers;
    tigers = new Tiger[numTigers + n];

    for (int i = 0; i < numTigers; i++)
        tigers[i] = newT[i];

    delete [] newT;
    newT = NULL;

    for (int i = numTigers; i < numTigers + n; i++)
        tigers[i] = Tiger{getRandName(), a};

    numTigers += n;
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
void Zoo::removeTiger(const int &n) {
    Tiger* newT = new Tiger[numTigers - 1];
    int temp = 0;

    for (int i = 0; i < numTigers; i++) {
        if (i != n)
            newT[i - temp] = tigers[i];
        else
            temp = 1;
    }

    delete [] tigers;
    tigers = new Tiger[numTigers - 1];

    for (int i = 0; i < numTigers - 1; i++)
        tigers[i] = newT[i];

    delete [] newT;
    newT = NULL;

    numTigers--;
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
void Zoo::addBBears(const int &n, const int &a) {
    BlackBear* newB = new BlackBear[numBBears];

    for (int i = 0; i < numBBears; i++)
        newB[i] = bBears[i];

    delete [] bBears;
    bBears = new BlackBear[numBBears + n];

    for (int i = 0; i < numBBears; i++)
        bBears[i] = newB[i];

    delete [] newB;
    newB = NULL;

    for (int i = numBBears; i < numBBears + n; i++)
        bBears[i] = BlackBear{getRandName(), a};

    numBBears += n;
}

/********************************************************
 * Function:
 * Description:
 * Parameters:
 * Pre-Conditions:
 * Post-Conditions:
 ********************************************************/
void Zoo::removeBBear(const int &n) {
    BlackBear* newB = new BlackBear[numBBears - 1];
    int temp = 0;

    for (int i = 0; i < numBBears; i++) {
        if (i != n)
            newB[i - temp] = bBears[i];
        else
            temp = 1;
    }

    delete [] bBears;
    bBears = new BlackBear[numBBears - 1];

    for (int i = 0; i < numBBears - 1; i++)
        bBears[i] = newB[i];

    delete [] newB;
    newB = NULL;

    numBBears--;
}