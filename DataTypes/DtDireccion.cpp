#include "DtDireccion.h"
#include <iostream>
using namespace std;

DtDireccion::DtDireccion() {
}
DtDireccion::DtDireccion(string calle, int numero) {
    this->calle = calle;
    this->numero = numero;
}

string DtDireccion::getCalle() {
    return calle;
}

int DtDireccion::getNumero() {
    return numero;
}

DtDireccion::~DtDireccion() {}
