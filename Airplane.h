//
// Created by Matilde on 19/11/2021.
//

#ifndef AED2122_G53_AIRPLANE_H
#define AED2122_G53_AIRPLANE_H

#include <vector>
#include <tuple>
#include "string"
#include "Flight.h"
#include "algorithm"

class Airplane {
private:
    std::string matricula;
    std::string tipo;
    int capacidade;
    std::vector<Flight> PlanoVoo;

public:
    Airplane(std::string &matricula, std::string &tipo, int &capacidade);
    void setMatricula(std::string matricula);
    void setTipo(std::string tipo);
    void setCapacidade(int c);
    void setPlanoVoo(std::vector<Flight> dummy);

    std::string getMatricula();
    std::string getTipo();
    int getCapacidade();
    std::vector<Flight> getPlanoVoo();

    bool addFlight(Flight& f1);
    bool removeFlight(Flight f1);
    void deletePlanoVoo();
};

#endif //AED2122_G53_AIRPLANE_H