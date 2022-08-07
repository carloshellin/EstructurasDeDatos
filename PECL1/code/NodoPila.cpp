#include "NodoPila.hpp"

NodoPila::NodoPila(Pasajero *pasajero, NodoPila *sig)
{
    valor = pasajero;
    siguiente = sig;
}

NodoPila::~NodoPila()
{
}