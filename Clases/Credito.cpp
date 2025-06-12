#include "Credito.h"

Credito::Credito(float costo, int cantEntradas, float descuento, string financiera)
    : Reserva(costo, cantEntradas), descuento(descuento), financiera(financiera) {}
float Credito::getDescuento()
{
    return descuento;
}
string Credito::getFinanciera()
{
    return financiera;
}
void Credito::setDescuento(float descuento)
{
    this->descuento = descuento;
}
void Credito::setFinanciera(string financiera)
{
    this->financiera = financiera;
}
Credito::~Credito() {}
