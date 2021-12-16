//
// Created by Matilde on 19/11/2021.
//

#ifndef AED2122_G53_FLIGHT_H
#define AED2122_G53_FLIGHT_H


#include <string>
#include "Time.h"
#include "vector"

class Flight {

    int numVoo;
    Time dataVoo, duracaoVoo;
    std::string origem,destino;

public:

    Flight(int numVoo, Time dataVoo, Time duracaoVoo): numVoo(numVoo), dataVoo(dataVoo), duracaoVoo(duracaoVoo){
        this->numVoo = numVoo;
        this->dataVoo = dataVoo;
        this->duracaoVoo = duracaoVoo;
    }
    void setNumVoo(int voo);
    void setData(int day, int month, int year, int hour, int minutes);
    void setDuracao(int hour, int minute);
    void setOrigem(std::string origem);
    void setDestino(std::string destino);

    std::string getOrigem();
    std::string getDestino();
    int getNumVoo();
    Time getData();
    Time getDuracao();

    bool operator<(Flight& f1){
        return numVoo<f1.getNumVoo();
    }
    bool operator==(Flight& f1){
        return numVoo==f1.numVoo && dataVoo==f1.dataVoo && duracaoVoo==f1.duracaoVoo && origem==f1.origem && destino==f1.destino;
    }

};


#endif //AED2122_G53_FLIGHT_H
