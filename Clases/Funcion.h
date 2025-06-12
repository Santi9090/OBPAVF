#ifndef FUNCION_H
#define FUNCION_H
#include "../DataTypes/DtFecha.h"
#include "../DataTypes/DtHorario.h"
#include <iostream>

using namespace std;

// Forward declaration
class Pelicula;

class Funcion
{
private:
    int idFuncion;
    DtFecha fecha;
    DtHorario horario;
    Pelicula* pelicula;
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