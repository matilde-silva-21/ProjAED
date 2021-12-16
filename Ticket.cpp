//
// Created by Matilde on 20/11/2021.
//

#include "Ticket.h"


Ticket::Ticket(int IDTicket, bool bagagem, int numvooPassageiro, std::string classe, std::string lugar, float price) {
    this->IDTicket=IDTicket;
    this->bagagem=bagagem;
    this->numvooPassageiro=numvooPassageiro;
    this->classe=classe;
    this->lugar=lugar;
    this->price=price;
}
