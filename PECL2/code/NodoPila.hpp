#ifndef NODOPILA_HPP
#define NODOPILA_HPP

#include "Pasajero.hpp"

class NodoPila
{
public:
    NodoPila(Pasajero *v, NodoPila *sig = NULL);
    ~NodoPila();
    
private:
    Pasajero *valor;
    NodoPila *siguiente;
    
    friend class Pila;
};

typedef NodoPila *pnodoPila;    

#endif // NODOPILA_HPP