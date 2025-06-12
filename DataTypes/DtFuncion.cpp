#include "DtFuncion.h"

DtFuncion::DtFuncion(int idFuncion, DtFecha fecha, DtHorario horario) {
    this->idFuncion = idFuncion;
    this->fecha = fecha;
    this->horario = horario;
}

int DtFuncion::getIdFuncion() const {
    return idFuncion;
}

DtFecha DtFuncion::getFecha() const {
    return fecha;
}

DtHorario DtFuncion::getHorario() const {
    return horario;
}

DtFuncion::~DtFuncion() {}
