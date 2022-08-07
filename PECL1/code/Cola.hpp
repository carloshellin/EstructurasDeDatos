#ifndef COLA_HPP
#define COLA_HPP

#include "NodoCola.hpp"

class Cola
{
public:
    Cola();
    ~Cola();
    
    void insertar(Pasajero *v);
    void insertarConPrioridad(Pasajero *v);
    Pasajero * eliminar();
    void mostrar(char id);
    
    pnodoCola getPrimero();
    int getLongitud();
    
private:
    pnodoCola primero, ultimo;
    int longitud;

};

#endif // COLA_HPP
