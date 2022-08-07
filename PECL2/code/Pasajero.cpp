#include "Pasajero.hpp"

Pasajero::Pasajero(int id, int prioridad, const char* paisDestino, int horaInicio, int duracion)
{
    this->id = id;
    this->idBox = 0;
    this->prioridad = prioridad;
    this->paisDestino = paisDestino;
    this->horaInicio = horaInicio;
    this->horaDeSalida = 0;
    this->duracion = duracion;
    this->satisfaccion = 0.0f;
}

void Pasajero::restarDuracion()
{
    duracion--;
}

void Pasajero::mostrar()
{
    cout << "\tPasajero " << id << " (TR = " << duracion << ")";
}

void Pasajero::setHoraSalida(int tiempo)
{
    horaDeSalida = tiempo;
}

int Pasajero::getTiempoEstancia()
{
    return (horaDeSalida - horaInicio);
}

void Pasajero::setSatisfaccion(float tiempoMedioAtencionPasajeros)
{
    satisfaccion = (float) (tiempoMedioAtencionPasajeros - getTiempoEstancia());
}

float Pasajero::getSatisfaccion()
{
    return satisfaccion;
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

int Pasajero::getIdentificador()
{
    return id;
}

Pasajero::~Pasajero()
{
}
