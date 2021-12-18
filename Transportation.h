//
// Created by Matilde on 20/11/2021.
//

#ifndef AED2122_G53_TRANSPORTATION_H
#define AED2122_G53_TRANSPORTATION_H


#include <string>
#include "Time.h"

class Transportation {
    std::string tipo; //bus, train, subway
    float distance; //distancia do transporte ao aeroporto
    Time schedule; //horario do tranporte

    public:
    Transportation(std::string tipo, float distance, Time& schedule);

    std::string getTipo() const;
    float getDistance() const;
    Time getSchedule() const;

    bool operator<(const Transportation& re) const;
    bool operator>(const Transportation& re) const;
    bool operator==(const Transportation& re) const;
};


#endif //AED2122_G53_TRANSPORTATION_H
