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
            std::string origem, destino, element, aux="";
            int day,month,year,starthour, startminute, durationhour,durationminute, numVoo, count=0;

            getline(f, element);
            char dud[element.size()+1];
            std::strcpy(dud,element.c_str());

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
    int IDTicket, numvooPassageiro;
    bool bagagem;
    float price;

    while(!f.eof()){
        getline(f,element);
        stringstream ss(element);

        ss>>IDTicket>>bagagem>>numvooPassageiro>>classe>>lugar>>price;

        Ticket t(IDTicket,bagagem,numvooPassageiro,classe,lugar,price);

        a1.addTicket(t);
    }

}
int main() {
    Airport a1("Porto");
    auto avioes  =  ReadPlanes();
    a1.setAvioes(avioes);

    readFlights(a1, "HH-33-HL");

    //cout<<a1.getAvioes().front().getMatricula();

    while(airportMenu(a1)){}

    return 0;
}


