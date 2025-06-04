#ifndef ICONTROLADORALTACINE_H
#define ICONTROLADORALTACINE_H

#include <string>
#include "../DataTypes/DtDireccion.h"
using namespace std;

class IControladorAltaCine {
public:
    virtual void AltaCine(DtDireccion direccion, string nombre) = 0;
};

#endif
