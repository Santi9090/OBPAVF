#ifndef DTCINE_H
#define DTCINE_H

#include <iostream>
using namespace std;

class DtCine {
private:
    int idCine;
    string direccion;
public:
    DtCine(int idCine, string direccion);
    int getIdCine();
    string getDireccion();
    ~DtCine();
};

#endif