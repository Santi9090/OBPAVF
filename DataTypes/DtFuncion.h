#ifndef DTFUNCION_H
#define DTFUNCION_H

#include "DtFecha.h"
#include "DtHorario.h"
#include "DtPelicula.h"
#include <iostream>

class DtFuncion {
private:
    int idFuncion;
    DtFecha fecha;
    DtHorario horario;
    DtPelicula pelicula;
public:
    DtFuncion(int idFuncion, DtFecha fecha, DtHorario horario,DtPelicula pelicula);
    int getIdFuncion();
    DtFecha getFecha();
    DtHorario getHorario();
    DtPelicula getPelicula();
    ~DtFuncion();
};

#endif