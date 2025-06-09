#include "Fabrica.h"
#include "ControladorCrearReserva.h"
#include "ControladorVerReservaPelicula.h"
#include "ControladorSesion.h"
#include "ControladorPelicula.h"
#include "ControladorAltaCine.h"
#include "ControladorAltaFuncion.h"

Fabrica* Fabrica::instancia = NULL;

Fabrica::Fabrica(){}

Fabrica* Fabrica::getInstancia(){
    if (instancia == NULL) 
        instancia = new Fabrica();
    return instancia;
}



Fabrica::~Fabrica(){}
/*
IControladorCrearReserva* Fabrica::getIControladorCrearReserva() {
    return new ControladorCrearReserva();
}

IControladorVerReservaPelicula* Fabrica::getIControladorVerReservaPelicula() {
    return new ControladorVerReservaPelicula();
}


IControladorPelicula* Fabrica::getIControladorPelicula() {
    return new ControladorPelicula();
}

IControladorAltaCine* Fabrica::getIControladorAltaCine() {
    return new ControladorAltaCine();
}

IControladorAltaFuncion* Fabrica::getIControladorAltaFuncion() {
    return new ControladorAltaFuncion();
}
*/

IControladorSesion* Fabrica::getIControladorSesion() {
    return new ControladorSesion();
}
