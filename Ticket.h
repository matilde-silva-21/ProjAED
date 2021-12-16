//
// Created by Matilde on 20/11/2021.
//

#ifndef AED2122_G53_TICKET_H
#define AED2122_G53_TICKET_H


#include "string"

class Ticket {

    int IDTicket;
    bool bagagem; //verificar se passageiro tem bagagem
    std::string classe; //economica primeira etc
    std::string lugar; //o mais comum é letra para filas e numero para os corredores por isso um lugar é a combinacao dos dois
    float price;
    int numvooPassageiro;

public:
    Ticket(int IDTicket, bool bagagem, int numvooPassageiro, std::string classe, std::string lugar, float price);


};


#endif //AED2122_G53_TICKET_H
