#ifndef ICONTROLADORALTACINE_H
#define ICONTROLADORALTACINE_H

#include <string>
#include "../DataTypes/DtDireccion.h"
#include "../DataTypes/DtSala.h"
using namespace std;

class IControladorAltaCine {
public:
    virtual void AltaCine(DtDireccion direccion, map<int, DtSala> dtSalas) = 0;
};

#endif
