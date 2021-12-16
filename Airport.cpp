//
// Created by Matilde on 20/11/2021.
//

#include <fstream>
#include "Airport.h"
#include <string.h>

Airport::Airport(string name) {
    this->name = name;
    //this->transporte = BST<Transportation>();
}

void Airport::setPassageiros(std::vector<Passenger> &passageiros) {
    this->passageiros = passageiros;
}

void Airport::setAvioes(std::vector<Airplane> &avioes) {
    Airport::avioes = avioes;
}

void Airport::setTransporte(BST<Transportation> &transporte) {
    //Airport::transporte = transporte;
}

std::vector<Airplane> Airport::getAvioes() {
    return Airport::avioes;
}
/*
BST<Transportation> Airport::getTransporte() {
    //return Airport::transporte;
}*/


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

std::vector<Passenger> Airport::getPassageiros() {
    return this->passageiros;
}

void Airport::setEmpregados(vector<Employee> &empregados){
    this->empregados = empregados;
}

bool Airport::readFlights(string matricula) {
    auto it = std::find_if(avioes.begin(), avioes.end(), [&matricula](Airplane obj) {return obj.getMatricula() == matricula;});
    if(it!=avioes.end()){
        Airplane a = (*it);
        ifstream f;
        f.open("aviao"+matricula+".txt");
        while(!f.eof()){
            std::string origem, destino, element, aux="";
            int day,month,year,starthour, startminute, durationhour,durationminute, numVoo, count=0;

            getline(f, element);
            char dud[element.size()+1];
            strcpy(dud,element.c_str());

            char* delim = strtok(dud, " :/");

            while(delim!=NULL){
                aux+=(delim);
                aux+=" ";
                delim = strtok(NULL, " :/");
            }

            stringstream ss(aux);

            ss>>numVoo>>day>>month>>year>>starthour>>startminute>>durationhour>>durationminute>>origem>>destino;

            Flight f1(numVoo, Time(day,month,year,starthour,startminute), Time(durationhour, durationminute));
            f1.setDestino(destino);
            f1.setOrigem(origem);

            a.addFlight(f1);

            return true;
        }
    }
    else{cout<<"Plane does not exist!"<<endl; return false;}

}

