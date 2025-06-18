#include "DtCine.h"
#include "DtDireccion.h"
#include <iostream>
using namespace std;

DtCine::DtCine(int idCine, DtDireccion direccion) {
    this->idCine = idCine;
    this->direccion = direccion;
}

int DtCine::getIdCine()  {
    return idCine;
}

DtDireccion DtCine::getDireccion() {
    return direccion;
}

DtCine::~DtCine() {}
