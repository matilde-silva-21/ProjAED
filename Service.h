//
// Created by Matilde on 19/11/2021.
//

#ifndef AED2122_G53_SERVICE_H
#define AED2122_G53_SERVICE_H


#include <string>
#include "Time.h"
#include "vector"
#include "Person.h"
#include "algorithm"

class Service {

    std::string tipo; //tipo = manutencao ou limpeza
    Time time;
    std::string employeeID;

public:
    bool operator<(Service& v1);
    bool operator==(Service& s1);

    Service(std::string& tipo, Time& time, std::string& employeeID) :  tipo(tipo), time(time), employeeID(employeeID) {
        this->tipo = tipo;
        this->time = time;
        this->employeeID = employeeID;
    }

    std::string getType();
    Time getTime();
    std::string getID();
};


#endif //AED2122_G53_SERVICE_H
