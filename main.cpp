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
#include <cstring>
#include "Menus.h"
#include "algorithm"
#include "string"


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
        if(element.empty()){break;}
        stringstream aux(element);

        aux >> matricula >> tipo >> capacidade;

        Airplane a(matricula, tipo, capacidade);
        avioes.push_back(a);
    }
    f.close();
    return avioes;
}

std::vector<Passenger> ReadPassageiros(){
    ifstream f;
    std::vector<Passenger> passageiros;
    f.open("passageiros.txt");
    string element;
    while(!f.eof()){
        string email, nome, ID, tipoID;
        int phone, IDticket;

        getline(f, element);
        if(element.empty()){break;}
        stringstream aux(element);

        aux >> nome >> email >> tipoID >> ID >> IDticket >>phone;

        Passenger p1 (nome, email, tipoID, phone, ID, IDticket);
        passageiros.push_back(p1);
    }
    f.close();
    return passageiros;
}

std::vector<Employee> ReadEmployees(){
    ifstream f;
    std::vector<Employee> empregados;
    f.open("funcionarios.txt");
    string element;
    while(!f.eof()){
        string name, employeeID, email;
        int phone;

        getline(f, element);
        if(element.empty()){break;}
        stringstream aux(element);

        aux >> name >> employeeID >>phone>>email;

        Employee a1(name,email,phone,employeeID);
        empregados.push_back(a1);
    }
    f.close();
    return empregados;
}

std::queue<Service> ReadServicesToDo(){
    ifstream f;
    std::queue<Service> servicos;
    f.open("servicosToDo.txt");
    string element;
    while(!f.eof()){
        string tipo, employeeID, data, hora;


        getline(f, element);
        if(element.empty()){break;}
        stringstream aux(element);

        aux >> tipo >>data >>hora >> employeeID;

        Time t = Menus::separateDateandHour(data,hora);
        Service c(tipo, t, employeeID);
        servicos.push(c);
    }
    f.close();
    return servicos;
}

std::queue<Service> ReadServicesDone(){
    ifstream f;
    std::queue<Service> servicos;
    f.open("servicosDone.txt");
    string element;
    while(!f.eof()){
        string tipo, employeeID, data, hora;


        getline(f, element);
        if(element.empty()){break;}
        stringstream aux(element);

        aux >> tipo >>data >>hora >> employeeID;

        Time t = Menus::separateDateandHour(data,hora);
        Service c(tipo, t, employeeID);
        servicos.push(c);
    }
    f.close();
    return servicos;
}

/*esta funcao assume que existirá um ficheiro para cada aviao , ficheiro com nome no formato ("Aviao"+matricula)
 alem disso atualiza automaticamente o plano de voo do aviao escolhido, em vez de retornar um vetor*/
void readFlights(Airport& a1, string matricula) {
    vector<Flight> final;
    vector<Airplane> avioes = a1.getAvioes();
    auto it = std::find_if(avioes.begin(), avioes.end(), [&matricula](Airplane obj) {return obj.getMatricula() == matricula;});

    if(it!=avioes.end()){
        ifstream f;
        f.open("aviao"+matricula+".txt");
        while(!f.eof()){
            std::string origem, destino, element, data , hora, duracao;
            int numVoo;
            getline(f, element);
            if(element.empty()){break;}

            stringstream ss(element);

            ss>>numVoo>>data>>hora>>duracao>>origem>>destino;


            Flight f1(numVoo, Menus::separateDateandHour(data,hora), Menus::separateHour(hora));
            f1.setDestino(destino);
            f1.setOrigem(origem);
            f.close();
            final.push_back(f1);
        }
        (*it).setPlanoVoo(final);
        a1.setAvioes(avioes);
    }
    else{cout<<"Plane does not exist!"<<endl; }
}

void readTickets(Airport& a1){
    ifstream f;
    f.open("ticket.txt");
    string element, lugar, classe;
    int IDTicket, numvooPassageiro, IDbagagem;
    float price;

    while(!f.eof()){
        getline(f,element);
        if(element.empty()){break;}
        stringstream ss(element);

        ss>>IDTicket>>IDbagagem>>numvooPassageiro>>classe;

        Bagagem b1(IDbagagem,IDTicket);

        Ticket t(IDTicket,b1,numvooPassageiro,classe);

        a1.addTicket(t);
    }
}

BST<Transportation> readBST(){

    Time hor(0,0);
    Transportation dummy("", 0, hor);
    BST<Transportation> b1(dummy);
    string element,tipo,horario;
    float distance;
    ifstream f1("transporte.txt");
    while(!f1.eof()){
        getline(f1, element);
        f1>>tipo>>horario>>distance;
        Time r = Menus::separateHour(horario);
        Transportation t1(tipo,distance,r);
        b1.insert(t1);
    }
    return b1;

}

void readCarrinho(CarrinhoTransporte& c1){
    string element;
    int bagID, tickID;
    ifstream f("carrinhoTransporte.txt");
    while(!f.eof()){
        getline(f,element);
        f >> bagID >>tickID;
        c1.addBagagem(Bagagem (bagID,tickID));
    }
}
int main() {
    /*ordem de inicializacao: *carrinho transporte,*BST,*airport,*airplanes,*flights,*tickets,*funcionarios,*passageiros,*ToDo, *Done*/

    CarrinhoTransporte c1(1,2,3,4);
    readCarrinho(c1);


    Airport a1("Porto",readBST(), c1);
    auto avioes = ReadPlanes();
    a1.setAvioes(avioes);
    for(auto it = avioes.begin(); it!=avioes.end() ; it++){readFlights(a1,it->getMatricula());}
    readTickets(a1);
    auto e1=ReadEmployees();
    a1.setEmpregados(e1);
    auto p1 = ReadPassageiros();
    a1.setPassageiros(p1);
    auto t1 = ReadServicesToDo();
    a1.setToDo(t1);
    auto d1 = ReadServicesDone();
    a1.setDone(d1);

    while(Menus::airportMenu(a1)){}

}

