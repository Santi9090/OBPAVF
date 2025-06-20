#ifndef CONTROLADORALTACINE_H
#define CONTROLADORALTACINE_H
#include "../Interfaces/IControladorAltaCine.h"
#include <string>
#include "../DataTypes/DtDireccion.h"
#include "../DataTypes/DtSala.h"
#include "../DataTypes/DtCine.h"
using namespace std;

class ControladorAltaCine : public IControladorAltaCine
{
public:
    ControladorAltaCine();
    void AltaCine(DtDireccion direccion, map<int, DtSala> dtSalas);
    list<DtCine> getCines();
    bool existeCine(int idCine);
    list<DtSala> listarSalas(int idCine);
    DtCine encontrarCine(int idCine);
};

#endif
