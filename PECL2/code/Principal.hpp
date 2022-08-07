#ifndef PRINCIPAL_HPP
#define PRINCIPAL_HPP

#include <unistd.h>

#include "Arbol.hpp"
#include "Pila.hpp"
#include "Aeropuerto.hpp"

class Principal
{
public:
    Principal(Pila *pasajeros);
    ~Principal();
    
    float simulacion();
    
    bool llegada();
    bool salida();

private:
    Arbol *arbol;
    Pila *pasajeros;
    Aeropuerto aeropuerto;
    int pasajerosTotal;
};

#endif // PRINCIPAL_HPP
