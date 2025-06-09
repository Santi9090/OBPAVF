#ifndef CINE_H
#define CINE_H
#include "DtDireccion.h"
#include "Sala.h"
#include <string>
#include <map>
#include <list>
#include "Pelicula.h"
using namespace std;

class Cine {
private:
    int idCine;
    DtDireccion direccion;
    map<int, Sala*> salas;
    map<int , Pelicula*> peliculas;
public:
    Cine(int idCine, DtDireccion direccion);
    int getIdCine();
    DtDireccion getDireccion();
    void setIdCine(int idCine);
    void setDireccion(DtDireccion direccion);
    void agregarSala(Sala* sala);
    Sala* buscarSala(int idSala);
    bool existeSala(int idSala);
    void eliminarSala(int idSala);
    map<int, Sala*> listarSalas();
};

#endif
