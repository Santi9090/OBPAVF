#include "Reserva.h"

Reserva::Reserva(float costo, int cantEntradas) : costo(costo), cantEntradas(cantEntradas) {}

float Reserva::getCosto()
{
    return costo;
}
int Reserva::getCantEntradas()
{
    return cantEntradas;
}
void Reserva::setCosto(float costo)
{
    this->costo = costo;
}
void Reserva::setCantEntradas(int cantEntradas)
{
    this->cantEntradas = cantEntradas;
}
Reserva::~Reserva() {}
