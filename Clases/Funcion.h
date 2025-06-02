#ifndef FUNCION_H
#define FUNCION_H
#include "DtFecha.h"
#include "DtHorario.h"
#include <iostream>
using namespace std;



class Funcion
{
private:
    int idFuncion;
    DtFecha fecha;
    DtHorario horario;
public:
    Funcion(int idFuncion, DtFecha fecha, DtHorario horario);
    int getIdFuncion();
    DtFecha getFecha();
    DtHorario getHorario();
    void setIdFuncion(int idFuncion);
    void setFecha(DtFecha fecha);
    void setHorario(DtHorario horario);
    ~Funcion();
};

#endif