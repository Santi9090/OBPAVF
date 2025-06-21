#ifndef DTDEBITO_H
#define DTDEBITO_H
#include "DtReserva.h"
#include <string>
using namespace std;

class DtDebito : public DtReserva
{
private:
    string banco;

public:
    DtDebito(float costo, int cantEntradas, string banco,int idReserva);
    string getBanco();
};

#endif
