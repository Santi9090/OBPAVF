#ifndef CONTROLADORALTACINE_H
#define CONTROLADORALTACINE_H

#include <string>
#include "DtDireccion.h"
using namespace std;

class ControladorAltaCine {
public:
    ControladorAltaCine();
    void AltaCine(DtDireccion direccion, string nombre);
};

#endif
