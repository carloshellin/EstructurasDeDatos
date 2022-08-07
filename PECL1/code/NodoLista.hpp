#ifndef NODOLISTA_HPP
#define NODOLISTA_HPP

#include "Box.hpp"

class NodoLista
{
public:
    NodoLista(Box *v, NodoLista *ant = NULL, NodoLista *sig = NULL);
    ~NodoLista();
    
private:
    Box *valor;
    NodoLista *anterior;
    NodoLista *siguiente;

    friend class Lista;
};

typedef NodoLista *pnodoLista;

#endif // NODOLISTA_HPP
