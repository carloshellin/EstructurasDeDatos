#ifndef ARBOL_HPP
#define ARBOL_HPP

#include <windows.h>
#include "NodoArbol.hpp"

class Arbol
{
public:
    Arbol();
    ~Arbol();
    
    bool vacio(pnodoArbol raiz);
    void insertar(Pasajero *pasajero, pnodoArbol nodo);
    void insertar(Pasajero *pasajero);
    float sumaSatisfaccion(pnodoArbol nodo);
    int sumaNodos(pnodoArbol nodo);
    float media();
    void satisfaccionMedia();
    Pasajero * maximo(pnodoArbol nodo);
    Pasajero * minimo(pnodoArbol nodo);
    void pasajerosMayorMenor();
    void pasajerosMayorMedia();
    void negativa();
    void ordenadosPuntuacion();
    void inOrden(pnodoArbol nodo, float media);
    void preOrden(pnodoArbol nodo);
    void enOrdenMayor(pnodoArbol nodo);
    int _print_t(pnodoArbol arbol, int is_left, int offset, int depth, char s[20][255]);
    void mostrar();
private:
    pnodoArbol raiz;
};

#endif // ARBOL_HPP
