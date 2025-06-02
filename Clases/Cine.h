#ifndef CINE_H
#define CINE_H
#include "DtDireccion.h"
#include <string>
using namespace std;

class Cine {
private:
    int idCine;
    DtDireccion direccion;

public:
    Cine(int idCine, DtDireccion direccion);
    int getIdCine();
    DtDireccion getDireccion();
    void setIdCine(int idCine);
    void setDireccion(DtDireccion direccion);
    ~Cine();
};

#endif
