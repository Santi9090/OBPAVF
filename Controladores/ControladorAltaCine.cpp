#include "ControladorAltaCine.h"
#include "../Manejadores/ManejadorCine.h"
#include "../Clases/Cine.h"
#include "../Clases/Sala.h"
#include <iostream>
using namespace std;
ControladorAltaCine::ControladorAltaCine() {}

void ControladorAltaCine::AltaCine(DtDireccion direccion, map<int, DtSala> dtSalas)
{
    ManejadorCine *Mc = ManejadorCine::getInstancia();
    Cine *nuevoCine = new Cine(Mc->getCines().size() + 1, direccion);
    Mc->agregarCine(nuevoCine);

    for (auto &sala : dtSalas)
    {
        Sala *nuevaSala = new Sala(sala.first, sala.second.getCapacidad());
        nuevoCine->agregarSala(nuevaSala);
    }
}

list<DtCine> ControladorAltaCine::getCines()
{
    ManejadorCine *Mc = ManejadorCine::getInstancia();
    list<DtCine> listaCines;
    for (auto &cine : Mc->getCines())
    {
        DtCine dtCine(cine->getIdCine(), cine->getDireccion(), cine->getSalas(), cine->getPeliculas());
        listaCines.push_back(dtCine);
    }
    return listaCines;
}

bool ControladorAltaCine::existeCine(int idCine)
{
    ManejadorCine *Mc = ManejadorCine::getInstancia();
    return Mc->existeCine(idCine);
}

list<DtSala> ControladorAltaCine::listarSalas(int idCine)
{
    ManejadorCine *Mc = ManejadorCine::getInstancia();
    Cine *cine = Mc->buscarCine(idCine);
    if (cine == NULL)
    {
        return list<DtSala>();
    }
    return cine->getSalas();
}

DtCine ControladorAltaCine::encontrarCine(int idCine)
{
    ManejadorCine *Mc = ManejadorCine::getInstancia();
    Cine *cine = Mc->buscarCine(idCine);
    DtCine dtCine(cine->getIdCine(), cine->getDireccion(), cine->getSalas(), cine->getPeliculas());
    return dtCine;
}
