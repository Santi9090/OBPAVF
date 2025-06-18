#ifndef MANEJADORPELICULA_H
#define MANEJADORPELICULA_H

#include <map>
#include "../Clases/Pelicula.h"
#include "../DataTypes/DtPelicula.h"
#include "../DataTypes/DtCine.h"
#include "../DataTypes/DtFuncion.h"

using namespace std;

class ManejadorPelicula {
private:
    map<string,Pelicula*> peliculas;
    static ManejadorPelicula* instancia;
    ManejadorPelicula();
public:
    static ManejadorPelicula* getInstancia();
    ~ManejadorPelicula();
    void agregarPelicula(Pelicula* pelicula);
    Pelicula* buscarPelicula(string titulo);
    bool existePelicula(string titulo);
    void eliminarPelicula(string titulo);
    list<DtPelicula> listarPeliculas();
};
    
#endif
