#include "Principal.hpp"

Principal::Principal(Pila *pasajeros)
{
    this->pasajeros = pasajeros;
    this->pasajerosTotal = pasajeros->getLongitud();
}

float Principal::simulacion()
{
    while (true)
    {
        const char *evento = "";
        
        if (llegada())
        {
            evento = "Llegada";
        }
        
        if (salida())
        {
            evento = "Salida";
        }
        
        aeropuerto.mostrar(evento);
        
        if (aeropuerto.estaVacio() && pasajeros->getLongitud() == 0)
        {
            return (float) (aeropuerto.getTiempoBoxes() + aeropuerto.getTiempoCola()) / (float) pasajerosTotal;
        }
        
        aeropuerto.actualizarTiempos();
        sleep(1);
    }
}

bool Principal::llegada()
{
    bool resultado = false;
    
    Pasajero *pasajero = pasajeros->extraer();
    while (pasajero && pasajero->getHoraInicio() == aeropuerto.getTiempo())
    {
        aeropuerto.entraBox(pasajero);
        resultado = true;
        
        pasajero = pasajeros->extraer();
    }
    
    if (pasajero) pasajeros->insertar(pasajero);
    
    return resultado;
}

bool Principal::salida()
{
    return aeropuerto.saleBox();
}

Principal::~Principal()
{
}

