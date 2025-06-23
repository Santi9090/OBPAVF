#include "Cine.h"
#include <string>
#include <map>
#include <list>
#include "../DataTypes/DtSala.h"
#include "../DataTypes/DtPelicula.h"
#include "Pelicula.h"
using namespace std;

Cine::Cine(int idCine, DtDireccion direccion)
    : idCine(idCine), direccion(direccion) {}

int Cine::getIdCine()
{
    return idCine;
}

DtDireccion Cine::getDireccion()
{
    return direccion;
}

void Cine::setIdCine(int idCine)
{
    this->idCine = idCine;
}

void Cine::setDireccion(DtDireccion direccion)
{
    this->direccion = direccion;
}

void Cine::agregarSala(Sala *sala)
{
    salas.insert(std::pair<int, Sala *>(sala->getId(), sala));
}

Sala *Cine::buscarSala(int idSala)
{
    auto it = salas.find(idSala);
    if (it != salas.end())
        return it->second;
    return nullptr;
}

bool Cine::existeSala(int idSala)
{
    return salas.find(idSala) != salas.end();
}
void Cine::eliminarSala(int idSala)
{
    auto it = salas.find(idSala);
    if (it != salas.end())
    {
        delete it->second; // Liberar memoria de la sala
        salas.erase(it);   // Eliminar la sala del mapa
    }
}

list<Sala*> Cine::getSalas()
{
    list<Sala*> listaSalas;
    for (auto &sala : salas)
    {
        listaSalas.push_back(sala.second);
    }
    return listaSalas;
}

list<DtPelicula> Cine::getPeliculas()
{
    list<DtPelicula> listaPeliculas;
    for (auto &pelicula : peliculas)
    {
        DtPelicula dtPelicula(pelicula.second->getTitulo(), pelicula.second->getSinopsis(), pelicula.second->getPuntajePromedio(), pelicula.second->getPoster());
        listaPeliculas.push_back(dtPelicula);
    }
    return listaPeliculas;
}
void Cine::agregarPelicula(Pelicula *pelicula)
{
    peliculas.insert(std::pair<string, Pelicula *>(pelicula->getTitulo(), pelicula));
}

void Cine::eliminarPelicula(Pelicula *pelicula)
{
    auto it = peliculas.find(pelicula->getTitulo());
    if (it != peliculas.end())
    {   
        
        peliculas.erase(it); // Eliminar la película del mapa
    }
}
bool Cine::existePelicula(string titulo)
{
    return peliculas.find(titulo) != peliculas.end();
}

Pelicula* Cine::buscarPelicula(string titulo)
{
    auto it = peliculas.find(titulo);
    if (it != peliculas.end())
        return it->second;
    return nullptr;
}
Cine::~Cine()
{
}