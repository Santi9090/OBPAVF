#ifndef ICONTROLADORCREARRESERVA_H
#define ICONTROLADORCREARRESERVA_H

#include <string>
#include "../DataTypes/DtReserva.h"
using namespace std;

class IControladorCrearReserva {
public:
    virtual void VerReservaDePelicula(string titulo, string nombreCliente, int cantidadEntradas) = 0;
    virtual void CrearReserva(int idfuncion,string pelicula ,DtReserva Reserva) = 0;
};

#endif
