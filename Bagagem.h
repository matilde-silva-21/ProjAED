//
// Created by Matilde on 15/12/2021.
//

#ifndef AED2122_G53_BAGAGEM_H
#define AED2122_G53_BAGAGEM_H


class Bagagem {
    int IDbagagem, IDTicket;

public:
    Bagagem(int IDbagagem, int IDTicket): IDTicket(IDTicket), IDbagagem(IDbagagem){}
    int getID() const;
};


#endif //AED2122_G53_BAGAGEM_H
