#include "Principal.hpp"

Principal::Principal(Pila* pasajeros)
{
    this->pasajeros = pasajeros;
    this->pasajerosTotal = pasajeros->getLongitud();
    this->arbol = new Arbol();
}

float Principal::simulacion()
{
    while (true)
    {
        const char* evento = "";

        if (llegada())
        {
            evento = "Llegada";
        }

        if (salida())
        {
            evento = "Salida";
        }

        aeropuerto.mostrar(evento);

        if (aeropuerto.estaVacio() && pasajeros->getLongitud() == 0)
        {
            Cola *colaAtendidos = aeropuerto.getColaAtendidos();
            float tiempoMedio = colaAtendidos->getTiempoMedioPasajeros();
            colaAtendidos->estableceSatisfaccion();
            while (colaAtendidos->getLongitud())
            {

                arbol->insertar(colaAtendidos->eliminar());
            }

            arbol->mostrar();
            
            arbol->satisfaccionMedia();
            arbol->pasajerosMayorMenor();
            arbol->pasajerosMayorMedia();
            arbol->negativa();
            arbol->ordenadosPuntuacion();

            return tiempoMedio;
        }

        aeropuerto.actualizarTiempos();
        sleep(0.5);
    }
}

bool Principal::llegada()
{
    bool resultado = false;

    Pasajero* pasajero = pasajeros->extraer();
    while (pasajero && pasajero->getHoraInicio() == aeropuerto.getTiempo())
    {
        aeropuerto.entraBox(pasajero);
        resultado = true;

        pasajero = pasajeros->extraer();
    }

    if (pasajero)
    {
        pasajeros->insertar(pasajero);   
    }

    return resultado;
}

bool Principal::salida()
{
    return aeropuerto.saleBox();
}

Principal::~Principal()
{
}
