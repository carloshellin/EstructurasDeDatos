#include "Pila.hpp"

Pila::Pila()
{
    ultimo = NULL;
    longitud = 0;
}

void Pila::insertar(Pasajero *v)
{
    pnodoPila nuevo = new NodoPila(v, ultimo);
    ultimo = nuevo;
    longitud++;
}

Pasajero * Pila::extraer()
{
    if (!ultimo)
    {
        return NULL;
    }
    
    pnodoPila nodo = ultimo;
    ultimo = nodo->siguiente;
    Pasajero *v = nodo->valor;
    
    delete nodo;
    
    longitud--;
    
    return v;
}

void Pila::mostrar()
{
    pnodoPila aux = ultimo;
    cout << "Mi pila: ";
    while (aux)
    {
        cout << "-> " << aux->valor;
        aux = aux->siguiente;
    }
    cout << endl;
}

int Pila::getLongitud()
{
    return longitud;
}

Pila::~Pila()
{
    while (ultimo)
    {
        pnodoPila aux = ultimo;
        ultimo = ultimo->siguiente;
        delete aux;
    }
}