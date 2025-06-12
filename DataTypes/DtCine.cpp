#include "DtCine.h"
#include <iostream>
using namespace std;

DtCine::DtCine(int idCine, string direccion) {
    this->idCine = idCine;
    this->direccion = direccion;
}

int DtCine::getIdCine()  {
    return idCine;
}

string DtCine::getDireccion() {
    return direccion;
}

DtCine::~DtCine() {}
