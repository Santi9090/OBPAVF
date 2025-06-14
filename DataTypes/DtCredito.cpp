#include "DtCredito.h"
#include "DtReserva.h"
DtCredito::DtCredito(float costo, int cantEntradas, float porcentajeDescuento, string financiera)
    : DtReserva(costo, cantEntradas)
{
    this->porcentajeDescuento = porcentajeDescuento;
    this->financiera = financiera;
}
float DtCredito::getPorcentajeDescuento()
{
    return porcentajeDescuento;
}
string DtCredito::getFinanciera()
{
    return financiera;
}
