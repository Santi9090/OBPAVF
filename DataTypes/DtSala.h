#ifndef DTSALA_H
#define DTSALA_H

#include <iostream>
using namespace std;

class DtSala {
private:
    int idSala;
    int capacidad;
public:
    DtSala(int idSala, int capacidad);
    int getIdSala();
    int getCapacidad();
    ~DtSala();
};

#endif