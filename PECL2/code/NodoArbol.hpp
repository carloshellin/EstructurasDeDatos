#ifndef NODOARBOL_HPP
#define NODOARBOL_HPP

#include "Pasajero.hpp"

class NodoArbol
{
public:
    NodoArbol(Pasajero *pasajero, NodoArbol *izquierdo = NULL, NodoArbol *derecho = NULL);
    ~NodoArbol();
private:
    Pasajero *pasajero;
    NodoArbol *izquierdo;
    NodoArbol *derecho;
    
    friend class Arbol;
};

typedef NodoArbol *pnodoArbol;

#endif // NODOARBOL_HPP
