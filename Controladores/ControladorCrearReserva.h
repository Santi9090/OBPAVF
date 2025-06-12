#ifndef CONTROLADORCREARRESERVA_H
#define CONTROLADORCREARRESERVA_H

#include <string>
#include "../Interfaces/IControladorCrearReserva.h"
#include "../Clases/Pelicula.h"
#include "../Clases/Cine.h"
#include "../Clases/Funcion.h"
#include <map>
using namespace std;

class ControladorCrearReserva : public IControladorCrearReserva
{
public:
    list<Pelicula*> listarPeliculas();
    list<Cine*> listarCines();
    list<Funcion*> listarFunciones();
    void CrearReserva(string nickname, Funcion* dtF, string tit, Cine* dtC);
};

#endif
