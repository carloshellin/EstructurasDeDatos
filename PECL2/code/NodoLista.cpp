#include "NodoLista.hpp"

NodoLista::NodoLista(Box *v, NodoLista *ant, NodoLista *sig)
{
    valor = v;
    anterior = ant;
    siguiente = sig;
}

NodoLista::~NodoLista()
{
}

