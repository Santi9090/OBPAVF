#include "Cine.h"
#include <string>
#include <map>
#include <list>
#include "../DataTypes/DtSala.h"
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
    salas.insert(std::pair<int,Sala*>(sala->getId(),sala));
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

list<DtSala> Cine::getSalas()
{
    list<DtSala> listaSalas;
    for (auto &sala : salas)
    {
        DtSala dtSala(sala.second->getId(), sala.second->getCapacidad());
        listaSalas.push_back(dtSala);
    }
    return listaSalas;

}

Cine::~Cine()
{
}