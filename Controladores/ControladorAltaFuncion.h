#ifndef CONTROLADORALTAFUNCION_H
#define CONTROLADORALTAFUNCION_H

#include <string>
#include "../Clases/Funcion.h"
#include "../Clases/Pelicula.h"
#include "../Clases/Cine.h"
#include "../DataTypes/DtFecha.h"
#include "../DataTypes/DtHorario.h"
#include "../Interfaces/IControladorAltaFuncion.h"

using namespace std;
class ControladorAltaFuncion: public IControladorAltaFuncion {
public:
    ControladorAltaFuncion();
    void AltaFuncion(int idCine, int idSala, DtFecha fecha, DtHorario horario,string titulo);
    list<DtFuncion> listarFunciones();
};
#endif
