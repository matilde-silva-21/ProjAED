//
// Created by Matilde on 20/11/2021.
//

#ifndef AED2122_G53_AIRPORT_H
#define AED2122_G53_AIRPORT_H


#include <vector>
#include "Airplane.h"
#include "Transportation.h"
#include "BST.h"
#include "Service.h"
#include "algorithm"
#include "CarrinhoTransporte.h"

class Airport {
    int numBagagem=0;
    std::string name;
    std::vector<Airplane> avioes; //avioes pertencentes ao aeroporto
    std::vector<Employee> empregados; //passageiros no aeroporto
    std::vector<Passenger> passageiros; //passageiros no voo
    BST<Transportation> transporte; //todos os transportes do aeroporto
    queue<Service> ToDo, Done;
    CarrinhoTransporte carrinho;
    std::vector<Ticket> tickets;
public:
    void setAvioes(std::vector<Airplane>& avioes);
    void setTransporte(BST<Transportation>& transporte);
    Airport(string name, BST<Transportation> t1,CarrinhoTransporte& carrinho);
    std::vector<Airplane> getAvioes();
    BST<Transportation> getTransporte();

    void addTransporte(const Transportation& t1);

    void addService(Service s1); //adicionar servico a ToDO
    void removeService(); //remover servico de Tdo e verificar se foi removido corretamente
    void removeDone(); //remover servico de Done
    void addDone(Service s1); //adicionar servico ao Done

    queue<Service> getToDo();
    queue<Service> getDone();

    void setToDo(queue<Service> v1);
    void setDone(queue<Service> v1);

    void setEmpregados(vector<Employee> &empregados);
    std::vector<Employee> getEmpregados();
    void removeEmpregado(vector<Employee>::iterator e1);
    void addEmpregado(Employee e1);

    void setPassageiros(std::vector<Passenger> &passageiros);
    std::vector<Passenger> getPassageiros();
    void addPassageiro(Passenger& p1);

    void addTicket(Ticket t1);
    std::vector<Ticket> getTickets();

    void addPlane(Airplane& a1);

    CarrinhoTransporte getCarrinhos();
    int numBagaem();

    int numberOfFilgths();


};


#endif //AED2122_G53_AIRPORT_H
