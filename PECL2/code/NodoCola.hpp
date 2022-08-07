#ifndef NODOCOLA_HPP
#define NODOCOLA_HPP

#include "Pasajero.hpp"

class NodoCola
{
public:
    NodoCola(Pasajero *v, NodoCola *sig = NULL);
    ~NodoCola();
    
private:
    Pasajero *valor;
    NodoCola *siguiente;
    
public:   
    friend class Cola;
};

typedef NodoCola *pnodoCola;

#endif // NODOCOLA_HPP
