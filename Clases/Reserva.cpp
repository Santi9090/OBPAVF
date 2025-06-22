#include "Reserva.h"

Reserva::Reserva( float costo, int cantEntradas,int idReserva) : costo(costo), cantEntradas(cantEntradas),idReserva(idReserva) {}

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
