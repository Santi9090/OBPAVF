#ifndef CONTROLADORCREARRESERVA_CPP
#define CONTROLADORCREARRESERVA_CPP

#include "ControladorCrearReserva.h"
#include "../Manejadores/ManejadorCine.h"
#include "../Manejadores/ManejadorPelicula.h"
#include "../Manejadores/ManejadorFuncion.h"

#include "../Clases/Sala.h"
#include "../Clases/Funcion.h"
using namespace std;

list<Pelicula*> ControladorCrearReserva::listarPeliculas() {
    ManejadorPelicula* manejadorPelicula = ManejadorPelicula::getInstancia();
    return manejadorPelicula->listarPeliculas();
}

list<Cine*> ControladorCrearReserva::listarCines() {
    ManejadorCine* manejadorCine = ManejadorCine::getInstancia();
    return manejadorCine->getCines();
}

list<Funcion*> ControladorCrearReserva::listarFunciones() {
    ManejadorFuncion* manejadorFuncion = ManejadorFuncion::getInstancia();
    return manejadorFuncion->getFunciones();
}

void ControladorCrearReserva::CrearReserva(string nickname, Funcion* dtF, string tit, Cine* dtC) {
    ManejadorReserva* manejadorReserva = ManejadorReserva::getInstancia();
    manejadorReserva->CrearReserva(nickname, dtF, tit, dtC);
}

#endif
