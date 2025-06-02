#ifndef CINE_H
#define CINE_H
#include "DtDireccion.h"
#include "Sala.h"
#include <string>
#include <map>
#include <list>
using namespace std;

class Cine {
private:
    int idCine;
    DtDireccion direccion;
    map<int, Sala*> salas;
public:
    Cine(int idCine, DtDireccion direccion);
    int getIdCine();
    DtDireccion getDireccion();
    void setIdCine(int idCine);
    void setDireccion(DtDireccion direccion);
    void agregarSala(Sala* sala);
    list<Sala*> getSalas();
    Sala* buscarSala(int idSala);
    ~Cine();
};

#endif
