//
// Created by Matilde on 15/12/2021.
//

#ifndef AED2122_G53_CARRINHOTRANSPORTE_H
#define AED2122_G53_CARRINHOTRANSPORTE_H

#include <stack>
#include <vector>
#include "Bagagem.h"


class CarrinhoTransporte {

    int IDcarrinho, ncarruagens, npilhas, nmalas; //ncarruagens = numero de carruagens por carrinho, npilhas = num pilhas por carruagem , nmalas = num malas por pilha
    std::vector<std::stack<Bagagem>> carruagens;

public:
    CarrinhoTransporte(int IDCarrinho, int ncarruagens, int npilhas, int nmalas);
    void setncarruagens(int n);
    void setnpilhas(int n);
    void setnmalas(int n);

    std::vector<std::stack<Bagagem>> getCar();

    int getncarruagens() const;
    int getnpilhas() const;
    int getnmalas() const;

    bool addBagagem(Bagagem b1); //se adicionada com sucesso retorna true
    void removeBagagem(); //esta funcao assume que a bagagem é retirada primeiro da ultima carruagem e em ultimo vem a primeira carruagem

};


#endif //AED2122_G53_CARRINHOTRANSPORTE_H
