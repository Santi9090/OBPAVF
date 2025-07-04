#include "DtCine.h"
#include "DtDireccion.h"
#include "DtPelicula.h"
#include <iostream>
using namespace std;

DtCine::DtCine()
{
}

DtCine::DtCine(int idCine, DtDireccion direccion, list<DtSala> salas, list<DtPelicula> peliculas)
{
    this->idCine = idCine;
    this->direccion = direccion;
    this->salas = salas;
    this->peliculas = peliculas;
}

int DtCine::getIdCine()
{
    return idCine;
}

DtDireccion DtCine::getDireccion()
{
    return direccion;
}
list<DtSala> DtCine::getSalas()
{
    list<DtSala> listaSalas;
    for (list<DtSala>::iterator it = this->salas.begin(); it != salas.end(); ++it)
    {
        listaSalas.push_back(*it);
    }
    return listaSalas;
}

list<DtPelicula> DtCine::getPeliculas()
{
    list<DtPelicula> listaPeliculas;
    for (list<DtPelicula>::iterator it = this->peliculas.begin(); it != peliculas.end(); ++it)
    {
        listaPeliculas.push_back(*it);
    }
    return listaPeliculas;
}

DtCine::~DtCine() {}
