#ifndef AEROPUERTO_HPP
#define AEROPUERTO_HPP

#include "Lista.hpp"

#include <iomanip>

//#define PARTE2
#define TOTAL_BOXES 3

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
    Cola *getColaAtendidos();
    
private:
#ifdef PARTE2
    Lista *boxes;
#else
    Box *boxes[TOTAL_BOXES];
    Cola *cola;
#endif
    Cola *colaAtendidos;
    int tiempo;
};

#endif // AEROPUERTO_HPP
