#include "Fabrica.h"
#include "Controladores/ControladorAltaCine.h"
#include "Controladores/ControladorVerReservaPelicula.h"
#include "Controladores/ControladorSesion.h"
#include "Controladores/ControladorCrearReserva.h"
#include "Controladores/ControladorPelicula.h"
#include "Controladores/ControladorAltaFuncion.h"
#include "Controladores/ControladorSesion.h"
#include "Controladores/ControladorPelicula.h"
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
IControladorPelicula* Fabrica::getIControladorPelicula() {
    return new ControladorPelicula();
}

