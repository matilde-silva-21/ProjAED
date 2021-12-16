#ifndef AED2122_G53_MENUS_H
#define AED2122_G53_MENUS_H

#include <iostream>
#include <iomanip>
#include "Airport.h"
#include "Airplane.h"

using namespace std;

class Menus {

};

int airportMenu(Airport a1);

int planesMenu1(Airport r1);

int planesMenu2(Airplane a1, int& check);

int ticketsMenu();


int publicTransMenu();

#endif //AED2122_G53_MENUS_H
