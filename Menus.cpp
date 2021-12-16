#include "Menus.h"
#include "Airport.h"
#include "iterator"
#include "Airplane.h"

int planesMenu2(Airplane a1){
    int choice;

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

    if(choice==1){cout<<"Type of plane: "<<a1.getTipo()<<endl;}
    else if(choice==2){cout<<"Capacity: "<<a1.getCapacidade()<<" people."<<endl;}
    else if(choice == 3){
        cout << "Flight plan of plane "<<a1.getMatricula()<< endl;
        for(auto & it : a1.getPlanoVoo()){
            cout<< "Flight number "<< it.getNumVoo() <<": "<<endl;
            cout<<"Date: ";
            it.getData().printDate();
            cout<<" at: ";
            it.getData().printhour();
            cout<<" Origin: "<<it.getOrigem()<<" Destination: "<<it.getDestino()<<endl;
        }
    }

    else if (choice == 4){
        return 0;
    }

    cout<<endl<<"To go back to the main menu, enter 0: ";

    return 1;
}

int planesMenu1(Airport r1) {
    int number;

    cout << "_______________________________________________\n" << endl;
    cout << setw(20) << right << "Planes" << endl;
    cout << "_______________________________________________\n" << endl;
    cout << "All planes on record, identified by their license plate: "<<endl;

    for (int i=0; i<r1.getAvioes().size();i++){
        cout<<"Plane "<<i+1<<": "<<r1.getAvioes()[i].getMatricula()<<endl;
    }

    cout<<endl<<"If you wish to delete or know more about a certain plane, please enter its number. \nIf you wish to add a plane, "
                "please enter "<<r1.getAvioes().size()<<".\n If you wish to go back, please enter 0.\n Please enter a number: ";

    cin>>number;

    if(number!=0 && number<r1.getAvioes().size()){
        auto it = r1.getAvioes().begin();
        advance(it,number-1);

        if(!planesMenu2(*it)){r1.getAvioes().erase(it); cout<<"\nPlane successfully eliminated!"<<endl;}
    }

    if (number==0){return 1;}

    return 1;
}

int airportMenu(Airport a1) {
    int choice;
    cout << "_______________________________________________\n" << endl;
    cout << setw(20) << right << "Airport" << endl;
    cout << "_______________________________________________\n" << endl;
    cout << "1 - Planes\n";   //de aviões sai matrícula,tipo,capacidade,plano de voo e limpeza
    cout << "2 - Public Transportation\n"; //opções de transportes publicos perto do aeroporto
    cout << "3 - Tickets\n";
    cout << "4 - Employees"<<endl;
    cout << "5 - Flights"<<endl;
    cout << "6 - Bagage Transport Cars"<<endl;
    cout << "7 - Services"<<endl;
    cout << "\n0 - Exit\n";
    cout << "_______________________________________________\n" << endl;

    cout<< "Please enter a number: ";
    cin>>choice;

    if(choice == 1){
        planesMenu1(a1);
    }

    return 0; //falta todos os return pq nao sei o que meter ainda
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
    return 1;
}

int ticketsMenu() {
    cout << "_______________________________________________\n" << endl;
    cout << setw(20) << right << "Tickets" << endl;
    cout << "_______________________________________________\n" << endl;
    cout << "1 - Buy tickets\n"; //escolhe voo e vê se tem espaço, escolhe a bagagem
    cout << "\n0 - Exit\n";
    cout << "_______________________________________________\n" << endl;
    return 0;
}