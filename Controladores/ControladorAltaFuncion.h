#ifndef CONTROLADORALTAFUNCION_H
#define CONTROLADORALTAFUNCION_H

#include <string>
#include "Funcion.h"
#include "Pelicula.h"
#include "Cine.h"
#include "DtFecha.h"
#include "DtHorario.h"
#include <iostream>
#include "IControladorAltaFuncion.h"
#include "ManejadorFuncion.h"
using namespace std;
class ControladorAltaFuncion: public IControladorAltaFuncion {
public:
    ControladorAltaFuncion();
    void AltaFuncion(int idCine, int idSala, int idFuncion, DtFecha fecha, DtHorario horario);
    void obtenerFunciones();
};
#endif
