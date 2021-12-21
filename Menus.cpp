#include <fstream>
#include "Menus.h"
#include "Airport.h"
#include "iterator"
#include "Airplane.h"
#include <stdio.h>
#include <cstring>
#include "time.h"

/*por verificar*/
Time Menus::separateDateandHour(string date, string hour) {
    int day=-1, month=-1, year=-1, minute=-1, hour2=-1;
    char * pch;
    char date1[date.length() + 1], hour1[hour.length()+1];
    strcpy(date1, date.c_str());
    strcpy(hour1, hour.c_str());

    pch = strtok(date1,"/");
    while (pch != NULL)
    {
        // set the variables
        int num = atoi(pch);
        if(day == -1) day = num;
        else if(month == -1) month = num;
        else if(year == -1) year = num;

        // continue splitting the string
        pch = strtok (NULL, "/");
    }

    pch= strtok(hour1, ":");
    while (pch != NULL)
    {
        // set the variables
        int num = atoi(pch);
        if(hour2 == -1) hour2 = num;
        else if(minute == -1) minute = num;

        // continue splitting the string
        pch = strtok (NULL, "/");
    }

    Time t1(day,month,year,hour2, minute);

    return t1;
}

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
            cout<< "Flight number "<< it.getNumVoo() <<": "<<"Date: " << it.getData().printDate()<<" at "<<it.getData().printhour()<<". Flight duration is "<<it.getDuracao().printhour();
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

/*feito*/
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

/*feito*/
int Menus::airportMenu(Airport& a1) {
    int choice;
    cout << "_______________________________________________\n" << endl;
    cout << setw(20) << right << "Airport" << endl;
    cout << "_______________________________________________\n" << endl;
    cout << "1 - Planes\n";   //de aviões sai matrícula,tipo,capacidade,plano de voo e limpeza
    cout << "2 - Public Transportation\n"; //opções de transportes publicos perto do aeroporto
    cout << "3 - Tickets\n";
    cout << "4 - Employees"<<endl;
    cout << "5 - Baggage Transport Car"<<endl;
    cout << "6 - Services"<<endl;
    cout << "7 - Automatic check-in"<<endl;
    cout << "\n0 - Exit\n";
    cout << "_______________________________________________\n" << endl;

    cout<< "Please enter a number: ";
    cin>>choice;

    if(choice == 1){
        while(planesMenu1(a1)){}
        return 1;
    }

    else if (choice==0){return 0;}

    else if(choice == 3){
        while(ticketsMenu(a1)){}
        return 1;
    }

    else if(choice == 6){
        while(servicesMenu(a1)){}
        return 1;
    }

    else if(choice==2){
        while(publicTransMenu(a1)){}
        return 1;
    }

    else if(choice==7){while(checkinMenu(a1)){} return 1;}

    else if(choice==4){while(employeeMenu(a1)){} return 1;}

    else if(choice==5){
        while(carMenu(a1)){}
        return 1;
    }
    return 1;
}

/*feito*/
int Menus::publicTransMenu(Airport& a1) {
    int choice;
    cout << "_______________________________________________\n" << endl;
    cout << setw(20) << right << "Public Transportation" << endl;
    cout << "_______________________________________________\n" << endl;
    cout << "1 - Bus\n"; //distancia do aeroporto e horarios
    cout << "2 - Train\n"; //distancia do aeroporto e horarios
    cout << "3 - Subway\n"; //distancia do aeroporto e horarios
    cout << "\n0 - Exit\n";
    cout << "_______________________________________________\n" << endl;

    cout<<"Pleasese enter: ";
    cin>>choice;

    if(choice == 1){
        while(busMenu(a1)){}
    }

    else if(choice==2){
        while(trainMenu(a1)){}
    }

    else if(choice==3){
        while(subwayMenu(a1)){}
    }

    else if(choice==0){return 0;}

    return 1;
}

