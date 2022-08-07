#include "NodoCola.hpp"

NodoCola::NodoCola(Pasajero *v, NodoCola *sig)
{
    valor = v;
    siguiente = sig;
}

NodoCola::~NodoCola()
{
}

