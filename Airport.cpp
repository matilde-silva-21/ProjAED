//
// Created by Matilde on 20/11/2021.
//

#include <fstream>
#include "Airport.h"
#include <string.h>

Airport::Airport(string name, const Transportation& t1): transporte(BST<Transportation>(t1)) {
    this->name = name;
}


void Airport::setAvioes(std::vector<Airplane> &avioes) {
    Airport::avioes = avioes;
}

void Airport::setTransporte(BST<Transportation> &transporte) {
    Airport::transporte = transporte;
}

std::vector<Airplane> Airport::getAvioes() {
    return this->avioes;
}

BST<Transportation> Airport::getTransporte() {
    return transporte;
}


void Airport::addService(Service s1) {
    ToDo.push(s1);
}

void Airport::removeService() {
    Done.push(ToDo.front());
    ToDo.pop();
}

void Airport::removeDone() {
    Done.pop();
}

void Airport::addDone(Service s1) {
    Done.push(s1);
}

queue<Service> Airport::getToDo() {
    return ToDo;
}

queue<Service> Airport::getDone() {
    return Done;
}

void Airport::setToDo(queue<Service> v1) {
    ToDo=v1;
}

void Airport::setDone(queue<Service> v1) {
    Done=v1;
}


void Airport::setEmpregados(vector<Employee> &empregados){
    this->empregados = empregados;
}

void Airport::setPassageiros(std::vector<Passenger> &passageiros) {
    this->passageiros = passageiros;
}

std::vector<Passenger> Airport::getPassageiros() {
    return this->passageiros;
}

void Airport::addTicket(Ticket t1) {
    tickets.push_back(t1);
}

std::vector<Ticket> Airport::getTickets() {
    return tickets;
}

void Airport::addPlane(Airplane &a1) {
    avioes.push_back(a1);
}

int Airport::numberOfFilgths() {
    int total=0;
    for(Airplane& a1: avioes){
        total+=a1.getPlanoVoo().size();
    }
    return total;
}

void Airport::addTransporte(const Transportation &t1) {

}
