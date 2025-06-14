#include "DtReserva.h"
DtReserva::DtReserva(float costo, int cantEntradas)
    : costo(costo), cantEntradas(cantEntradas) {}
float DtReserva::getCosto() {
    return costo;
}
int DtReserva::getCantEntradas() {
    return cantEntradas;
}

