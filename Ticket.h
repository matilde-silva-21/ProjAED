//
// Created by Matilde on 20/11/2021.
//

#ifndef AED2122_G53_TICKET_H
#define AED2122_G53_TICKET_H


#include <tuple>
#include "Flight.h"

class Ticket {


    bool bagagem; //verificar se passageiro tem bagagem
    Flight vooPassageiro;
    std::string classe; //economica primeira etc
    std::tuple<char,int> lugar; //o mais comum é letra para filas e numero para os corredores por isso um lugar é a combinacao dos dois
    float price;


public:
    explicit Ticket(Flight vooPassageiro);
};


#endif //AED2122_G53_TICKET_H
