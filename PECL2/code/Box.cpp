#include "Box.hpp"

Box::Box(char id)
{
    this->id = id;
    pasajero = NULL;
    cola = new Cola();
}

void Box::insertarCola(Pasajero *pasajero)
{
    cola->insertarConPrioridad(pasajero);
}

void Box::incrementarId()
{
    id++;
}

bool Box::eliminarPasajero(Cola *cola, Cola *colaAtendidos, int tiempo)
{
    bool resultado = false;
    if (pasajero && pasajero->getDuracion() == 0)
    {
        pasajero->setHoraSalida(tiempo);
        colaAtendidos->insertarPorIdentificador(pasajero);
        
        pasajero = cola->eliminar();
        resultado = true;
    }
    
    return resultado;
}

void Box::mostrar()
{
    cout << "BOX " << id << "\t\t\t";
}

void Box::setId(char id)
{
    this->id = id;
}

char Box::getId()
{
    return id;
}

void Box::setPasajero(Pasajero *pasajero)
{
    this->pasajero = pasajero;
}

Pasajero *Box::getPasajero()
{
    return pasajero;
}

Cola * Box::getCola()
{
    return cola;
}

Box::~Box()
{
}