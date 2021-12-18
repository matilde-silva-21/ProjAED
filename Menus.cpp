#include <fstream>
#include "Menus.h"
#include "Airport.h"
#include "iterator"
#include "Airplane.h"
#include <stdio.h>
#include <cstring>
#include "time.h"

/*feito*/
int Menus::planesMenu2(Airplane& a1, int &check, Airport& r1) {
    int choice, crux,men, another;

    cout << "_______________________________________________\n" << endl;
    cout << setw(20) << right << "Plane "<< a1.getMatricula()<< endl;
    cout << "_______________________________________________\n" << endl;
    cout << "1 - Type of plane\n";  //lista de todos os tipos de avioes
    cout << "2 - Capacity\n";       //lista de aviões e respetiva lotação
    cout << "3 - Flight plan\n";    //plano de voo
    cout << "4 - Delete plane\n";
    cout << "\n0 - Exit\n";
    cout << "_______________________________________________\n" << endl;

    cout<<endl<<"Please enter a number: ";

    cin>>choice;

    if(choice==1){cout<<"\nType of plane: "<<a1.getTipo()<<endl;}
    else if(choice==2){cout<<"\nCapacity: "<<a1.getCapacidade()<<" people."<<endl;}
    else if(choice == 3){
        if(a1.getPlanoVoo().empty()){
            cout<<"\nNo flights planned for this plane.\nIf you wish to add a flight enter 1.\nIf you wish to go back enter 0: ";
            cin>>men;
            if(men==1){addVoo(a1,r1);}
            else{return 1;}
        }
        else{
            cout << endl<<"\nFlight plan of plane "<<a1.getMatricula()<< endl;
            for(auto & it : a1.getPlanoVoo()){
            cout<< "Flight number "<< it.getNumVoo() <<": "<<endl;
            cout<<"Date: ";
            it.getData().printDate();
            cout<<" at: ";
            it.getData().printhour();
            cout<<" Origin: "<<it.getOrigem()<<" Destination: "<<it.getDestino()<<endl;
        }

            cout<<"\n\nIf you wish to add a flight enter 1.\nIf you wish to delete a flight enter 2.\nIf you wish to go back enter 0: ";

            cin>>another;

            if(another==1){addVoo(a1,r1);}
            else if(another==2){deleteVoo(a1,r1);}
            else if(another==0){return 1;}
        }
    }

    else if (choice == 0){
        return 0;
    }

    else if (choice == 4){
        check++;
        return 0;
    }

    cout<<endl<<"To go back, enter 0: ";

    cin>>crux;

    return 1;
}

/*feito (a excecao das funcoes que chama que algumas estao incompletas mas se arranjar as outras esta ja esta feita)*/
int Menus::planesMenu1(Airport& r1) {
    int number;

    cout << "______________________________________________\n" << endl;
    cout << setw(20) << right << "Planes" << endl;
    cout << "_______________________________________________\n" << endl;
    cout << "All planes on record, identified by their license plate: \n"<<endl;

    for (int i=0; i<r1.getAvioes().size();i++){
        cout<<"Plane "<<i+1<<": "<<r1.getAvioes()[i].getMatricula()<<endl;
    }

    cout<<endl<<"If you wish to delete or know more about a certain plane, please enter its number. \nIf you wish to add a plane, "
                "please enter "<<r1.getAvioes().size()+1<<".\nIf you wish to go back, please enter 0.\n\nPlease enter a number: ";

    cin>>number;

    if(number!=0 && number<=r1.getAvioes().size()){
        auto copy = r1.getAvioes();
        auto it = copy.begin();
        int check = 0;
        it = (it+number-1);
        while(planesMenu2(*(it), check, r1)){}
        if(check!=0){
            copy.erase(it);
            r1.setAvioes(copy);
            cutfromfile(r1, number-1);
            cout<<"\nPlane successfully eliminated!"<<endl;
        }
        return 1;
    }

    else if (number==0){return 0;}
    else if(number==r1.getAvioes().size()+1){
        addPlane(r1);
        return 1;
    }

    return 1;
}

int Menus::airportMenu(Airport& a1) {
    int choice;
    cout << "_______________________________________________\n" << endl;
    cout << setw(20) << right << "Airport" << endl;
    cout << "_______________________________________________\n" << endl;
    cout << "1 - Planes\n";   //de aviões sai matrícula,tipo,capacidade,plano de voo e limpeza
    cout << "2 - Public Transportation\n"; //opções de transportes publicos perto do aeroporto
    cout << "3 - Tickets\n";
    cout << "4 - Employees"<<endl;
    cout << "5 - Bagage Transport Cars"<<endl;
    cout << "6 - Services"<<endl;
    cout << "\n0 - Exit\n";
    cout << "_______________________________________________\n" << endl;

    cout<< "Please enter a number: ";
    cin>>choice;

    if(choice == 1){
        while(planesMenu1(a1)){}
    }

    if (choice==0){return 1;}

    if(choice == 3){
        while(ticketsMenu()){}
    }

    return 0;
}

