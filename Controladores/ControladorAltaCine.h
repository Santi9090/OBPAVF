#ifndef CONTROLADORALTACINE_H
#define CONTROLADORALTACINE_H
#include "IControladorAltaCine.h"
#include <string>
#include "DtDireccion.h"
using namespace std;

class ControladorAltaCine: public IControladorAltaCine {
public:
    ControladorAltaCine();
    void AltaCine(DtDireccion direccion, string nombre);
};

#endif
