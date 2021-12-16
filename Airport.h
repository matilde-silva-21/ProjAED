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
#include "sstream"

class Airport {
    std::string name;
    std::vector<Airplane> avioes; //avioes pertencentes ao aeroporto
    std::vector<Passenger> passageiros; //passageiros no aeroporto
    std::vector<Employee> empregados; //passageiros no aeroporto

    //BST<Transportation> transporte; //todos os transportes do aeroporto
    queue<Service> ToDo, Done;
    std::vector<CarrinhoTransporte> carrinhos;

public:
    void setAvioes(std::vector<Airplane>& avioes);
    void setTransporte(BST<Transportation>& transporte);
    void setPassageiros(std::vector<Passenger> &passageiros);
    explicit Airport(string name);
    std::vector<Airplane> getAvioes();
    //BST<Transportation> getTransporte();
    std::vector<Passenger> getPassageiros();
    void addService(Service s1); //adicionar servico a ToDO
    void removeService(); //remover servico de Tdo e verificar se foi removido corretamente
    void removeDone(); //remover servico de Done
    void addDone(Service s1); //adicionar servico ao Done

    queue<Service> getToDo();
    queue<Service> getDone();

    void setToDo(queue<Service> v1);
    void setDone(queue<Service> v1);

    void setEmpregados(vector<Employee> &empregados);
    std::vector<Employee> getEmpregados;


/*esta funcao assume que existirá um ficheiro para cada aviao , ficheiro com nome no formato ("Aviao"+matricula)
 alem disso atualiza automaticamente o plano de voo do aviao escolhido, em vez de retornar um vetor*/
    bool readFlights(string matricula);
};


#endif //AED2122_G53_AIRPORT_H
