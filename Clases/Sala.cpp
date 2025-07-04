#include "Sala.h"
#include <algorithm>

Sala::Sala(int idSala, int capacidad) : idSala(idSala), capacidad(capacidad) {}

int Sala::getId()
{
    return idSala;
}

int Sala::getCapacidad()
{
    return capacidad;
}

void Sala::setId(int idSala)
{
    this->idSala = idSala;
}

void Sala::setCapacidad(int capacidad)
{
    this->capacidad = capacidad;
}

void Sala::agregarFuncion(Funcion *funcion)
{
    funciones.insert(std::pair<int, Funcion *>(funcion->getIdFuncion(), funcion));
}


list<Funcion *> Sala::getFunciones()
{
    list<Funcion *> listaFunciones;
    for (auto &funcion : funciones)
    {
        listaFunciones.push_back(funcion.second);
    }
    return listaFunciones;
}

void Sala::eliminarFuncion(int idFuncion)
{
    auto it = funciones.find(idFuncion);
    if (it != funciones.end()) {
        funciones.erase(it);
    }
}

Sala::~Sala()
{
    // Liberar memoria de funciones si corresponde
}
