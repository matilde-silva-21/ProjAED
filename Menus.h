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

    static int ticketsMenu(Airport& a1);

    static void cutfromfile(Airport& a1, int index);

    static int publicTransMenu(Airport& a1);

    static void addPlane(Airport& a1);

    static void addVoo(Airplane& a1, Airport& r1);

    static void deleteVoo(Airplane& a1, Airport& r1);

    static void addTicket(Ticket& t1);

    static void addPerson(int IDticket, Airport& a1);

    static int servicesMenu(Airport& a1);

    static Time separateDateandHour(string date, string hour);

    static Time separateHour(string hour);

    static int busMenu(Airport& a1);

    static int trainMenu(Airport &a1);

    static int subwayMenu(Airport &a1);

    static int checkinMenu(Airport& a1);

    static int employeeMenu(Airport& a1);

    static int carMenu(Airport& a1);
};



#endif //AED2122_G53_MENUS_H
