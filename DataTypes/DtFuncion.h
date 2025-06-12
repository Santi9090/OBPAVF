#ifndef DTFUNCION_H
#define DTFUNCION_H

#include "DtFecha.h"
#include "DtHorario.h"

class DtFuncion {
private:
    int idFuncion;
    DtFecha fecha;
    DtHorario horario;
public:
    DtFuncion(int idFuncion, DtFecha fecha, DtHorario horario);
    int getIdFuncion() const;
    DtFecha getFecha() const;
    DtHorario getHorario() const;
    ~DtFuncion();
};

#endif