#ifndef DTFCHA_H
#define DTFCHA_H

#include <iostream>
using namespace std;

class DtFecha {
private:
    int dia;
    int mes;
    int anio;
public:
DtFecha();
    DtFecha(int dia, int mes, int anio);
    int getDia();
    int getMes();
    int getAnio();
    ~DtFecha();
};

#endif