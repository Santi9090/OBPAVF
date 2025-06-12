#ifndef ICONTROLADORALTAFUNCION_H
#define ICONTROLADORALTAFUNCION_H

#include <string>
#include "../DataTypes/DtFecha.h"
#include "../DataTypes/DtHorario.h"
using namespace std;

class IControladorAltaFuncion {
public:
    virtual void AltaFuncion(int idCine, int idSala, int idFuncion, DtFecha fecha, DtHorario horario) = 0;
};

#endif
