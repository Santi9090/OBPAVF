#ifndef CONTROLADORPELICULA_H
#define CONTROLADORPELICULA_H

#include <string>
#include "IControladorPelicula.h"
using namespace std;

class ControladorPelicula: public IControladorPelicula {
public:
    ControladorPelicula();
    void EliminarPelicula(string titulo);
};

#endif
