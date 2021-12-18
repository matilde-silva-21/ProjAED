#ifndef AED2122_G53_MENUS_H
#define AED2122_G53_MENUS_H

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include "Airport.h"
#include "Airplane.h"

using namespace std;

class Menus {
public:
    static int airportMenu(Airport& a1);

    static int planesMenu1(Airport& r1);

    static int planesMenu2(Airplane& a1, int& check, Airport& r1);

    static int ticketsMenu();

    static void cutfromfile(Airport& a1, int index);

    static int publicTransMenu();

    static void addPlane(Airport& a1);

    static void addVoo(Airplane& a1, Airport& r1);

    static void addFlightFile(Airplane& a1);

    static void deleteVoo(Airplane& a1, Airport& r1);

};



#endif //AED2122_G53_MENUS_H
