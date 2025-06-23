#ifndef CONTROLADORPELICULA_H
#define CONTROLADORPELICULA_H

#include <string>
#include "../Interfaces/IControladorPelicula.h"
#include "../DataTypes/DtPelicula.h"
#include <map>
#include "../Clases/Pelicula.h"
using namespace std;

class ControladorPelicula : public IControladorPelicula
{
public:
    void RegistrarPelicula(string titulo, string sinopsis, string urlFoto);
    list<DtPelicula> ListarPeliculas();
    bool ExistePelicula(string titulo);
    DtPelicula BuscarPelicula(string titulo);
    void EliminarPelicula(string titulo);
};

#endif