/*falta a possibilidade de eliminar ou alterar os atributos dos bilhetes: adicionar uma(ou mais) pessoas novas ao registo e associar a elas o bilhete*/
int Menus::ticketsMenu(Airport& a1) {
    int choice, manie, main;
    cout << "_______________________________________________\n" << endl;
    cout << setw(20) << right << "Tickets" << endl;
    cout << "_______________________________________________\n" << endl;
    cout << "1 - Buy tickets\n"; //escolhe voo e vê se tem espaço, escolhe a bagagem
    cout << "\n0 - Exit\n";
    cout << "_______________________________________________\n" << endl;

    cout<<"\nPlease enter: ";
    cin>>choice;

    if(choice==0){return 0;}
    else if(choice==1){
        int count=0, group, amount;
        bool bagagem;
        string classe;
        auto copy1 = a1.getAvioes();
        for (auto it=copy1.begin(); it!=copy1.end(); it++){
            auto copy2=it->getPlanoVoo();
            if(copy2.empty()){count++; continue;}
            for(auto it2=copy2.begin(); it2!=copy2.end();it2++){
                cout<< "Flight number "<< it2->getNumVoo() <<": "<<"\nDate: "<<it2->getData().printDate()<<" at: "<<it2->getData().printhour()<<"\nFlight duration: "<<it2->getDuracao().printhour()<<" Origin: "<<it2->getOrigem()<<" Destination: "<<it2->getDestino()<<"\n";
            }
        }
        if(count==copy1.size()){
            cout<<"\n\nCurrently, there are no planned flights.\n\nPlease enter 0 to return to main menu: ";
            cin>>count;
            return 0;
        }

        else{
            auto it2=copy1.begin();
            cout<<"Please enter the number of the flight you wish to buy a ticket for: ";
            cin>>manie;

            cout<<"\nWhat class do you wish to travel in? Write one of the follownig; first, economic or business: ";
            cin>>classe;

            cout<<"If this ticket belongs to a group trip, enter 1. If not, enter 0: ";
            cin>>group;

            Bagagem b1(a1.numBagaem(),a1.getTickets().size());
            Ticket t1(a1.getTickets().size(),b1, manie,classe);
            a1.addTicket(t1);

            addTicket(t1);

            if(group==0){
                addPerson(t1.getID(),a1);
            }
            if(group==1){
                cout<<"\nPlease enter the number of people in your group: ";
                cin>>amount;
                for(int i=1; i<amount;i++){addPerson(t1.getID(),a1);}
            }
        }
    }
    cout<<"\nTo return to the main menu, enter 0: ";
    cin>>main;
    if(!main){return 0;}
    return 1;
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

/*feito*/
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

    Time t1 = separateDateandHour(date,hora);
    Time t2 = separateHour(duracao);

    Flight f1(n,t1,t2);
    f1.setOrigem(origem);
    f1.setDestino(destino);

    //esta funcao escreve automaticamente no ficheiro
    a1.addFlight(f1);

    cout<<"\nPlane added successfully!"<<endl;

}

/*por verificar*/
void Menus::deleteVoo(Airplane &a1, Airport &r1) {
    int numb;
    cout<<"Please enter the number of the flight you wish to delete: ";
    cin>>numb;

    auto it = std::find_if(a1.getPlanoVoo().begin(), a1.getPlanoVoo().end(), [&numb](Flight obj) {return obj.getNumVoo() == numb;});

    //esta funcao tira do ficheiro de txt automaticamente
    a1.removeFlight(*it);
}

/*feito*/
void Menus::addTicket(Ticket &t1) {
    fstream f("ticket.txt", ios::app);
    f<<t1.getID()<<" "<<t1.getBagagem().getID()<<" "<<t1.getNumVoo()<<" "<<t1.getClasse()<<endl;
    f.close();
}

/*feito*/
void Menus::addPerson(int IDticket, Airport& a1) {
    std::string name,email,typeID,IDNUMB;
    int phone;
    cout<<"\nPlease enter the name of the passenger: ";
    cin>>name;
    cout<<"\nPlease enter the passenger's email: ";
    cin>>email;
    cout<<"\nPlease enter the type of your ID (passport, citizenship card, etc): ";
    cin>>typeID;
    cout<<"\nPlease enter the number of your ID: ";
    cin>>IDNUMB;
    cout<<"\nPlease enter your phone number: ";
    cin>>phone;

    Passenger pi(name,email,typeID,phone,IDNUMB,IDticket);

    a1.addPassageiro(pi);

    fstream f("passageiros.txt", ios::app);

    f<<name<<" "<<email<<" "<<typeID<<" "<<phone<<" "<<IDNUMB<<" "<<IDticket<<endl;

    f.close();

    cout<<"\nPerson added succesfully!"<<endl;

}

