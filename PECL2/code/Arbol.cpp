#include "Arbol.hpp"

Arbol::Arbol()
{
    Pasajero *pasajero = new Pasajero(-1, -1, "", -1, -1);

    raiz = new NodoArbol(pasajero);
}

bool Arbol::vacio(pnodoArbol nodo)
{
    return nodo == NULL;
}

void Arbol::insertar(Pasajero *pasajero, pnodoArbol nodo)
{
    if (pasajero->getSatisfaccion() <= nodo->pasajero->getSatisfaccion())
    {
        if (vacio(nodo->izquierdo))
        {
            nodo->izquierdo = new NodoArbol(pasajero);
        }
        else
        {
            insertar(pasajero, nodo->izquierdo);
        }
    }
    else
    {
        if (vacio(nodo->derecho))
        {
            nodo->derecho = new NodoArbol(pasajero);
        }
        else
        {
            insertar(pasajero, nodo->derecho);
        }
    }
}

void Arbol::insertar(Pasajero *pasajero)
{   
    insertar(pasajero, raiz);
}

float Arbol::sumaSatisfaccion(pnodoArbol nodo)
{
    if (vacio(nodo)) return 0;
    return nodo->pasajero->getSatisfaccion() + sumaSatisfaccion(nodo->izquierdo) + sumaSatisfaccion(nodo->derecho);
}

int Arbol::sumaNodos(pnodoArbol nodo)
{
    if (vacio(nodo)) return 0;
    return 1 + sumaNodos(nodo->izquierdo) + sumaNodos(nodo->derecho);
}

float Arbol::media()
{
    float satisfaccion = sumaSatisfaccion(raiz);
    int pasajeros = sumaNodos(raiz->izquierdo) + sumaNodos(raiz->derecho);
    
    return (float) satisfaccion / (float) pasajeros;
}

// Satisfacción media de los pasajeros.
void Arbol::satisfaccionMedia()
{
    cout << fixed << "Satisfaccion media de los pasajeros: " << media() << endl << endl;
}

Pasajero * Arbol::maximo(pnodoArbol nodo)
{
    if (vacio(nodo->derecho))
    {
        return nodo->pasajero;
    }
    else
    {
        return maximo(nodo->derecho);
    }
}

Pasajero * Arbol::minimo(pnodoArbol nodo)
{
    if (vacio(nodo->izquierdo))
    {
        return nodo->pasajero;
    }
    else
    {
        return minimo(nodo->izquierdo);
    }
}

// Datos de los pasajeros que tienen mayor y menor nivel de satisfacción.
void Arbol::pasajerosMayorMenor()
{
    Pasajero *mayor = maximo(raiz);
    Pasajero *menor = minimo(raiz);
    
    cout << "Datos de los pasajeros que tienen mayor y menor nivel de satisfaccion:" << endl;
    cout << "Mayor: (id: " << mayor->getId() << ", satisfaccion: " << mayor->getSatisfaccion() << ")" << endl;
    cout << "Menor: (id: " << menor->getId() << ", satisfaccion: " << menor->getSatisfaccion() << ")" << endl << endl;
}

// izquierda, raíz, derecha
void Arbol::inOrden(pnodoArbol nodo, float media)
{
    if (nodo->izquierdo) inOrden(nodo->izquierdo, media);
    if (nodo->pasajero->getSatisfaccion() > media && nodo != raiz)
    {
        cout << "(id: " << nodo->pasajero->getId() << ", satisfaccion: " << nodo->pasajero->getSatisfaccion() << ")" << endl;
    }
    if (nodo->derecho) inOrden(nodo->derecho, media);
}

// Datos de los pasajeros que tienen un nivel de satisfacción mayor que la media, ordenados de menor a mayor puntuación.
void Arbol::pasajerosMayorMedia()
{
    cout << "Datos de los pasajeros que tienen un nivel de satisfaccion mayor que la media, ordenados de menor a mayor puntuacion:" << endl;
    inOrden(raiz,  media());
    cout << endl;
}

// raíz, izquierda, derecha
void Arbol::preOrden(pnodoArbol nodo)
{
    cout << "(id: " << nodo->pasajero->getId() << ", satisfaccion: " << nodo->pasajero->getSatisfaccion() << ")" << endl;
    if (nodo->izquierdo) preOrden(nodo->izquierdo);
    if (nodo->derecho) preOrden(nodo->derecho);
}

// Datos de los pasajeros cuya puntuación es negativa recorriendo el ABB en preorden.
void Arbol::negativa()
{
    cout << "Datos de los pasajeros cuya puntuacion es negativa recorriendo el ABB en preorden:" << endl;
    preOrden(raiz->izquierdo);
    cout << endl;
}

// izquierda, derecha, raíz
void Arbol::enOrdenMayor(pnodoArbol nodo)
{
    if (nodo->derecho) enOrdenMayor(nodo->derecho);
    if (nodo != raiz)
    {
        cout << "(id: " << nodo->pasajero->getId() << ", satisfaccion: " << nodo->pasajero->getSatisfaccion() << ")" << endl;
    }
    if (nodo->izquierdo) enOrdenMayor(nodo->izquierdo);
}

// Datos de todos los pasajeros ordenados por su puntuación.
void Arbol::ordenadosPuntuacion()
{
    cout << "Datos de todos los pasajeros ordenados por su puntuacion:" << endl;
    enOrdenMayor(raiz);
    cout << endl;
}

int Arbol::_print_t(pnodoArbol arbol, int is_left, int offset, int depth, char s[20][255])
{
    char b[20];
    int width = 8;

    if (!arbol) return 0;
    
    sprintf(b, "%f", arbol->pasajero->getSatisfaccion());

    int left  = _print_t(arbol->izquierdo,  1, offset,                depth + 1, s);
    int right = _print_t(arbol->derecho, 0, offset + left + width, depth + 1, s);

    for (int i = 0; i < width; i++)
        s[2 * depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset + left + width + right + width/2] = '+';

    } else if (depth && !is_left) {

        for (int i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset - width/2 - 1] = '+';
    }

    return left + width + right;
}

void Arbol::mostrar()
{
    // TODO: Funciona bien para arboles pequeños pero no grandes
    char s[20][255];
    for (int i = 0; i < 20; i++)
        sprintf(s[i], "%80s", " ");

    _print_t(raiz, 0, 0, 0, s);

    for (int i = 0; i < 20; i++)
        printf("%s\n", s[i]);
}

Arbol::~Arbol()
{
}

