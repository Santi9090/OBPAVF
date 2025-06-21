#include "DtReserva.h"
DtReserva::DtReserva(float costo, int cantEntradas,int idReserva)
    : costo(costo), cantEntradas(cantEntradas), idReserva(idReserva) {}
float DtReserva::getCosto() {
    return costo;
}
int DtReserva::getCantEntradas() {
    return cantEntradas;
}
int DtReserva::getIdReserva() {
    return idReserva;
}

DtReserva::~DtReserva() {}