/*por verificar*/
int Menus::servicesMenu(Airport &a1) {
    int choice, IDemployee, hc;
    string type, date, hour;
    cout << "_______________________________________________\n" << endl;
    cout << setw(20) << right << "Services" << endl;
    cout << "_______________________________________________\n" << endl;
    cout << "1 - Add Service to To Do list\n";
    cout << "2 - Move Service from To Do list to completed services\n";
    cout << "3 - Display the completed services\n";
    cout << "4 - Display the services yet to be done\n";
    cout << "0 - Go back to main menu\n";

    cout<<"\nPlease enter: ";
    cin>>choice;

    if(choice == 0){return 0;}

    else if(choice == 1){
        cout<<"\nPlease enter the type of service (cleaning or maintenance): ";
        cin>>type;
        cout<<"\nPlease enter the day of the service in DD/MM/YYYY format: ";
        cin>>date;
        cout<<"\nPlease enter the time of day of the service in HH:MM format: ";
        cin>>hour;
        cout<<"\nPlease enter the ID of the employee that will perform the service: ";
        cin>>IDemployee;

        Time t1 = separateDateandHour(date,hour);

        Service s1(type, t1, reinterpret_cast<string &>(IDemployee));

        a1.addService(s1);

        fstream fire("servicosToDo.txt", ios::app);
        fire<<type<<" "<<date<<" "<<hour<<" "<<IDemployee<<endl;
        fire.close();

        cout<<"\nService added succesfully! To return enter 0: ";
        cin>>hc;
        return 1;
    }

    else if(choice==2){
        a1.removeService();
        fstream fer("servicosToDo.txt");
        auto copy = a1.getToDo();
        auto cur = copy.front();
        copy.pop();
        while(!copy.empty()){
            fer<<copy.front().getType()<<" "<<copy.front().getTime().printDate()<<" "<<copy.front().getTime().printhour()<<" "<<copy.front().getID()<<endl;
        }
        fer.close();

        fstream fire("servicosDone.txt", ios::app);

        fire<<cur.getType()<<" "<<cur.getTime().printDate()<<" "<<cur.getTime().printhour()<<" "<<cur.getID()<<endl;
        fire.close();

        cout<<"\nService completed succesfully! To return enter 0: ";
        cin>>hc;
        return 1;
    }

    else if(choice == 3){
        queue<Service> copy = a1.getDone();
        if(copy.empty()){cout<<"\nNo services currently planned. To return enter 0: ";cin>>hc; return 1;}
        else while(!copy.empty()){
            cout<<"\nType of service: "<<copy.front().getType()<<" Time and day of service: "
            <<copy.front().getTime().printDate()<<" at "<<copy.front().getTime().printhour()<<
            " performed by employee number "<<copy.front().getID()<<".\n";

            copy.pop();
        }

        cout <<"\n\nTo return enter 0: "; cin>>hc; return 1;
    }

    else if(choice == 4){
        queue<Service> copy = a1.getToDo();
        if(copy.empty()){cout<<"\nNo services currently planned. To return enter 0: ";cin>>hc; return 1;}
        else while(!copy.empty()){
                cout<<"\nType of service: "<<copy.front().getType()<<" Time and day of service: "
                    <<copy.front().getTime().printDate()<<" at "<<copy.front().getTime().printhour()<<
                    " performed by employee number "<<copy.front().getID()<<".\n";

                copy.pop();
            }

        cout <<"\n\nTo return enter 0: "; cin>>hc; return 1;
    }


    return 1;
}

