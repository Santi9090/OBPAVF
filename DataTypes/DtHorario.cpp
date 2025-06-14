#include "DtHorario.h"

DtHorario::DtHorario() {}
DtHorario::DtHorario(int hora, int minuto) {
    this->hora = hora;
    this->minuto = minuto;
}

int DtHorario::getHora() const {
    return hora;
}

int DtHorario::getMinuto() const {
    return minuto;
}

DtHorario::~DtHorario() {}
