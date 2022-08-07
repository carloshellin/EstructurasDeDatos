#ifndef PILA_HPP
#define PILA_HPP

#include "NodoPila.hpp"

class Pila
{
public:
    Pila();
    ~Pila();
    void insertar(Pasajero *v);
    Pasajero * extraer();
    void mostrar();
    
    int getLongitud();
    
private:
    pnodoPila ultimo;
    int longitud;
};

#endif // PILA_HPP