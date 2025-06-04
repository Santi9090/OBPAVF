#ifndef CONTROLADORVERRESERVAPELICULA_H
#define CONTROLADORVERRESERVAPELICULA_H

#include <string>
#include "IControladorVerReservaPelicula.h"
using namespace std;

class ControladorVerReservaPelicula: public IControladorVerReservaPelicula {
public:
    ControladorVerReservaPelicula();
    void VerReservaDePelicula(string titulo);
};

#endif
