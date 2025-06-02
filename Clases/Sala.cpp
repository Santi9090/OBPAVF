#include "Sala.h"
#include <algorithm>

Sala::Sala(int idSala, string direccion) : idSala(idSala), direccion(direccion) {}

int Sala::getId() {
    return idSala;
}

string Sala::getDireccion() {
    return direccion;
}

void Sala::setId(int idSala) {
    this->idSala = idSala;
}

void Sala::setDireccion(string direccion) {
    this->direccion = direccion;
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
