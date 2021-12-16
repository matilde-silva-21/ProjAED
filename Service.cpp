//
// Created by Matilde on 19/11/2021.
//

#include "Service.h"

bool Service::operator<(Service &v1){
    return time < v1.time;
}

bool Service::operator==(Service& s1) {
    return tipo==s1.tipo && time==s1.time && EmplyeeID==s1.EmplyeeID;
}
