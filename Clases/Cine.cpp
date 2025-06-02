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


void Cine::agregarSala(Sala* sala) {
    salas[sala->getId()] = sala;
}

list<Sala*> Cine::getSalas() {
    list<Sala*> lista;
    for (auto& par : salas) {
        lista.push_back(par.second);
    }
    return lista;
}

Sala* Cine::buscarSala(int idSala) {
    auto it = salas.find(idSala);
    if (it != salas.end())
        return it->second;
    return nullptr;
}

Cine::~Cine() {
    // Liberar memoria de salas si corresponde
}
