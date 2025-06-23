#ifndef ICONTROLADORPELICULA_H
#define ICONTROLADORPELICULA_H

#include <string>
#include <map>
#include "../DataTypes/DtPelicula.h"
#include "../Clases/Pelicula.h"
using namespace std;

class IControladorPelicula {
public:
    virtual list<DtPelicula> ListarPeliculas() = 0;
    virtual void RegistrarPelicula(string titulo, string sinopsis, string urlFoto) = 0;
    virtual bool ExistePelicula(string titulo) = 0;
    virtual DtPelicula BuscarPelicula(string titulo) = 0;
    virtual void EliminarPelicula(string titulo) = 0;
    virtual void EliminarPeliculaCopilot(string titulo) = 0;
};

#endif
