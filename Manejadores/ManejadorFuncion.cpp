#include "ManejadorFuncion.h"
#include "map"
#include <list>
#include "../DataTypes/DtFuncion.h"

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
void ManejadorFuncion::agregarFuncion(Funcion *funcion)
{
    funciones.insert(std::pair<int, Funcion *>(funcion->getIdFuncion(), funcion));
}

Funcion *ManejadorFuncion::buscarFuncion(int idFuncion)
{
    map<int, Funcion *>::iterator it = this->funciones.find(idFuncion);
    return it->second;
}

bool ManejadorFuncion::existeFuncion(int idFuncion)
{
    map<int, Funcion *>::iterator it = this->funciones.find(idFuncion);
    return (it != this->funciones.end());
}

int ManejadorFuncion::generarIdFuncion()
{
    int contador = 0;
    for (map<int, Funcion *>::iterator it = this->funciones.begin(); it != funciones.end(); ++it)
    {
        contador++;
    }
    return contador + 1;
}

list<Funcion *> ManejadorFuncion::getFunciones()
{
    list<Funcion *> lstFunciones;
    for (map<int, Funcion *>::iterator it = this->funciones.begin(); it != funciones.end(); ++it)
    {
        lstFunciones.push_back(it->second);
    }
    return lstFunciones;
}
void ManejadorFuncion::eliminarFuncion(int idFuncion)
{
    map<int, Funcion *>::iterator it = this->funciones.find(idFuncion);
    if (it != this->funciones.end())
    {
        delete it->second;         // Liberar memoria de la función
        this->funciones.erase(it); // Eliminar la función del mapa
    }
}

ManejadorFuncion::~ManejadorFuncion()
{
}