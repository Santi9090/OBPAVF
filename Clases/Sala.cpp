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

void Sala::agregarFuncion(Funcion* funcion) {
    funciones[funcion->getIdFuncion()] = funcion;
}

list<Funcion*> Sala::getFunciones() {
    list<Funcion*> lista;
    for (auto& par : funciones) {
        lista.push_back(par.second);
    }
    return lista;
}

void Sala::removePeliFuncion(string titulo) {
    // Implementación pendiente: eliminar función por título de película
}

Sala::~Sala() {
    // Liberar memoria de funciones si corresponde
}


    