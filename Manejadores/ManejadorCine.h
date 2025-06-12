#ifndef MANEJADORCINE_H
#define MANEJADORCINE_H

#include "../Clases/Cine.h"
#include <map>
#include <list>
#include <string>
using namespace std;

class ManejadorCine {
private:
    static ManejadorCine* instancia;
    map<int, Cine*> cines;
    ManejadorCine();
public:
    static ManejadorCine* getInstancia();
    list<Cine*> getCines();
    Cine* buscarCine(int idCine);
    void agregarCine(Cine* cine);
    bool existeCine(int idCine);
    void eliminarCine(int idCine);
    virtual ~ManejadorCine();

    
};

#endif
