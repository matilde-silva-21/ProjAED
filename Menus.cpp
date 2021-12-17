#include <fstream>
#include "Menus.h"
#include "Airport.h"
#include "iterator"
#include "Airplane.h"

/*feito*/
int Menus::planesMenu2(Airplane& a1, int &check) {
    int choice, crux;

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
        cout << endl<<"Flight plan of plane "<<a1.getMatricula()<< endl;
        for(auto & it : a1.getPlanoVoo()){
            cout<< "Flight number "<< it.getNumVoo() <<": "<<endl;
            cout<<"Date: ";
            it.getData().printDate();
            cout<<" at: ";
            it.getData().printhour();
            cout<<" Origin: "<<it.getOrigem()<<" Destination: "<<it.getDestino()<<endl;
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

/*falta a adicao de um aviao e remocao de um do txt file*/
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
        while(planesMenu2(*(it), check)){}
        if(check!=0){
            copy.erase(it);
            r1.setAvioes(copy);
            cutfromfile(number, it->getMatricula());
            cout<<"\nPlane successfully eliminated!"<<endl;
        }
        return 1;
    }

    if (number==0){return 0;}

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
    cout << "5 - Flights"<<endl;
    cout << "6 - Bagage Transport Cars"<<endl;
    cout << "7 - Services"<<endl;
    cout << "\n0 - Exit\n";
    cout << "_______________________________________________\n" << endl;

    cout<< "Please enter a number: ";
    cin>>choice;

    if(choice == 1){
        while(planesMenu1(a1)){}
    }

    if (choice==0){return 1;}

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
    cout << "_______________________________________________\n" << endl;
    cout << setw(20) << right << "Tickets" << endl;
    cout << "_______________________________________________\n" << endl;
    cout << "1 - Buy tickets\n"; //escolhe voo e vê se tem espaço, escolhe a bagagem
    cout << "\n0 - Exit\n";
    cout << "_______________________________________________\n" << endl;
    return 0;
}

void Menus::cutfromfile(int index, const string& matricula) {
    int count = 1;
    std::vector<std::string> temp;
    string ele;

    ifstream f("aviao"+matricula+".txt");

    while(!f.eof()){
        if(count==index){continue;}
        else{
            getline(f, ele);
            temp.push_back(ele);
            count++;
        }
    }

    f.close();

    for (string& line: temp){
        //escrever em aviao com a funcao do domingos
    }
}
