#ifndef SALA_H
#define SALA_H

#include <string>
#include <map>
#include <list>
#include "Funcion.h"
#
using namespace std;

class Sala {
private:
    int idSala;
    int capacidad;
    map <int, Funcion*> funciones;
public:
    Sala(int id, int capacidad);
    int getId();
    int getCapacidad();
    void setId(int id);
    void setCapacidad(int capacidad);
    ~Sala();
};

#endif
