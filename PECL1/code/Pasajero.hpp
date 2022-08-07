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

    int getId();    
    int getPrioridad();
    int getHoraInicio();
    int getDuracion();
    
private:
    int id;
    char idBox;
    const char *paisDestino;
    int prioridad;
    int horaInicio;
    int duracion;
};

#endif // PASAJERO_HPP
