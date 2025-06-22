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
    list<DtSala> listaSalas;
    for (auto &cine : Mc->getCines())
    {
        list<Sala *> salas = cine->getSalas();
        for (auto &sala : salas)
        {
            DtSala dtSala(sala->getId(), sala->getCapacidad());
            listaSalas.push_back(dtSala);
        }
        DtCine dtCine(cine->getIdCine(), cine->getDireccion(), listaSalas, cine->getPeliculas());
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
    list<DtSala> listaSalas;

    for (auto &sala : cine->getSalas())
    {
        DtSala dtSala(sala->getId(), sala->getCapacidad());
        listaSalas.push_back(dtSala);
    }
    return listaSalas;
}

DtCine ControladorAltaCine::encontrarCine(int idCine)
{
    ManejadorCine *Mc = ManejadorCine::getInstancia();
    Cine *cine = Mc->buscarCine(idCine);
    list<DtSala> listaSalas;
    for (auto &cine : Mc->getCines())
    {
        list<Sala *> salas = cine->getSalas();
        for (auto &sala : salas)
        {
            DtSala dtSala(sala->getId(), sala->getCapacidad());
            listaSalas.push_back(dtSala);
        }
    }
    DtCine dtCine(cine->getIdCine(), cine->getDireccion(), listaSalas, cine->getPeliculas());
    return dtCine;
}