/*por verificar*/
int Menus::busMenu(Airport &a1) {

    int choice,hc;
    cout << "_______________________________________________\n" << endl;
    cout << setw(20) << right << "Bus" << endl;
    cout << "_______________________________________________\n" << endl;
    cout << "1 - Display all bus stations"<<endl;
    cout << "2 - Add a bus station\n";
    cout << "3 - Delete bus station\n";
    cout << "0 - Return to Transportation Menu\n";
    cout << "\nPlease enter: ";
    cin>>choice;

    if(choice==1){
        int count=1;
        BST<Transportation> copy = a1.getTransporte();
        for(auto it = copy.begin(); it!=copy.end() ; it++){
            if((*it).getTipo()=="bus"){
                cout<<"\nBus station number "<<count<<": Scheduled time: "<<(*it).getSchedule().printhour()<<
                    " Distance from Airport: "<<(*it).getDistance()<<endl;
                count++;
            }
        }
        if(count==1){cout<<"\nNo bus stations on record.";}
        cout << "\n\nTo go back, enter 0: ";
        cin>>hc;
        return 1;
    }

    else if(choice==0){
        return 0;
    }
    else if(choice==2){
        string hora;
        float distance;
        cout<<"\nPlease enter the time at which the bus will come, in HH:MM format: ";
        cin>>hora;
        cout<<"\nPlease enter the distance of the bus station to the airport: ";
        cin>>distance;
        Time t2 = separateHour(hora);
        Transportation t12("bus",distance,t2);
        a1.addTransporte(t12);
        cout<<"\nBus Station added successfully! To go back, enter 0: ";
        cin>>hc;
        return 1;
    }

    else if(choice==3){
        int count=1,hc,number;
        BST<Transportation> copy = a1.getTransporte();
        vector<iteratorBST<Transportation>> aux;
        for(auto it = copy.begin(); it!=copy.end() ; it++){
            if((*it).getTipo()=="bus"){
                aux.push_back(it);
                cout<<"\nBus station number "<<count<<": Scheduled time: "<<(*it).getSchedule().printhour()<<
                    " Distance from Airport: "<<(*it).getDistance()<<endl;
                count++;
            }
        }

        if(count==1){cout<<"\nNo train stations on record.";}
        else{cout<<"\nPlease enter the number of the station you wish to delete: ";
        cin>>number;

        copy.remove(*aux[number-1]);
        a1.setTransporte(copy);

        cout<<"\nBus station deleted successfully!";}

        cout<<"\nTo go back, enter 0: ";
        cin>>hc;
        return 1;
    }

    return 1;
}

/*feito*/
Time Menus::separateHour(string hour) {
    int minute=-1, hour2=-1;
    char * pch;
    char hour1[hour.length()+1];
    strcpy(hour1, hour.c_str());

    pch= strtok(hour1, ":");
    while (pch != NULL)
    {
        // set the variables
        int num = atoi(pch);
        if(hour2 == -1) hour2 = num;
        else if(minute == -1) minute = num;

        // continue splitting the string
        pch = strtok (NULL, "/");
    }

    Time t1(hour2, minute);

    return t1;
}

/*por verificar*/
int Menus::trainMenu(Airport &a1) {

    int choice,hc;
    cout << "_______________________________________________\n" << endl;
    cout << setw(20) << right << "Train" << endl;
    cout << "_______________________________________________\n" << endl;
    cout << "1 - Display all train stations"<<endl;
    cout << "2 - Add a train station\n";
    cout << "3 - Delete train station\n";
    cout << "0 - Return to Transportation Menu\n";
    cout << "\nPlease enter: ";
    cin>>choice;

    if(choice==1){
        int count=1;
        BST<Transportation> copy = a1.getTransporte();
        for(auto it = copy.begin(); it!=copy.end() ; it++){
            if((*it).getTipo()=="train"){
                cout<<"\nTrain station number "<<count<<": Scheduled time: "<<(*it).getSchedule().printhour()<<
                    " Distance from Airport: "<<(*it).getDistance()<<endl;
                count++;
            }
        }
        if(count==1){cout<<"\nNo train stations on record.";}
        cout << "\n\nTo go back, enter 0: ";
        cin>>hc;
        return 1;
    }

    else if(choice==0){
        return 0;
    }
    else if(choice==2){
        string hora;
        float distance;
        cout<<"\nPlease enter the time at which the train will come, in HH:MM format: ";
        cin>>hora;
        cout<<"\nPlease enter the distance of the train station to the airport: ";
        cin>>distance;
        Time t2 = separateHour(hora);
        Transportation t12("bus",distance,t2);
        a1.addTransporte(t12);
        cout<<"\nTrain Station added successfully! To go back, enter 0: ";
        cin>>hc;
        return 1;
    }

    else if(choice==3){
        int count=1,hc,number;
        BST<Transportation> copy = a1.getTransporte();
        vector<iteratorBST<Transportation>> aux;
        for(auto it = copy.begin(); it!=copy.end() ; it++){
            if((*it).getTipo()=="train"){
                aux.push_back(it);
                cout<<"\nTrain station number "<<count<<": Scheduled time: "<<(*it).getSchedule().printhour()<<
                    " Distance from Airport: "<<(*it).getDistance()<<endl;
                count++;
            }
        }

        if(count==1){cout<<"\nNo train stations on record.";}

        else {cout<<"\nPlease enter the number of the station you wish to delete: ";
        cin>>number;

        copy.remove(*aux[number-1]);
        a1.setTransporte(copy);

        cout<<"\nTrain station deleted successfully!";
        }
        cout<<"\nTo go back, enter 0: ";
        cin>>hc;
        return 1;
    }
    return 1;

}

