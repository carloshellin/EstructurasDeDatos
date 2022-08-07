#ifndef COLA_HPP
#define COLA_HPP

#include "NodoCola.hpp"

class Cola
{
public:
    Cola();
    ~Cola();
    
    void insertar(Pasajero *v);
    void insertarPorIdentificador(Pasajero *v);
    void insertarConPrioridad(Pasajero *v);
    Pasajero * eliminar();
    void mostrar(char id);
    float getTiempoMedioPasajeros();
    void estableceSatisfaccion();
    int getLongitud();
    
private:
    pnodoCola primero, ultimo;
    int longitud;

};

#endif // COLA_HPP
