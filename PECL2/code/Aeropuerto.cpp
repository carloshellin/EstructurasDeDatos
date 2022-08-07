#include "Aeropuerto.hpp"

Aeropuerto::Aeropuerto()
{
    #ifdef PARTE2
        boxes = new Lista();
        boxes->insertarOrdenado(new Box());
    #else
        for (int i = 0; i < TOTAL_BOXES; i++)
        {
            boxes[i] = new Box('A' + i);
        }
        cola = new Cola();
    #endif
    
    tiempo = 0;
    colaAtendidos = new Cola();
}

void Aeropuerto::entraBox(Pasajero *pasajero)
{   
    #ifdef PARTE2
        Box *box = boxes->colaMasCorta();
        if (box->getPasajero())
        {
            box->insertarCola(pasajero);
        }
        else
        {
            box->setPasajero(pasajero);
        }
    #else
        for (int i = 0; i < TOTAL_BOXES; i++)
        {
            if (!boxes[i]->getPasajero())
            {
                boxes[i]->setPasajero(pasajero);
                return;
            }
        }
        
        cola->insertarConPrioridad(pasajero);
    #endif
    
    #ifdef PARTE2
        if (boxes->estanOcupados())
        {
            // Añadir un box de atención a la lista en caso de tener todos los boxes con más de 2 pasajeros en cada cola.
            boxes->insertarOrdenado(new Box());
        }
    #endif
}

bool Aeropuerto::saleBox()
{   
    bool resultado = false;
    
    #ifdef PARTE2
        resultado = boxes->eliminarPasajeros(colaAtendidos, tiempo);
        if (boxes->estanLibres())
        {
            // Borrar los boxes vacíos cuando haya dos o más libres
            boxes->eliminarVacios();
        }
    #else
        for (int i = 0; i < TOTAL_BOXES; i++)
        {
            resultado = boxes[i]->eliminarPasajero(cola, colaAtendidos, tiempo);
        }
    #endif
    
    return resultado;
}

void Aeropuerto::actualizarTiempos()
{
    #ifdef PARTE2
        boxes->restarDuracionPasajeros();
    #else
        for (int i = 0; i < TOTAL_BOXES; i++)
        {
            if (boxes[i]->getPasajero())
            {
                boxes[i]->getPasajero()->restarDuracion();
            }
        }
    #endif
    
    tiempo++;
}

bool Aeropuerto::estaVacio()
{
    bool boxLibre = false;
    
    #ifdef PARTE2
        boxLibre = boxes->estanLibres();
    #else
        for (int i = 0; i < TOTAL_BOXES; i++)
        {
            if (boxes[i]->getPasajero())
            {
                return false;
            }
            else
            {
                boxLibre = true;
            }
        }
    #endif
    
    return tiempo > 0 && boxLibre;
}

void Aeropuerto::mostrar(const char *evento)
{
        system("cls");
        
        cout << evento << "\t\t\t";
        #ifdef PARTE2
            boxes->mostrar();
        #else
            for (int i = 0; i < TOTAL_BOXES; i++)
            {
                boxes[i]->mostrar();
            }
        #endif
        cout << endl;
        
        cout << "A las " << setfill('0') << setw(2) << tiempo / 60 << ":" << setfill('0') << setw(2) << tiempo % 60;
        
        #ifdef PARTE2
            boxes->mostrarPasajeros();
            cout << endl;
        
            boxes->mostrarColas();
        #else
            for (int i = 0; i < TOTAL_BOXES; i++)
            {
                if (boxes[i]->getPasajero()) boxes[i]->getPasajero()->mostrar();
            }
            
            cout << endl;
            cola->mostrar(' ');
        #endif
}

int Aeropuerto::getTiempo()
{
    return tiempo;
}

Cola * Aeropuerto::getColaAtendidos()
{
    return colaAtendidos;
}

Aeropuerto::~Aeropuerto()
{
}

