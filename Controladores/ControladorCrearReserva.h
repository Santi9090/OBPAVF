#ifndef CONTROLADORCREARRESERVA_H
#define CONTROLADORCREARRESERVA_H

#include <string>
#include "../Interfaces/IControladorCrearReserva.h"
#include "../Clases/Pelicula.h"
#include "../Clases/Cine.h"
#include "../Clases/Funcion.h"
#include "../DataTypes/DtReserva.h"
#include <map>
using namespace std;

class ControladorCrearReserva : public IControladorCrearReserva
{
public:

    void CrearReserva(int idfuncion,string pelicula ,DtReserva Reserva);
};

#endif
