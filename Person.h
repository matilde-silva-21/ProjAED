//
// Created by Matilde on 20/11/2021.
//

#ifndef AED2122_G53_PERSON_H
#define AED2122_G53_PERSON_H


#include <string>
#include <tuple>
#include "Ticket.h"

class Person {

    std::string name,email;
    std::string tipoID;
    std::string ID; //primeiro atributo indica o tipo de id (passaporte,cc) e o segundo o numero do documento (criar classe ID?)
    int phone;

public:
    void setName(std::string name);
    void setPhone(int phone);
    void setEmail(std::string email);
    void setID(std::string& IDn);

    std::string getName();
    int getPhone();
    std::string getEmail();
    std::string getID();

    bool operator==(Person& p1){return ID==p1.ID;}

    Person(std::string name, std::string email, std::string tipoID, int phone, std::string ID);
};

class Passenger: public Person{
    Ticket ticket;  //isto implica que o mesmo bilhete esteja associado a 1 ou mais pessoas (viagens de grupo)
    bool checkin; //se o passageiro optou por checkin automatico ou nao

public:
    void setTicket(Ticket ticket);
    Ticket getTicket();

    Passenger(std::string name, std::string email, std::string tipoID, int phone, std::string ID);
};
class Employee: public Person {
    std::string EmployeeID;

public:
    Employee(std::string name, std::string & EmployeeID);
};


#endif //AED2122_G53_PERSON_H