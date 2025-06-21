#include "Reserva.h"

Reserva::Reserva(int idReserva, float costo, int cantEntradas) : idReserva(idReserva), costo(costo), cantEntradas(cantEntradas) {}

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
int Reserva::getIdReserva()
{
    return idReserva;
}
Reserva::~Reserva() {}
