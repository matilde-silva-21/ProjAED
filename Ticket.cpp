//
// Created by Matilde on 20/11/2021.
//

#include "Ticket.h"


Ticket::Ticket(int IDTicket, Bagagem bagagem, int numvooPassageiro, std::string classe):bagagem(bagagem) {
    this->IDTicket=IDTicket;
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

Bagagem Ticket::getBagagem() {
    return bagagem;
}
