#include "ManejadorPelicula.h"
#include "../Clases/Pelicula.h"
#include <iostream>
#include <map>
using namespace std;

ManejadorPelicula* ManejadorPelicula::instancia = NULL;

ManejadorPelicula::ManejadorPelicula() {}

ManejadorPelicula* ManejadorPelicula::getInstancia() {
    if (instancia == NULL)
        instancia = new ManejadorPelicula();
    return instancia;
}

void ManejadorPelicula::agregarPelicula(Pelicula* pelicula) {
    peliculas.insert(pair<string, Pelicula*>(pelicula->getTitulo(), pelicula));
}

Pelicula* ManejadorPelicula::buscarPelicula(string titulo) {
    map<string, Pelicula*>::iterator it = peliculas.find(titulo);
    if (it != peliculas.end())
        return it->second;
    return NULL;
}

bool ManejadorPelicula::existePelicula(string titulo) {
    return peliculas.find(titulo) != peliculas.end();
}

void ManejadorPelicula::eliminarPelicula(string titulo) {
    map<string, Pelicula*>::iterator it = peliculas.find(titulo);
    if (it != peliculas.end()) {
        delete it->second; // Liberar memoria de la película
        peliculas.erase(it);
    }
}

list<DtPelicula> ManejadorPelicula::listarPeliculas() {
    list<DtPelicula> lista;
    for (map<string, Pelicula*>::iterator it = peliculas.begin(); it != peliculas.end(); ++it) {
        Pelicula* pelicula = it->second;
        DtPelicula dtPelicula(pelicula->getTitulo(), pelicula->getSinopsis(), pelicula->getPuntajePromedio(), pelicula->getPoster());
        lista.push_back(dtPelicula);
    }
    return lista;
}

ManejadorPelicula::~ManejadorPelicula() {
    // Liberar memoria de todas las películas
    for (map<string, Pelicula*>::iterator it = peliculas.begin(); it != peliculas.end(); ++it) {
        delete it->second;
    }
    peliculas.clear();
}