/*por verificar*/
int Menus::subwayMenu(Airport &a1) {
    int choice,hc;
    cout << "_______________________________________________\n" << endl;
    cout << setw(20) << right << "Subway" << endl;
    cout << "_______________________________________________\n" << endl;
    cout << "1 - Display all subway stations"<<endl;
    cout << "2 - Add a subway station\n";
    cout << "3 - Delete subway station\n";
    cout << "0 - Return to Transportation Menu\n";
    cout << "\nPlease enter: ";
    cin>>choice;

    if(choice==1){
        int count=1;
        BST<Transportation> copy = a1.getTransporte();
        for(auto it = copy.begin(); it!=copy.end() ; it++){
            if((*it).getTipo()=="subway"){
                cout<<"\nSubway station number "<<count<<": Scheduled time: "<<(*it).getSchedule().printhour()<<
                    " Distance from Airport: "<<(*it).getDistance()<<endl;
                count++;
            }
        }
        if(count==1){cout<<"\nNo Subway stations on record.";}
        cout << "\n\nTo go back, enter 0: ";
        cin>>hc;
        return 1;
    }

    else if(choice==0){
        return 0;
    }
    else if(choice==2){
        string hora;
        float distance;
        cout<<"\nPlease enter the time at which the subway will come, in HH:MM format: ";
        cin>>hora;
        cout<<"\nPlease enter the distance of the subway station to the airport: ";
        cin>>distance;
        Time t2 = separateHour(hora);
        Transportation t12("bus",distance,t2);
        a1.addTransporte(t12);
        cout<<"\nSubway Station added successfully! To go back, enter 0: ";
        cin>>hc;
        return 1;
    }

    else if(choice==3){
        int count=1,hc,number;
        BST<Transportation> copy = a1.getTransporte();
        vector<iteratorBST<Transportation>> aux;
        for(auto it = copy.begin(); it!=copy.end() ; it++){
            if((*it).getTipo()=="train"){
                aux.push_back(it);
                cout<<"\nSubway station number "<<count<<": Scheduled time: "<<(*it).getSchedule().printhour()<<
                    " Distance from Airport: "<<(*it).getDistance()<<endl;
                count++;
            }
        }

        if(count==1){cout<<"\nNo subway stations on record.";}

        else{cout<<"\nPlease enter the number of the station you wish to delete: ";
        cin>>number;

        copy.remove(*aux[number-1]);
        a1.setTransporte(copy);

        cout<<"\nSubway station deleted successfully!";}

        cout<<"\nTo go back, enter 0: ";
        cin>>hc;
        return 1;
    }

    return 1;
}

/*por verificar*/
int Menus::checkinMenu(Airport &a1) {
    int ticknumb,hc;
    cout << "_______________________________________________\n" << endl;
    cout << setw(20) << right << "Automatic Check-In" << endl;
    cout << "_______________________________________________\n" << endl;
    cout << "\nPlease enter the number of your ticket: "<<endl;
    cin>>ticknumb;

    auto it = std::find_if(a1.getTickets().begin(), a1.getTickets().end(), [&ticknumb](Ticket& obj) {return obj.getID() == ticknumb;});

    if(it!=a1.getTickets().end()){
        if(a1.getCarrinhos().addBagagem(Bagagem (a1.numBagaem(),(*it).getID()))){}
        else{cout<<"No space available in the baggage transport car. Check-in unsuccessful, to go back, enter 0: ";cin>>hc;return 0;}
    }

    cout<<"\nCheck-In successful, have a nice flight! To go back enter 0: ";
    cin>>hc;
    return 0;
}

