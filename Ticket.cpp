//
// Created by Matilde on 20/11/2021.
//

#include "Ticket.h"


Ticket::Ticket(int IDTicket, bool bagagem, int numvooPassageiro, std::string classe) {
    this->IDTicket=IDTicket;
    this->bagagem=bagagem;
    this->numvooPassageiro=numvooPassageiro;
    this->classe=classe;
}

int Ticket::getID() {
    return IDTicket;
}

std::string Ticket::getClasse() {
    return classe;
}

int Ticket::getNumVoo() {
    return numvooPassageiro;
}

bool Ticket::getBagagem() {
    return bagagem;
}
