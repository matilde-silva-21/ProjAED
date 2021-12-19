//
// Created by Matilde on 20/11/2021.
//

#include "Person.h"
#include "Time.h"
#include "Flight.h"

Person::Person(std::string name, std::string email, std::string tipoID, int phone, std::string ID) {
    this->name = name;
    this->email = email;
    this->tipoID = tipoID;
    this->phone = phone;
    this->ID = ID;
}

void Person::setName(std::string name) {
    this->name = name;
}

void Person::setPhone(int phone) {
    this->phone = phone;
}

void Person::setEmail(std::string email) {
    this->email = email;
}

std::string Person::getName() {
    return this->name;
}

int Person::getPhone() {
    return this->phone;
}

std::string Person::getEmail() {
    return this->email;
}

void Person::setID(std::string& IDn) {
    this->ID = IDn;
}

std::string Person::getID() {
    return this->ID;
}


Employee::Employee(std::string name, std::string email, int phone, std::string ID): Person(name,email,"employee",phone,ID) {
    setName(name);
    EmployeeID = ID;
}

void Passenger::setTicket(int IDticket) {
    this->IDticket=IDticket;
}

int Passenger::getTicket() {
    return IDticket;
}


Passenger::Passenger(std::string name, std::string email, std::string tipoID, int phone, std::string ID,int IDticket) : Person(name,email, tipoID, phone, ID), IDticket(IDticket){

}
