#ifndef MANEJADOR_FUNCION_H
#define MANEJADOR_FUNCION_H
#include "Funcion.h"
#include <string>
#include <map>
using namespace std;

class ManejadorFuncion
{
private:
    static ManejadorFuncion *instancia;
    map<int, Funcion *> funciones;
    ManejadorFuncion();

public:
    static ManejadorFuncion *getInstancia();
    void agregarFuncion(int idFuncion, Funcion *funcion);
    Funcion *buscarFuncion(int idFuncion);
    void eliminarFuncion(int idFuncion);
    list<Funcion *> getFunciones();
    bool existeFuncion(int idFuncion);
    ~ManejadorFuncion();
};

#endif // MANEJADOR_FUNCION_H