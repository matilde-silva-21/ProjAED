//
// Created by Matilde on 20/11/2021.
//

#include <fstream>
#include "Airport.h"
#include <string.h>

Airport::Airport(string name, BST<Transportation> t1, CarrinhoTransporte& carrinho): transporte(t1),
                                                                                       carrinho(carrinho) {
    this->name = name;
}


void Airport::setAvioes(std::vector<Airplane> &avioes) {
    Airport::avioes = avioes;
}

void Airport::setTransporte(BST<Transportation> &transporte) {
    Airport::transporte = transporte;
    fstream f1("transporte.txt");
    for(auto it=transporte.begin(); it!=transporte.end(); it++){
        f1<<(*it).getTipo()<<" "<<(*it).getSchedule().printhour()<<" "<<(*it).getDistance()<<endl;
    }
    f1.close();
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
    transporte.insert(t1);
    fstream f("transporte.txt", std::ios_base::app);
    f<<t1.getTipo()<<" "<<t1.getSchedule().printhour()<<" "<<t1.getDistance()<<endl;
    f.close();

}

void Airport::addPassageiro(Passenger &p1) {
    passageiros.push_back(p1);
}

CarrinhoTransporte Airport::getCarrinhos() {
    return carrinho;
}

int Airport::numBagaem() {
    numBagagem++;
    return numBagagem-1;
}

std::vector<Employee> Airport::getEmpregados() {
    return empregados;
}

void Airport::removeEmpregado(vector<Employee>::iterator e1) {
    empregados.erase(e1);
    sort(empregados.begin(),empregados.end());
    fstream f1("funcionarios.txt");
    for(Employee& e1: empregados){
        f1<<e1.getName()<<" "<<e1.getID()<<" "<<e1.getPhone()<<" "<<e1.getEmail()<<endl;
    }
    f1.close();
}

void Airport::addEmpregado(Employee e1) {
    empregados.push_back(e1);
    sort(empregados.begin(),empregados.end());
    fstream f1("funcionarios.txt");
    for(Employee& e1: empregados){
        f1<<e1.getName()<<" "<<e1.getID()<<" "<<e1.getPhone()<<" "<<e1.getEmail()<<endl;
    }
    f1.close();
}


