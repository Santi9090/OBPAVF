#include "ControladorAltaCine.h"
#include "../Manejadores/ManejadorCine.h"
#include "../Clases/Cine.h"
#include "../Clases/Sala.h"
#include <iostream>
using namespace std;
ControladorAltaCine::ControladorAltaCine() {}

void ControladorAltaCine::AltaCine(DtDireccion direccion,map <int, DtSala> dtSalas)
{
    ManejadorCine *Mc = ManejadorCine::getInstancia();
    Cine *nuevoCine = new Cine(Mc->getCines().size() + 1, direccion);
    Mc->agregarCine(nuevoCine);

    for (auto &sala : dtSalas) {
        Sala *nuevaSala = new Sala(sala.first, sala.second.getCapacidad());
        nuevoCine->agregarSala(nuevaSala);
    }
}

