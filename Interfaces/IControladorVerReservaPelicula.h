#ifndef ICONTROLADORVERRESERVAPELICULA_H
#define ICONTROLADORVERRESERVAPELICULA_H

#include <string>
using namespace std;

class IControladorVerReservaPelicula {
public:
    virtual void VerReservaDePelicula(string titulo) = 0;
};

#endif
