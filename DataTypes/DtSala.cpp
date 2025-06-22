#include "DtSala.h"
#include <iostream>
using namespace std;


DtSala::DtSala(int idSala, int capacidad)
{
    this->idSala = idSala;
    this->capacidad = capacidad;
}    

int DtSala::getIdSala()
{
    return idSala;
}

int DtSala::getCapacidad()
{
    return capacidad;
}
list<DtFuncion> DtSala::getFunciones()
{
    list<DtFuncion> listaFunciones;
    for (map<int,DtFuncion>::iterator it=this->funciones.begin(); it!=funciones.end(); ++it)
        listaFunciones.push_back(it->second);
    return listaFunciones;
}
DtSala::~DtSala() {}
