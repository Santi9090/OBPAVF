#ifndef DTCREDITO_H
#define DTCREDITO_H

#include <string>
#include "DtReserva.h"
using namespace std;

class DtCredito : public DtReserva
{
private:
    float porcentajeDescuento;
    string financiera;

public:
    DtCredito(float costo, int cantEntradas, int idReserva, float porcentajeDescuento, string financiera);
    float getPorcentajeDescuento();
    string getFinanciera();
};

#endif
