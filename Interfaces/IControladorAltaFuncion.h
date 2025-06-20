#ifndef ICONTROLADORALTAFUNCION_H
#define ICONTROLADORALTAFUNCION_H
#include <string>
#include "../DataTypes/DtFecha.h"
#include "../DataTypes/DtHorario.h"
#include "../DataTypes/DtFuncion.h"
#include <list>
using namespace std;

class IControladorAltaFuncion {
public:
    virtual void AltaFuncion(int idCine, int idSala, DtFecha fecha, DtHorario horario, string titulo) = 0;
    virtual list<DtFuncion> listarFunciones() = 0;
};

#endif
