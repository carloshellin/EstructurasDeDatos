#include "Principal.hpp"

int main(int argc, char **argv)
{   
    // Pasajeros en pila
    // El último es el que más tarda en salir
    // El primero es el que sale antes
    Pila pila;
    
    pila.insertar(new Pasajero(5, 3, "Alemania", 21, 20));
    pila.insertar(new Pasajero(6, 2, "Italia", 18, 14));
    pila.insertar(new Pasajero(8, 7, "Australia", 14, 31));
    pila.insertar(new Pasajero(9, 4, "Noruega", 11, 23));
    pila.insertar(new Pasajero(7, 6, "Indonesia", 9, 16));
    pila.insertar(new Pasajero(4, 5, "Sudáfrica", 7, 23));
    pila.insertar(new Pasajero(2, 7, "Australia", 5, 39));
    pila.insertar(new Pasajero(3, 1, "Portugal", 0, 15));
    pila.insertar(new Pasajero(1, 6, "Indonesia", 0, 20));

    Principal programaPrincipal(&pila);
    float tiempoMedio = programaPrincipal.simulacion();
    
    cout << "El tiempo medio de atencion es de " << tiempoMedio << " minutos." << endl;
    system("pause");
    
	return 0;
}
