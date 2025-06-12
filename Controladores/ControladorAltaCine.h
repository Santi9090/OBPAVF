#ifndef CONTROLADORALTACINE_H
#define CONTROLADORALTACINE_H
#include "../Interfaces/IControladorAltaCine.h"
#include <string>
#include "../DataTypes/DtDireccion.h"
using namespace std;

class ControladorAltaCine: public IControladorAltaCine {
public:
    ControladorAltaCine();
    void AltaCine(DtDireccion direccion, string nombre);
};

#endif
