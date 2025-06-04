#ifndef CONTROLADORCREARRESERVA_H
#define CONTROLADORCREARRESERVA_H

#include <string>
#include "../Interfaces/IControladorCrearReserva.h"
#include "../DataTypes/DtPelicula.h"
#include "../DataTypes/DtCine.h"
#include "../DataTypes/DtFuncion.h"
#include <map>
using namespace std;

class ControladorCrearReserva : public IControladorCrearReserva
{
public:
    map<string, DtPelicula> listarPeliculas();
    map<string, DtCine> listarCines();
    map<string, DtFuncion> listarFunciones();
    void CrearReserva(string nickname, DtFuncion dtF, string tit, DtCine dtC);
};

#endif
