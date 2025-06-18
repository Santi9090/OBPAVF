#ifndef ICONTROLADORALTACINE_H
#define ICONTROLADORALTACINE_H

#include <string>
#include "../DataTypes/DtDireccion.h"
#include "../DataTypes/DtSala.h"
#include "../DataTypes/DtCine.h"

#include <map>
#include <list>
using namespace std;

class IControladorAltaCine
{
public:
    virtual void AltaCine(DtDireccion direccion, map<int, DtSala> dtSalas) = 0;
    virtual list<DtCine> getCines() = 0;
    virtual bool existeCine(int idCine) = 0;
    virtual list<DtSala> listarSalas(int idCine) = 0;
};

#endif
