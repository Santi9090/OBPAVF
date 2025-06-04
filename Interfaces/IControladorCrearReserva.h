#ifndef ICONTROLADORCREARRESERVA_H
#define ICONTROLADORCREARRESERVA_H

#include <string>
using namespace std;

class IControladorCrearReserva {
public:
    virtual void VerReservaDePelicula(string titulo, string nombreCliente, int cantidadEntradas) = 0;
};

#endif
