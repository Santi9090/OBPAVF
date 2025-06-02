#include "DtPelicula.h"
#include <iostream>
using namespace std;

DtPelicula::DtPelicula(string titulo, string sinopsis, float puntajePromedio, string poster) {
    this->titulo = titulo;
    this->sinopsis = sinopsis;
    this->puntajePromedio = puntajePromedio;
    this->poster = poster;
}

string DtPelicula::getTitulo() const {
    return titulo;
}

string DtPelicula::getSinopsis() const {
    return sinopsis;
}

float DtPelicula::getPuntajePromedio() const {
    return puntajePromedio;
}

string DtPelicula::getPoster() const {
    return poster;
}

DtPelicula::~DtPelicula() {}
