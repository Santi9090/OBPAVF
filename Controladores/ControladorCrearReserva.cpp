#ifndef CONTROLADORCREARRESERVA_CPP
#define CONTROLADORCREARRESERVA_CPP

#include "ControladorCrearReserva.h"
#include "ManejadorCine.h"
#include "ManejadorPelicula.h"
#include "Sala.h"
#include "Funcion.h"
using namespace std;

map<string, DtPelicula> ControladorCrearReserva::listarPeliculas() {
    ManejadorPelicula* manejadorPelicula = ManejadorPelicula::getInstancia();
    return manejadorPelicula->listarPeliculas();
}

map<string, DtCine> ControladorCrearReserva::listarCines() {
    ManejadorCine* manejadorCine = ManejadorCine::getInstancia();
    return manejadorCine->listarCines();
}

map<string, DtFuncion> ControladorCrearReserva::listarFunciones() {
    ManejadorFuncion* manejadorFuncion = ManejadorFuncion::getInstancia();
    return manejadorFuncion->listarFunciones();
}

void ControladorCrearReserva::CrearReserva(string nickname, DtFuncion dtF, string tit, DtCine dtC) {
    ManejadorReserva* manejadorReserva = ManejadorReserva::getInstancia();
    manejadorReserva->CrearReserva(nickname, dtF, tit, dtC);
}

#endif
