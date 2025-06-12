#include "Cine.h"
#include <string>
using namespace std;

Cine::Cine(int idCine, DtDireccion direccion)
    : idCine(idCine), direccion(direccion) {}

int Cine::getIdCine()
{
    return idCine;
}

DtDireccion Cine::getDireccion()
{
    return direccion;
}

void Cine::setIdCine(int idCine)
{
    this->idCine = idCine;
}

void Cine::setDireccion(DtDireccion direccion)
{
    this->direccion = direccion;
}

void Cine::agregarSala(Sala *sala)
{
    salas[sala->getId()] = sala;
}


Sala *Cine::buscarSala(int idSala)
{
    auto it = salas.find(idSala);
    if (it != salas.end())
        return it->second;
    return nullptr;
}

bool Cine::existeSala(int idSala)
{
    return salas.find(idSala) != salas.end();
}
void Cine::eliminarSala(int idSala)
{
    auto it = salas.find(idSala);
    if (it != salas.end())
    {
        delete it->second; // Liberar memoria de la sala
        salas.erase(it);   // Eliminar la sala del mapa
    }
}

map<int, Sala *> Cine::listarSalas()
{
    return salas;
}

Cine::~Cine()
{
    // Liberar memoria de salas si corresponde
}