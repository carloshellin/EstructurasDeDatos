#include "Lista.hpp"

Lista::Lista()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}

void Lista::insertar(Box *v)
{
    pnodoLista nuevo = new NodoLista(v);
    if (ultimo)
    {
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
    }
    ultimo = nuevo;
    if (!primero)
    {
        primero = nuevo;
    }
    
    longitud++;
}

void Lista::insertarOrdenado(Box *v)
{
    pnodoLista nuevo = new NodoLista(v);
    
    if (!primero)
    {
        // Lista vacía
        primero = nuevo;
        ultimo = nuevo;
    }
    else if (primero->valor->getId() != 'A')
    {
        // El primero no tiene como identificador la letra 'A'
        nuevo->siguiente = primero;
        nuevo->anterior = primero->anterior;
        primero->anterior = nuevo;
        primero = nuevo;
    }
    else
    {
        // Lista con primero y último
        
        pnodoLista aux = primero;
        pnodoLista p = aux;
        while (aux && v->getId() == aux->valor->getId())
        {
            // Si existe un mismo identificador, incrementar el del nuevo
            nuevo->valor->incrementarId();
            p = aux;
            aux = aux->siguiente;
        }
        
        if (!aux) ultimo = nuevo; // aux llega al final de la lista, el último es el nuevo
        
        nuevo->siguiente = p->siguiente;
        nuevo->anterior = p;
        if (p->siguiente) p->siguiente->anterior = nuevo; // Si p tiene siguiente, estamos insertando en el medio
        p->siguiente = nuevo;
    }
    
    longitud++;
}

pnodoLista Lista::eliminar(pnodoLista nodo)
{
    if (!nodo)
    {
        return NULL;
    }
    
    if (nodo == primero)
    {
        nodo->siguiente->anterior = NULL;
        primero = nodo->siguiente;
    }
    else if (nodo == ultimo)
    {
        nodo->anterior->siguiente = NULL;
        ultimo = nodo->anterior;
    }
    else
    {
        nodo->anterior->siguiente = nodo->siguiente;
        nodo->siguiente->anterior = nodo->anterior;
    }
    
    pnodoLista v = nodo->anterior ? nodo->anterior : nodo->siguiente;
    delete nodo;
    if (!primero)
    {
        ultimo = NULL;
    }
    
    longitud--;
    
    return v;
}

Box * Lista::colaMasCorta()
{
    pnodoLista aux = primero;
    
    Box *box = aux->valor;
    int longitud = box->getCola()->getLongitud();
    while (aux)
    {
        int colaLongitud = aux->valor->getCola()->getLongitud();
        if (longitud >= colaLongitud)
        {
            box = aux->valor;
            longitud = colaLongitud;
        }
        
        aux = aux->siguiente;
    }
    
    return box;
}

bool Lista::estanOcupados()
{
    pnodoLista aux = primero;
    
    while (aux)
    {
        if (aux->valor->getCola()->getLongitud() <= 2)
        {
            return false;
        }
        
        aux = aux->siguiente;
    }
    
    return true;
}

bool Lista::estanLibres()
{
    // La lista siempre debe tener al menos un box operativo.
    if (longitud == 1)
    {
        return primero->valor->getPasajero() ? false : true;
    }
    
    pnodoLista aux = primero;
    int libres = 0;
    
    while (aux)
    {
        if (!aux->valor->getPasajero())
        {
            libres++;
        }
        
        aux = aux->siguiente;
    }
    
    return libres >= 2;
}

void Lista::eliminarVacios()
{
    pnodoLista aux = primero;
    
    while (aux && longitud > 1)
    {
        if (!aux->valor->getPasajero())
        {
            aux = eliminar(aux);
        }
        else
        {
            aux = aux->siguiente;
        }       
    }
}

bool Lista::eliminarPasajeros(Cola *colaAtendidos, int tiempo)
{
    bool resultado = false;
    pnodoLista aux = primero;
    
    while (aux)
    {
        Box *box = aux->valor;
        Pasajero *pasajero = box->getPasajero();
        if (pasajero && pasajero->getDuracion() == 0)
        {
            pasajero->setHoraSalida(tiempo);
            colaAtendidos->insertarPorIdentificador(pasajero);
            
            pasajero = box->getCola()->eliminar();
            resultado = true;
            if (pasajero)
            {
                box->setPasajero(pasajero);
            }
            else
            {
                box->setPasajero(NULL);
            }
        }
        
        aux = aux->siguiente;
    }
    
    return resultado;
}

int Lista::restarDuracionPasajeros()
{
    pnodoLista aux = primero;
    int tiempoBoxes = 0;
    
    while (aux)
    {
        Pasajero *pasajero = aux->valor->getPasajero();
        if (pasajero)
        {
            pasajero->restarDuracion();
            tiempoBoxes++;
        }
        
        aux = aux->siguiente;
    }
    
    return tiempoBoxes;
}

int Lista::totalLongitudColas()
{
    pnodoLista aux = primero;
    int totalLongitud = 0;
    
    while (aux)
    {
        totalLongitud += aux->valor->getCola()->getLongitud();
        
        aux = aux->siguiente;
    }
    
    return totalLongitud;
}

void Lista::mostrar()
{       
    pnodoLista aux = primero;
    
    while (aux)
    {
        aux->valor->mostrar();

        aux = aux->siguiente;
    }
}

void Lista::mostrarPasajeros()
{
    pnodoLista aux = primero;
    
    while (aux)
    {
        Pasajero *pasajero = aux->valor->getPasajero();
        if (pasajero)
        {
            pasajero->mostrar();
        }
        else
        {
            cout << "\t\t\t";
        }

        aux = aux->siguiente;
    }
}

void Lista::mostrarColas()
{
    pnodoLista aux = primero;
    
    while (aux)
    {
        Box *box = aux->valor;
        box->getCola()->mostrar(box->getId());

        aux = aux->siguiente;
    }
}

int Lista::getLongitud()
{
    // Consultar en cualquier momento el número de boxes de atención operativos.
    return longitud;
}

Lista::~Lista()
{
    while (primero)
    {
        eliminar(primero);
    }
}

