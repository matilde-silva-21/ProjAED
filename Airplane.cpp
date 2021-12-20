//
// Created by Matilde on 19/11/2021.
//

#include <fstream>
#include "Airplane.h"
#include "iostream"



Airplane::Airplane(std::string &matricula, std::string &tipo, int &capacidade) {
    this->capacidade = capacidade;
    this->matricula = matricula;
    this->tipo = tipo;
}

void Airplane::setMatricula(std::string matricula) {
    this->matricula = matricula;
}

void Airplane::setTipo(std::string tipo) {
    this->tipo = tipo;
}

void Airplane::setCapacidade(int c) {
    this->capacidade = c;
}

void Airplane::setPlanoVoo(std::vector<Flight> dummy) {
    Airplane::PlanoVoo = dummy;
}

std::string Airplane::getMatricula() {
    return this->matricula;
}

std::string Airplane::getTipo() {
    return Airplane::tipo;
}

int Airplane::getCapacidade() {
    return Airplane::capacidade;
}

std::vector<Flight> Airplane::getPlanoVoo() {
    return Airplane::PlanoVoo;
}


bool compare(Flight f1, Flight f2){
    return f1.getNumVoo()<f2.getNumVoo();
}

bool Airplane::addFlight(Flight& f1) {
    PlanoVoo.push_back(f1);
    std::sort(PlanoVoo.begin(),PlanoVoo.end(), compare);
    std::fstream f("aviao"+matricula+".txt");
    for(Flight& f2: PlanoVoo){
        f<<f2.getNumVoo()<<" "<<f2.getData().printDate()<<" "<<f2.getData().printhour()<<" "<<f2.getDuracao().printhour()<<" "<<f2.getDestino()<<" "<<f1.getOrigem()<<std::endl;
    }
    f.close();
    return true;
}

bool Airplane::removeFlight(Flight f1) {
    for(auto it =PlanoVoo.begin();it!=PlanoVoo.end();it++){
        if(*it == f1){
            PlanoVoo.erase(it);
            std::fstream f("aviao"+matricula+".txt");
            for(Flight& f2: PlanoVoo){
                f<<f2.getNumVoo()<<" "<<f2.getData().printDate()<<" "<<f2.getData().printhour()<<" "<<f2.getDuracao().printhour()<<" "<<f2.getDestino()<<" "<<f1.getOrigem()<<std::endl;
            }
            return true;
        }
        else{return false;}
    }
    return false;
}
void Airplane::deletePlanoVoo() {
    PlanoVoo.erase(PlanoVoo.begin(),PlanoVoo.end());
    std::fstream f("aviao"+matricula+".txt");
    f.close();
}



