#ifndef DTHORARIO_H
#define DTHORARIO_H

#include <iostream>
using namespace std;

class DtHorario {
private:
    int hora;
    int minuto;
public:
DtHorario();
    DtHorario(int hora, int minuto);
    int getHora() const;
    int getMinuto() const;
    ~DtHorario();
};

#endif