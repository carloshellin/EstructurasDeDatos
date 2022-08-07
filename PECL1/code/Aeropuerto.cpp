#include "Aeropuerto.hpp"

Aeropuerto::Aeropuerto()
{
    boxes = new Lista();
    boxes->insertarOrdenado(new Box());
    
    tiempo = 0;
    tiempoBoxes = 0;
    tiempoCola = 0;
}

void Aeropuerto::entraBox(Pasajero *pasajero)
{    
    Box *box = boxes->colaMasCorta();
    if (box->getPasajero())
    {
        box->insertarCola(pasajero);
    }
    else
    {
        box->setPasajero(pasajero);
    }
    
    if (boxes->estanOcupados())
    {
        // Añadir un box de atención a la lista en caso de tener todos los boxes con más de 2 pasajeros en cada cola.
        boxes->insertarOrdenado(new Box());
    }
}

bool Aeropuerto::saleBox()
{   
    bool resultado = boxes->eliminarPasajeros();
    
    if (boxes->estanLibres())
    {
        // Borrar los boxes vacíos cuando haya dos o más libres
        boxes->eliminarVacios();
    }
    
    return resultado;
}

void Aeropuerto::actualizarTiempos()
{
    tiempoBoxes += boxes->restarDuracionPasajeros();
    tiempoCola += boxes->totalLongitudColas();
    tiempo++;
}

bool Aeropuerto::estaVacio()
{
    return tiempo > 0 && boxes->estanLibres();
}

void Aeropuerto::mostrar(const char *evento)
{
        system("cls");
        
        cout << evento << "\t\t\t";
        boxes->mostrar();
        cout << endl;
        
        cout << "A las " << setfill('0') << setw(2) << tiempo / 60 << ":" << setfill('0') << setw(2) << tiempo % 60;
        
        boxes->mostrarPasajeros();
        cout << endl;
        
        boxes->mostrarColas();
}

int Aeropuerto::getTiempo()
{
    return tiempo;
}

int Aeropuerto::getTiempoBoxes()
{
    return tiempoBoxes;
}

int Aeropuerto::getTiempoCola()
{
    return tiempoCola;
}

Aeropuerto::~Aeropuerto()
{
}

