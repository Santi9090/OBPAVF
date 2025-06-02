#include "Pelicula.h"
#include <iostream>

using namespace std;

Pelicula::Pelicula(string& titulo, string& sinopsis, float puntajePromedio, string& poster)
    : titulo(titulo), sinopsis(sinopsis), puntajePromedio(puntajePromedio), poster(poster) {}

string Pelicula::getTitulo() {
    return titulo;
}

string Pelicula::getSinopsis() {
    return sinopsis;
}

float Pelicula::getPuntajePromedio() {
    return puntajePromedio;
}

string Pelicula::getPoster() {
    return poster;
}

void Pelicula::setTitulo(string& titulo) {
    this->titulo = titulo;
}

void Pelicula::setSinopsis(string& sinopsis) {
    this->sinopsis = sinopsis;
}

void Pelicula::setPuntajePromedio(float puntaje) {
    this->puntajePromedio = puntaje;
}

void Pelicula::setPoster(string& poster) {
    this->poster = poster;
}

string Pelicula::getTituloPelicula() {
    return titulo;
}

void Pelicula::OlvidateDePelicula() {
    // Implementación vacía o lógica para "olvidar" la película
}

void Pelicula::obtenerMasInfo() {
    // Implementación vacía o lógica para obtener más información
}

void Pelicula::getDtPelicula() {
    // Implementación vacía o lógica para devolver un DtPelicula
}

void Pelicula::verInformacionAdicional(string& p) {
    // Implementación vacía o lógica para mostrar información adicional
}
