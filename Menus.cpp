#include "Menus.h"

int airportMenu() {
    cout << "_______________________________________________\n" << endl;
    cout << setw(20) << right << "Airport" << endl;
    cout << "_______________________________________________\n" << endl;
    cout << "1 - Flights\n";   //de aviões sai matrícula,tipo,capacidade,plano de voo e limpeza
    cout << "2 - Public Transportation\n"; //opções de transportes publicos perto do aeroporto
    cout << "3 - Tickets\n";
    cout << "\n0 - Exit\n";
    cout << "_______________________________________________\n" << endl;
    return ; //falta todos os return pq nao sei o que meter ainda
}

int planesMenu() {
    cout << "_______________________________________________\n" << endl;
    cout << setw(20) << right << "Flights" << endl;
    cout << "_______________________________________________\n" << endl;
    cout << "1 - Registration\n";   //lista de todas as matriculas
    cout << "2 - Type of plane\n";  //lista de todos os tipos de avioes
    cout << "3 - Capacity\n";       //lista de aviões e respetiva lotação
    cout << "4 - Flight plan\n";    //plano de voo
    cout << "5 - Luggage\n";        //mostra informação relativa a bagagem de todos os aviões
    cout << "6 - Maintenance/Cleaning\n";  //manutenção/limpeza
    cout << "\n0 - Exit\n";
    cout << "_______________________________________________\n" << endl;
    return ;
}

int flightsMenu() {
    cout << "_______________________________________________\n" << endl;
    cout << setw(20) << right << "Flight plan" << endl;
    cout << "_______________________________________________\n" << endl;
    cout << "1 - Flight number\n";
    cout << "2 - Departure\n";
    cout << "3 - Flight time\n";
    cout << "4 - Origin\n";
    cout << "5 - Destination\n";
    cout << "\n0 - Exit\n";
    cout << "_______________________________________________\n" << endl;
    return ;
}

int publicTransMenu() {
    cout << "_______________________________________________\n" << endl;
    cout << setw(20) << right << "Public Transportation" << endl;
    cout << "_______________________________________________\n" << endl;
    cout << "1 - Bus\n"; //distancia do aeroporto e horarios
    cout << "2 - Train\n"; //distancia do aeroporto e horarios
    cout << "3 - Subway\n"; //distancia do aeroporto e horarios
    cout << "4 - Cab\n"; //distancia do aeroporto e horarios
    cout << "\n0 - Exit\n";
    cout << "_______________________________________________\n" << endl;
    return ;
}

int ticketsMenu() {
    cout << "_______________________________________________\n" << endl;
    cout << setw(20) << right << "Tickets" << endl;
    cout << "_______________________________________________\n" << endl;
    cout << "1 - Buy tickets\n"; //escolhe voo e vê se tem espaço, escolhe a bagagem
    cout << "\n0 - Exit\n";
    cout << "_______________________________________________\n" << endl;
    return ;
}