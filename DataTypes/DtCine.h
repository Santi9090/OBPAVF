#ifndef DTCINE_H
#define DTCINE_H

#include <iostream>
#include "DtDireccion.h"
#include "DtSala.h"
#include "DtPelicula.h"
#include <map>
#include <list>
using namespace std;

class DtCine
{
private:
    int idCine;
    DtDireccion direccion;
    list<DtSala> salas;
    list<DtPelicula> peliculas;

public:
    DtCine();
    DtCine(int idCine, DtDireccion direccion, list<DtSala> salas, list<DtPelicula> peliculas);
    int getIdCine();
    DtDireccion getDireccion();
    list<DtSala> getSalas();
    list<DtPelicula> getPeliculas();

    ~DtCine();
};

#endif