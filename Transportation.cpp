//
// Created by Matilde on 20/11/2021.
//

#include "Transportation.h"

Transportation::Transportation(std::string tipo, float distance, Time& schedule): schedule(schedule) {
        this->tipo = tipo;
        this->distance = distance;
        this->schedule = schedule;
}
std::string Transportation::getTipo() const{
    return tipo;
}

float Transportation::getDistance() const{
    return distance;
}

Time Transportation::getSchedule() const{
    return schedule;
}

bool Transportation::operator<(const Transportation& re) const{
    return this->distance<re.getDistance();
}

bool Transportation::operator>(const Transportation &re) const {
    return this->distance>re.getDistance();
}

bool Transportation::operator==(const Transportation &re) const {
    return tipo==re.tipo && distance==re.distance && schedule==re.schedule;
}