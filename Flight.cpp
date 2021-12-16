//
// Created by Matilde on 19/11/2021.
//

#include <vector>
#include "Flight.h"

void Flight::setNumVoo(int voo) {
    Flight::numVoo = voo;
}

void Flight::setData(int day, int month, int year, int hour, int minutes) {
    Time final(day, month, year, hour, minutes);
    dataVoo = final;

}

void Flight::setOrigem(std::string origem) {
    Flight::origem = origem;
}

std::string Flight::getOrigem() {
    return Flight::origem;
}

std::string Flight::getDestino() {
    return Flight::destino;
}

int Flight::getNumVoo() {
    return Flight::numVoo;
}

Time Flight::getData() {
    return Flight::dataVoo;
}

Time Flight::getDuracao() {
    return Flight::duracaoVoo;
}

void Flight::setDuracao(int hour, int minute) {
    duracaoVoo = Time(hour, minute);
}

void Flight::setDestino(std::string destino) {
    Flight::destino = destino;
}
