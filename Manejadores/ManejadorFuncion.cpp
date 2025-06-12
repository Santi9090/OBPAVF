#include "ManejadorFuncion.h"
#include "map"
#include <list>
using namespace std;


ManejadorFuncion *ManejadorFuncion::instancia = nullptr;

ManejadorFuncion::ManejadorFuncion() {}
ManejadorFuncion *ManejadorFuncion::getInstancia()
{
    if (instancia == nullptr)
    {
        instancia = new ManejadorFuncion();
    }
    return instancia;
}
void ManejadorFuncion::agregarFuncion(int idFuncion, Funcion *funcion)
{
    funciones.insert(pair<int, Funcion *>(idFuncion, funcion));
}

Funcion *ManejadorFuncion::buscarFuncion(int idFuncion)
{
    map<int, Funcion *>::iterator it = this->funciones.find(idFuncion);
    return it->second;
}

void ManejadorFuncion::eliminarFuncion(int idFuncion)
{
    map<int, Funcion *>::iterator it = this->funciones.find(idFuncion);
    this->funciones.erase(it);
}

list<Funcion *> ManejadorFuncion::getFunciones()
{
    list<Funcion*> listFunciones;
    for (map<int, Funcion *>::iterator it = this->funciones.begin(); it != funciones.end(); ++it)
        listFunciones.push_back(it->second);
    return listFunciones;
}

bool ManejadorFuncion::existeFuncion(int idFuncion)
{
  map<int, Funcion*>::iterator it = this->funciones.find(idFuncion);
  return (it != this->funciones.end());
}



ManejadorFuncion::~ManejadorFuncion()
{
}