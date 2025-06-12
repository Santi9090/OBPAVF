#include "DtSala.h"
#include <iostream>
using namespace std;

DtSala::DtSala(int idSala, int capacidad) {
    this->idSala = idSala;
    this->capacidad = capacidad;
}

int DtSala::getIdSala(){
    return idSala;
}

int DtSala::getCapacidad(){
    return capacidad;
}

DtSala::~DtSala() {}
