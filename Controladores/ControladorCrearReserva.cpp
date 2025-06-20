#ifndef CONTROLADORCREARRESERVA_CPP
#define CONTROLADORCREARRESERVA_CPP

#include "ControladorCrearReserva.h"
#include "../Manejadores/ManejadorCine.h"
#include "../Manejadores/ManejadorPelicula.h"
#include "../Manejadores/ManejadorFuncion.h"
#include "../Clases/Reserva.h"

#include "../Clases/Sala.h"
#include "../Clases/Funcion.h"
using namespace std;

list<Cine *> ControladorCrearReserva::listarCines()
{
    ManejadorCine *manejadorCine = ManejadorCine::getInstancia();
    return manejadorCine->getCines();
}


void ControladorCrearReserva::CrearReserva(Funcion* funcion, DtReserva reserva)
{
    
    
}
#endif