int Menus::publicTransMenu() {
    cout << "_______________________________________________\n" << endl;
    cout << setw(20) << right << "Public Transportation" << endl;
    cout << "_______________________________________________\n" << endl;
    cout << "1 - Bus\n"; //distancia do aeroporto e horarios
    cout << "2 - Train\n"; //distancia do aeroporto e horarios
    cout << "3 - Subway\n"; //distancia do aeroporto e horarios
    cout << "4 - Cab\n"; //distancia do aeroporto e horarios
    cout << "\n0 - Exit\n";
    cout << "_______________________________________________\n" << endl;
    return 1;
}

int Menus::ticketsMenu() {
    int choice;
    cout << "_______________________________________________\n" << endl;
    cout << setw(20) << right << "Tickets" << endl;
    cout << "_______________________________________________\n" << endl;
    cout << "1 - Buy tickets\n"; //escolhe voo e vê se tem espaço, escolhe a bagagem
    cout << "\n0 - Exit\n";
    cout << "_______________________________________________\n" << endl;

    cin>>choice;

    if(choice==0){return 0;}
    else if(choice==1){

    }
}

/*feito*/
void Menus::cutfromfile(Airport& a1, int index) {
    string matricula = (a1.getAvioes().begin()+index)->getMatricula();
    string filename = "aviao"+matricula+".txt";
    char filename1[filename.size()+1];
    strcpy(filename1, filename.c_str());
    fstream  afile;
    afile.open("avioes.txt", ios::out | ios::in );
    for(Airplane& a1: a1.getAvioes()){
        afile<<a1.getMatricula()<<" "<<a1.getTipo()<<" "<<a1.getCapacidade()<<endl;
    }

    afile.close();

}

/*feito*/
void Menus::addPlane(Airport &a1) {
    string matricula,tipo;
    int capacidade;
    cout<<"\nPlease enter the license plate in format XX-XX-XX: ";
    cin>>matricula;
    cout<<"\nPlease enter the type of the airplane in format XNNN: ";
    cin>>tipo;
    cout<<"\nPlease enter the capacity: ";
    cin>>capacidade;

    Airplane avi(matricula, tipo, capacidade);

    a1.addPlane(avi);

    fstream f("avioes.txt", ios::app);
    f<<matricula<<" "<<tipo<<" "<<capacidade<<endl;
    f.close();

    cout<<"\nPlane added succesfully!";
}

/*esta funcao tem que separar corretamente as datas ainda */
void Menus::addVoo(Airplane& a1, Airport& r1) {
    int n = r1.numberOfFilgths();
    string date, hora, duracao, origem, destino;

    cout<<"\nPlease enter the flight date in format DD/MM/YYYY: ";
    cin>>date;
    cout<<"\nPlease enter the time of the flight in HH:MM format: ";
    cin>>hora;
    cout<<"\nPlease enter the duration of the flight in HH:MM format: ";
    cin>>duracao;
    cout<<"\nPlease enter the origin city: ";
    cin>>origem;
    cout<<"\nPlease enter the destination city: ";
    cin>>destino;

    int day,month,year,hour1, minute1, hour2, minute2;
    string cur;
    int count=0;

    for(char c: date){
        if(c=='/'){
            if (count==0){day= stoi(cur); cur="";count++;}
            else if(count==1){month= stoi(cur); cur="";count++;}
            else if(count==2){year=stoi(cur); cur="";}
        }
        else{
            cur+=c;
        }
    }

    cur="";
    for(char c: hora){
        if(c==':'){
            if (count==0){hour1= stoi(cur); cur="";count++;}
            else if(count==1){minute1= stoi(cur);cur=""; }
        }
        else{
            cur+=c;
        }
    }

    cur="";
    for(char c: duracao){
        if(c==':'){
            if (count==0){hour2= stoi(cur);cur=""; count++;}
            else if(count==1){minute2= stoi(cur); cur="";}
        }
        else{
            cur+=c;
        }
    }

    Time t1(day,month,year,hour1,minute1);
    Time t2(hour2,minute2);

    Flight f1(n,t1,t2);
    f1.setOrigem(origem);
    f1.setDestino(destino);

    a1.addFlight(f1);

    cout<<"\nPlane added successfully!"<<endl;

    addFlightFile(a1);
}

/*esta funcao tem que tratar de criar ficheiros e meter la dentro voos*/
void Menus::addFlightFile(Airplane &a1) {
    fstream f("aviao"+a1.getMatricula()+".txt", ios::out | ios::in);
    for(Flight& f1: a1.getPlanoVoo()){
        f<<f1.getNumVoo();
        f1.getData().printDate();
        f1.getData().printhour();
        f<<" ";
        f1.getDuracao().printhour();
        f<<" "<<f1.getDestino()<<" "<<f1.getOrigem()<<endl;
    }
    f.close();
}

/*falta a parte em que tira do ficheiro o voo*/
void Menus::deleteVoo(Airplane &a1, Airport &r1) {
    int numb;
    cout<<"Please enter the number of the flight you wish to delete: ";
    cin>>numb;

    auto it = std::find_if(a1.getPlanoVoo().begin(), a1.getPlanoVoo().end(), [&numb](Flight obj) {return obj.getNumVoo() == numb;});

    a1.removeFlight(*it);
}
