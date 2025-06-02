#include "Cine.h"
using namespace std;

Cine::Cine(int idCine, DtDireccion direccion)
    : idCine(idCine), direccion(direccion) {}

int Cine::getIdCine() {
    return idCine;
}

DtDireccion Cine::getDireccion() {
    return direccion;
}

void Cine::setIdCine(int idCine) {
    this->idCine = idCine;
}

void Cine::setDireccion(DtDireccion direccion) {
    this->direccion = direccion;
}

Cine::~Cine() {
    // Destructor
}
