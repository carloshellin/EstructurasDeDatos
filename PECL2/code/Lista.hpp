#ifndef LISTA_HPP
#define LISTA_HPP

#include "NodoLista.hpp"

class Lista
{
public:
    Lista();
    ~Lista();
    
    void insertar(Box *v);
    void insertarOrdenado(Box *v);
    pnodoLista eliminar(pnodoLista nodo);
    Box * colaMasCorta();
    bool estanOcupados();
    bool estanLibres();
    void eliminarVacios();
    bool eliminarPasajeros(Cola *colaAtendidos, int tiempo);
    int restarDuracionPasajeros();
    int totalLongitudColas();
    void mostrar();
    void mostrarPasajeros();
    void mostrarColas();
    
    int getLongitud();
    
private:
    pnodoLista primero, ultimo;
    int longitud;
};

#endif // LISTA_HPP
