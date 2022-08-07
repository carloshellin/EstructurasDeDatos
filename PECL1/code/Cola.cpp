#include "Cola.hpp"

Cola::Cola()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}

void Cola::insertar(Pasajero *v)
{
    pnodoCola nuevo = new NodoCola(v);
    if (ultimo)
    {
        ultimo->siguiente = nuevo;
    }
    ultimo = nuevo;
    if (!primero)
    {
        primero = nuevo;
    }
    
    longitud++;
}

void Cola::insertarConPrioridad(Pasajero *v)
{
    pnodoCola nuevo = new NodoCola(v);
    
    if (!primero)
    {
        // Cola vacía
        primero = nuevo;
        ultimo = nuevo;
    }
    else
    {
        // Cola con primero y último
        
        int prioridad = v->getPrioridad();
        
        if (prioridad > primero->valor->getPrioridad())
        {
            // Prioridad mayor que el primero, a la parte izquierda
            nuevo->siguiente = primero;
            primero = nuevo;
        }
        else if (prioridad <= ultimo->valor->getPrioridad())
        {
            // Menor o igual que último, a la parte derecha
            ultimo->siguiente = nuevo;
            ultimo = nuevo;
        }
        else
        {
            // Menor que primero y mayor que último, ocupa el medio
            pnodoCola aux = primero;
            while (prioridad <= aux->siguiente->valor->getPrioridad())
            {
                aux = aux->siguiente;
            }
            
            nuevo->siguiente = aux->siguiente;
            aux->siguiente = nuevo;
        }
    }
    
    longitud++;
}

Pasajero * Cola::eliminar()
{
    pnodoCola nodo = primero;
    if (!nodo)
    {
        return NULL;
    }
    primero = nodo->siguiente;
    Pasajero *v = nodo->valor;
    delete nodo;
    if (!primero)
    {
        ultimo = NULL;
    }
    
    longitud--;
    
    return v;
}

void Cola::mostrar(char id)
{
    pnodoCola aux = primero;

    cout << "\t\t\t\tCOLA " << id << ":";    
    if (!aux)
    {
        cout << " Vacia";
    }
    
    cout << endl;
    
    while (aux)
    {
        cout << "\t\t\tPasajero " << aux->valor->getId() << " (PR = " << aux->valor->getPrioridad() << ")" << endl;
        aux = aux->siguiente;
    }
    
    cout << endl;
}

pnodoCola Cola::getPrimero()
{
    return primero;
}

int Cola::getLongitud()
{
    return longitud;
}

Cola::~Cola()
{
    while (primero)
    {
        eliminar();
    }
}

