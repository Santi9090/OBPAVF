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
    DtCredito(float costo, int cantEntradas, float porcentajeDescuento, string financiera,int idReserva);
    float getPorcentajeDescuento();
    string getFinanciera();
};

#endif
