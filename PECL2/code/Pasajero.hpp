#ifndef PASAJERO_HPP
#define PASAJERO_HPP

#include <iostream>
using namespace std;

class Pasajero
{
public:
    Pasajero(int id, int prioridad, const char *paisDestino, int horaInicio, int duracion);
    Pasajero();
    ~Pasajero();
    
    void restarDuracion();
    void mostrar();
    
    void setHoraSalida(int tiempo);
    void setSatisfaccion(float tiempoMedioAtencionPasajeros);
    float getSatisfaccion();
    int getId();    
    int getPrioridad();
    int getHoraInicio();
    int getDuracion();
    int getIdentificador();
    int getTiempoEstancia();
    
private:
    int id;
    char idBox;
    const char *paisDestino;
    int prioridad;
    int horaInicio;
    int horaDeSalida;
    int duracion;
    float satisfaccion;
};

#endif // PASAJERO_HPP
