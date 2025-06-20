#include "DtFuncion.h"

DtFuncion::DtFuncion(int idFuncion, DtFecha fecha, DtHorario horario,DtPelicula pelicula)
    : pelicula(pelicula) 
{
    this->idFuncion = idFuncion;
    this->fecha = fecha;
    this->horario = horario;
    this->pelicula = pelicula; 
}

int DtFuncion::getIdFuncion()
{
    return idFuncion;
}

DtFecha DtFuncion::getFecha()
{
    return fecha;
}

DtHorario DtFuncion::getHorario()
{
    return horario;
}
DtPelicula DtFuncion::getPelicula()
{
    return pelicula;
}
DtFuncion::~DtFuncion() {}
