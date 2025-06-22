#include "DtCredito.h"
#include "DtReserva.h"
DtCredito::DtCredito(float costo, int cantEntradas,int idReserva,float porcentajeDescuento, string financiera)
    : DtReserva(costo, cantEntradas,idReserva)
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
