#include "Fabrica.h"
#include "Controladores/ControladorAltaCine.h"
#include "Controladores/ControladorVerReservaPelicula.h"
#include "Controladores/ControladorSesion.h"
#include "Controladores/ControladorCrearReserva.h"
#include "Controladores/ControladorPelicula.h"
#include "Controladores/ControladorAltaFuncion.h"
#include "Controladores/ControladorSesion.h"
#include "Controladores/ControladorPelicula.h"
#include "Controladores/ControladorPuntajeComentario.h"
Fabrica* Fabrica::instancia = NULL;

Fabrica::Fabrica(){}

Fabrica* Fabrica::getInstancia(){
    if (instancia == NULL) 
        instancia = new Fabrica();
    return instancia;
}



Fabrica::~Fabrica(){}

IControladorCrearReserva* Fabrica::getIControladorCrearReserva() {
    return new ControladorCrearReserva();
}

IControladorVerReservaPelicula* Fabrica::getIControladorVerReservaPelicula() {
    return new ControladorVerReservaPelicula();
}

IControladorAltaFuncion* Fabrica::getIControladorAltaFuncion() {
    return new ControladorAltaFuncion();
}


IControladorSesion* Fabrica::getIControladorSesion() {
    return new ControladorSesion();
}
IControladorPelicula* Fabrica::getIControladorPelicula() {
    return new ControladorPelicula();
}

IControladorAltaCine* Fabrica::getIControladorAltaCine() {
    return new ControladorAltaCine();
}

IControladorPuntajeComentario* Fabrica::getIControladorPuntajeComentario(){
    return new ControladorPuntajeComentario();
}