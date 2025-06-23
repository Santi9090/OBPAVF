#ifndef CINE_H
#define CINE_H
#include "../DataTypes/DtDireccion.h"
#include <string>
#include <map>
#include <list>
#include "Sala.h"
#include "../DataTypes/DtSala.h"
#include "../DataTypes/DtPelicula.h"
#include "Pelicula.h"
using namespace std;

class Cine
{
private:
    int idCine;
    DtDireccion direccion;
    map<int, Sala *> salas;
    map<string, Pelicula *> peliculas;

public:
    Cine(int idCine, DtDireccion direccion);
    int getIdCine();
    DtDireccion getDireccion();
    void setIdCine(int idCine);
    void setDireccion(DtDireccion direccion);
    void agregarSala(Sala *sala);
    Sala *buscarSala(int idSala);
    bool existeSala(int idSala);
    void eliminarSala(int idSala);
    list<Sala*> getSalas();
    list<DtPelicula> getPeliculas();
    void eliminarPelicula(Pelicula* pelicula);
    void agregarPelicula( Pelicula * pelicula);
    bool existePelicula(string titulo);
    Pelicula* buscarPelicula(string titulo);
    ~Cine();

};

#endif
