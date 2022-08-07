#ifndef AEROPUERTO_HPP
#define AEROPUERTO_HPP

#include "Lista.hpp"

#include <iomanip>

class Aeropuerto
{
public:
    Aeropuerto();
    ~Aeropuerto();
    
    void entraBox(Pasajero *pasajero);
    bool saleBox();
    void actualizarTiempos();
    bool estaVacio();
    void mostrar(const char *evento);
    
    int getTiempo();
    int getTiempoBoxes();
    int getTiempoCola();
    
private:
    Lista *boxes;
    int tiempo;
    int tiempoBoxes;
    int tiempoCola;
};

#endif // AEROPUERTO_HPP
