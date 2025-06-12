#include "Sala.h"
#include <algorithm>

Sala::Sala(int idSala, int capacidad) : idSala(idSala), capacidad(capacidad) {}

int Sala::getId() {
    return idSala;
}

int Sala::getCapacidad() {
    return capacidad;
}

void Sala::setId(int idSala) {
    this->idSala = idSala;
}

void Sala::setCapacidad(int capacidad) {
    this->capacidad = capacidad;
}


Sala::~Sala() {
    // Liberar memoria de funciones si corresponde
}


    