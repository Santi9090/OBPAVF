#include "DtHorario.h"

DtHorario::DtHorario() {}
DtHorario::DtHorario(string horaComienzo, string horaFin)
{
    this->horaComienzo = horaComienzo;
    this->horaFin = horaFin;
}

string DtHorario::getHoraComienzo()
{
    return horaComienzo
}

string DtHorario::getHoraFin()
{
    return horaFin;
}

DtHorario::~DtHorario() {}
