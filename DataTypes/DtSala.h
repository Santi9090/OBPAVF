#ifndef DTSALA_H
#define DTSALA_H

#include <iostream>
#include <map>
#include "DtFuncion.h"
#include <string>
#include <list>
using namespace std;

class DtSala {
private:
    int idSala;
    int capacidad;
    map <int, DtFuncion> funciones;
public:
    DtSala(int idSala, int capacidad);
    int getIdSala();
    int getCapacidad();
    list<DtFuncion> getFunciones();
    ~DtSala();
};

#endif