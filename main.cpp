#include <iostream>
#include <fstream>
#include <sstream>

#include "Airplane.h"
#include "Airport.h"
#include "Time.h"
#include "Ticket.h"
#include "Person.h"
#include "Service.h"
#include "Transportation.h"
#include <tuple>

std::vector<Airplane> ReadPlanes(){
    ifstream f;
    std::vector<Airplane> avioes;
    f.open("avioes.txt");
    string element;
    while(!f.eof()){
        string matricula;
        int capacidade;
        string tipo;
        getline(f, element);
        stringstream aux(element);

        aux >> matricula >> tipo >> capacidade;

        Airplane a(matricula, tipo, capacidade);
        avioes.push_back(a);
    }
    return avioes;
}

std::vector<Passenger> ReadPassageiros(){
    ifstream f;
    std::vector<Passenger> passageiros;
    f.open("passageiros.txt");
    string element;
    while(!f.eof()){
        string email, nome, ID, tipoID;
        int phone;

        getline(f, element);
        stringstream aux(element);

        aux >> nome >> email >> tipoID >> ID >> phone;

        Passenger p1 (nome, email, tipoID, phone, ID);
        passageiros.push_back(p1);
    }
    return passageiros;
}

std::vector<Employee> ReadEmployees(){
    ifstream f;
    std::vector<Employee> empregados;
    f.open("funcionarios.txt");
    string element;
    while(!f.eof()){
        string name, employeeID;

        getline(f, element);
        stringstream aux(element);

        aux >> name >> employeeID;

        Employee a1(name, employeeID);
        empregados.push_back(a1);
    }
    return empregados;
}

std::vector<Service> ReadServices(vector<Employee> empregados){
    ifstream f;
    std::vector<Service> servicos;
    f.open("servicos.txt");
    string element;
    while(!f.eof()){
        string tipo, employeeID;
        int hora, minuto, dia, mes, ano;


        getline(f, element);
        stringstream aux(element);
        vector<Employee>::iterator it = empregados.begin();
        while(it != empregados.end()){
            if((*it).getID() == employeeID)
                break;
            it++;
        }
        aux >> tipo >> dia >> mes >> ano >> hora >> minuto >> employeeID;
        Time t(mes, ano, dia, hora, minuto);
        Service c(tipo, t, it->getID());
        servicos.push_back(c);
    }
    return servicos;
}

int main() {
    Airport a1("Porto");
    auto avioes  =  ReadPlanes();
    a1.setAvioes(avioes);
    auto passageiros = ReadPassageiros();
    a1.setPassageiros(passageiros);
    auto empregados = ReadEmployees();
    a1.setEmpregados(empregados);
    auto services =  ReadServices(a1.getEmpregados);

    a1.readFlights("HH-33-HL");

    return 0;
}
