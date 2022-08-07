#ifndef BOX_HPP
#define BOX_HPP

#include "Cola.hpp"

class Box
{
public:
    Box(char id = 'A');
    ~Box();
    
    void insertarCola(Pasajero *pasajero);
    void incrementarId();
    void mostrar();

    void setId(char id);
    char getId();
    void setPasajero(Pasajero *pasajero);
    Pasajero * getPasajero();
    Cola * getCola();
    
private:
    char id;
    Pasajero *pasajero;
    Cola *cola;
};

#endif // BOX_HPP
