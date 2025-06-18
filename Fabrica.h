#ifndef FABRICA
#define FABRICA
#include "Interfaces/IControladorAltaCine.h"
#include "Interfaces/IControladorVerReservaPelicula.h"
#include "Interfaces/IControladorSesion.h"
#include "Interfaces/IControladorCrearReserva.h"
#include "Interfaces/IControladorAltaFuncion.h"
#include "Interfaces/IControladorPelicula.h"

#include <iostream>
class Fabrica
{
private:
    static Fabrica *instancia;
    Fabrica();

public:
    static Fabrica *getInstancia();
    // IControladorCrearReserva* getIControladorCrearReserva();
    // IControladorVerReservaPelicula* getIControladorVerReservaPelicula();
    IControladorSesion *getIControladorSesion();
    IControladorPelicula *getIControladorPelicula();
    IControladorAltaCine* getIControladorAltaCine();
    IControladorAltaFuncion* getIControladorAltaFuncion();
    ~Fabrica();
};
#endif