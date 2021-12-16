//
// Created by Matilde on 20/11/2021.
//

#include "Transportation.h"

Transportation::Transportation(std::string& tipo, float& distance, Time& schedule): schedule(schedule) {
        this->tipo = tipo;
        this->distance = distance;
        this->schedule = schedule;
}
