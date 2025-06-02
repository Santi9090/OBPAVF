#ifndef SALA_H
#define SALA_H

#include <string>
#include <map>
#include <list>
#include "Funcion.h"
using namespace std;

class Sala {
private:
    int idSala;
    string direccion;
    map<int, Funcion*> funciones;
public:
    Sala(int id, string direccion);
    int getId();
    string getDireccion();
    void setId(int id);
    void setDireccion(string direccion);
    void agregarFuncion(Funcion* funcion);
    list<Funcion*> getFunciones();
    void removePeliFuncion(string titulo);
    ~Sala();
};

#endif
