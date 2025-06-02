#ifndef CONTROLADORALTAFUNCION_H
#define CONTROLADORALTAFUNCION_H

#include <string>
#include "Funcion.h"
#include "Pelicula.h"
#include "Cine.h"
#include "DtFecha.h"
#include "DtHorario.h"
#include <iostream>
using namespace std;
class ControladorAltaFuncion {
public:
    ControladorAltaFuncion();
    void AltaFuncion(int idCine, int idSala, int idFuncion, DtFecha fecha, DtHorario horario);
    void obtenerFunciones();
};
#endif
