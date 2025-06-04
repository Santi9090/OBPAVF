#ifndef ICONTROLADORPELICULA_H
#define ICONTROLADORPELICULA_H

#include <string>
using namespace std;

class IControladorPelicula {
public:
    virtual void EliminarPelicula(string titulo) = 0;
};

#endif
