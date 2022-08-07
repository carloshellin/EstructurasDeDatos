#include "NodoArbol.hpp"

NodoArbol::NodoArbol(Pasajero *pasajero, NodoArbol *izquierdo, NodoArbol *derecho)
{
    this->pasajero = pasajero;
    this->izquierdo = izquierdo;
    this->derecho = derecho;
}

NodoArbol::~NodoArbol()
{
}

