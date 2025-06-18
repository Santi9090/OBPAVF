#ifndef DTCINE_H
#define DTCINE_H

#include <iostream>
#include "DtDireccion.h"
using namespace std;

class DtCine {
private:
    int idCine;
    DtDireccion direccion;
public:
    DtCine(int idCine, DtDireccion direccion);
    int getIdCine();
    DtDireccion getDireccion();
    ~DtCine();
};

#endif