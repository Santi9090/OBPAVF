#ifndef DTSALA_H
#define DTSALA_H

#include <iostream>
#include <map>
#include "DtFuncion.h"
#include <string>
#include <list>
using namespace std;

class DtSala
{
private:
    int idSala;
    int capacidad;
    map<int, DtFuncion> funciones;

public:
    DtSala();
    DtSala(int idSala, int capacidad);
    int getCapacidad();
    int getIdSala();
    list<DtFuncion> getFunciones();
    ~DtSala();
};

#endif