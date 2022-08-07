#include "Pasajero.hpp"

Pasajero::Pasajero(int id, int prioridad, const char *paisDestino, int horaInicio, int duracion)
{
    this->id = id;
    this->idBox = 0;
    this->prioridad = prioridad;
    this->paisDestino = paisDestino;
    this->horaInicio = horaInicio;
    this->duracion = duracion;
}

void Pasajero::restarDuracion()
{
    duracion--;
}

void Pasajero::mostrar()
{
    cout << "\tPasajero " << id << " (TR = " << duracion << ")";
}

int Pasajero::getId()
{
    return id;
}

int Pasajero::getPrioridad()
{
    return prioridad;
}

int Pasajero::getHoraInicio()
{
    return horaInicio;
}

int Pasajero::getDuracion()
{
    return duracion;
}

Pasajero::~Pasajero()
{
}
