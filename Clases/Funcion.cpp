#include "Funcion.h"

Funcion::Funcion(int idFuncion, DtFecha fecha, DtHorario horario) {
    this->idFuncion = idFuncion;
    this->fecha = fecha;
    this->horario = horario;
}

int Funcion::getIdFuncion() {
    return idFuncion;
}

DtFecha Funcion::getFecha() {
    return fecha;
}

DtHorario Funcion::getHorario() {
    return horario;
}

void Funcion::setIdFuncion(int idFuncion) {
    this->idFuncion = idFuncion;
}

void Funcion::setFecha(DtFecha fecha) {
    this->fecha = fecha;
}

void Funcion::setHorario(DtHorario horario) {
    this->horario = horario;
}

Funcion::~Funcion() {}
