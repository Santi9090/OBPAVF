#include "ManejadorPelicula.h"
#include "Pelicula.h"
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
map<string, Pelicula*> ManejadorPelicula::listarPeliculas() {
    return peliculas;
}
ManejadorPelicula::~ManejadorPelicula() {
    for (auto& pair : peliculas) {
        delete pair.second; // Liberar memoria de cada película
    }
    peliculas.clear();
}