/*por verificar*/
int Menus::employeeMenu(Airport &a1) {
    int choice,hc, count=0, phone;
    string name, numb, email;
    cout << "_______________________________________________\n" << endl;
    cout << setw(20) << right << "Employees" << endl;
    cout << "_______________________________________________\n" << endl;
    cout << "1 - Display list of all employees"<<endl;
    cout << "2 - Display list of tasks assigned to an employee"<<endl;
    cout << "3 - Remove an employee"<<endl;
    cout << "4 - Add an employee"<<endl;
    cout << "0 - Go back to airport menu"<<endl;
    cout << "\nPlease enter: ";
    cin>>choice;

    if(choice==0){return 0;}

    else if(choice==1){
        for(Employee& e1: a1.getEmpregados()){
            cout<<"\nEmployee ID: "<<e1.getID()<<" Name: "<<e1.getName()<<endl;
        }
        if(a1.getEmpregados().empty()){cout<<"\nNo employees on record. ";}
        cout<<"To go back, enter 0: ";
        cin>>hc;
        return 1;
    }

    else if(choice==2){
        cout<<"\nPlease enter the ID of the employee: ";
        cin>>numb;
        auto copy = a1.getToDo();
        while(!copy.empty()){
            if(copy.front().getID() == numb){
                cout<<"\nType of service: "<<copy.front().getType()<<" Time and day of service: "
                    <<copy.front().getTime().printDate()<<" at "<<copy.front().getTime().printhour()<<".\n";
                count++;
            }
            copy.pop();
        }

        if(count==0){cout<<"\nNo services assigned to this employee. ";}
        cout<<"To go back, enter 0: ";
        cin>>hc;
        return 1;

    }

    else if(choice==3){
        cout<<"\nPlease enter the ID of the employee you wish to remove: ";
        cin>>numb;
        auto it = find_if(a1.getEmpregados().begin(),a1.getEmpregados().end(),[&numb](Employee& e1){return e1.getID()==numb;});

        if(it!=a1.getEmpregados().end()){
            //esta funcao altera ja o ficheiro de texto
            a1.removeEmpregado(it);
            cout<<"\nEmployee removed successfully! To go back, enter 0: ";
            cin>>hc;
            return 1;
        }

        else{
            cout<<"\nEmployee does not exist. To go back, enter 0: ";
            cin >>hc;
            return 1;
        }

    }

    else if(choice==4){
        cout << "\nPlease enter the name of the employee: ";
        cin>>name;
        cout << "\nPlease enter the employee's email: ";
        cin>>email;
        cout << "\nPlease enter the employee's phone number: ";
        cin>>phone;

        //esta funcao altera ja o ficheiro de texto
        a1.addEmpregado(Employee(name,email,phone, to_string(a1.getEmpregados().size())));

        cout<<"\nEmployee added succesfully. To go back, enter 0: ";
        cin>>hc;
        return 1;
    }

    return 1;

}

/*por verificar*/
int Menus::carMenu(Airport &a1) {
    int choice,numb,hc;
    cout << "_______________________________________________\n" << endl;
    cout << setw(20) << right << "Baggage Transport Car" << endl;
    cout << "_______________________________________________\n" << endl;
    cout << "1 - Change the amount of carriages"<<endl;
    cout << "2 - Change the amount of stacks per carriages"<<endl;
    cout << "3 - Change the amount of baggage per stack"<<endl;
    cout << "4 - Display all baggage on transport"<<endl;
    cout << "0 - Go back"<<endl;
    cout << "\nPlease enter: ";

    cin>>choice;

    if(choice==0){return 0;}

    else if(choice==1){
        cout << "\nThe current amount of carriages is "<<a1.getCarrinhos().getncarruagens()<<". Please enter the new amount: ";
        cin >> numb;
        a1.getCarrinhos().setncarruagens(numb);
        cout << "\nAmount of carriages changed successfully! To go back, please enter 0: ";
        cin >> hc;
        return 1;
    }

    else if(choice==2){
        cout << "\nThe current amount of stacks per carriage is "<<a1.getCarrinhos().getnpilhas()<<". Please enter the new amount: ";
        cin>>numb;
        a1.getCarrinhos().setnpilhas(numb);
        cout<<"\nAmount of carriages changed successfully! To go back, please enter 0: ";
        cin>>hc;
        return 1;
    }

    else if(choice==3){
        cout << "\nThe current amount of baggage per stack is "<<a1.getCarrinhos().getnmalas()<<". Please enter the new amount: ";
        cin>>numb;
        a1.getCarrinhos().setnmalas(numb);
        cout<<"\nAmount of baggage changed successfully! To go back, please enter 0: ";
        cin>>hc;
        return 1;
    }

    else if(choice==4){
        auto copy = a1.getCarrinhos().getCar();
        for (auto it=copy.begin(); it!=copy.end() ; it++){
            cout << "\nBaggage number "<<it->top().getID();
        }
        if(copy.empty()){cout<<"\nNo baggage on the car. To go back, enter 0: "; cin>>hc; return 1;}
        else{cout<<"\nTo go back, enter 0: "; cin>>hc; return 1;}
    }

    return 1;
}

