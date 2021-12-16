//
// Created by Matilde on 15/12/2021.
//

#include "CarrinhoTransporte.h"

CarrinhoTransporte::CarrinhoTransporte(int IDCarrinho, int ncarruagens, int npilhas, int nmalas): IDcarrinho(IDCarrinho), ncarruagens(ncarruagens), npilhas(npilhas), nmalas(nmalas) {}

void CarrinhoTransporte::setncarruagens(int n) {
    ncarruagens = n;
}

void CarrinhoTransporte::setnpilhas(int n) {
    npilhas=n;

}

void CarrinhoTransporte::setnmalas(int n) {
    nmalas = n;
}

int CarrinhoTransporte::getncarruagens() const{
    return ncarruagens;
}

int CarrinhoTransporte::getnpilhas() const{
    return npilhas;
}

int CarrinhoTransporte::getnmalas() const{
    return nmalas;
}

bool CarrinhoTransporte::addBagagem(Bagagem b1) {
    if(carruagens.size() >= ncarruagens){return false;}
    for(std::stack f1: carruagens){
        if(carruagens.size() < getnpilhas()){
            f1.push(b1);
            return true;
        }
    }
    return false;
}

void CarrinhoTransporte::removeBagagem() {
    std::stack f1 = carruagens.back();
    f1.pop();
}
