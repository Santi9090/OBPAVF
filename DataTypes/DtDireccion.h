#ifndef DTDIRECCION_H
#define DTDIRECCION_H

#include <iostream>
using namespace std;

class DtDireccion {
private:
    string calle;
    int numero;
public:
    DtDireccion(string calle, int numero);
    string getCalle();
    int getNumero();
    ~DtDireccion();
};

#endif