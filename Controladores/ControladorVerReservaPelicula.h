#ifndef CONTROLADORVERRESERVAPELICULA_H
#define CONTROLADORVERRESERVAPELICULA_H

#include <string>
#include "../Interfaces/IControladorVerReservaPelicula.h"
#include "../Clases/Sala.h"
#include "../Clases/Funcion.h"
using namespace std;

class ControladorVerReservaPelicula: public IControladorVerReservaPelicula {
public:
    ControladorVerReservaPelicula();
    void VerReservaDePelicula(string titulo);
};

#endif
