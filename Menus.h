#ifndef AED2122_G53_MENUS_H
#define AED2122_G53_MENUS_H

#include <iostream>
#include <iomanip>
#include "Airport.h"
#include "Airplane.h"

using namespace std;

class Menus {
    static int airportMenu(Airport& a1);

    static int planesMenu1(Airport& r1);

    static int planesMenu2(Airplane& a1, int& check);

    static int ticketsMenu();

    static void cutfromfile(int index, const string& matricula);

    static int publicTransMenu();
};



#endif //AED2122_G53_MENUS_H
