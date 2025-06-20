#ifndef MANEJADOR_FUNCION_H
#define MANEJADOR_FUNCION_H
#include "../Clases/Funcion.h"
#include <string>
#include <map>
#include <list>
using namespace std;

class ManejadorFuncion
{
private:
    static ManejadorFuncion *instancia;
    map<int, Funcion *> funciones;
    ManejadorFuncion();

public:
    static ManejadorFuncion *getInstancia();
    void agregarFuncion( Funcion *funcion);
    Funcion *buscarFuncion(int idFuncion);
    void eliminarFuncion(int idFuncion);
    int generarIdFuncion();
    bool existeFuncion(int idFuncion);

    list<Funcion*> getFunciones();
    ~ManejadorFuncion();
};

#endif // MANEJADOR_FUNCION_H