#ifndef DTHORARIO_H
#define DTHORARIO_H

#include <iostream>
using namespace std;

class DtHorario {
private:
    string horaComienzo;
    string horaFin;
public:
    DtHorario();
    DtHorario(string horaComienzo, string horaFin);
    string getHoraComienzo() ;
    string getHoraFin();
    ~DtHorario();
};

#endif