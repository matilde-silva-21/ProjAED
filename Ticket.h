//
// Created by Matilde on 20/11/2021.
//

#ifndef AED2122_G53_TICKET_H
#define AED2122_G53_TICKET_H


#include "string"
#include "vector"

class Ticket {

    int IDTicket;
    bool bagagem; //verificar se passageiro tem bagagem
    std::string classe; //economica primeira etc
    int numvooPassageiro;


public:
    Ticket(int IDTicket, bool bagagem, int numvooPassageiro, std::string classe);
    int getID();
    std::string getClasse();
    int getNumVoo();
    bool getBagagem();


};


#endif //AED2122_G53_TICKET_H
