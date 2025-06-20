#include "DtPelicula.h"
#include <iostream>
using namespace std;

DtPelicula::DtPelicula(string titulo, string sinopsis, float puntajePromedio, string poster)
{
    this->titulo = titulo;
    this->sinopsis = sinopsis;
    this->puntajePromedio = puntajePromedio;
    this->poster = poster;
}

string DtPelicula::getTitulo()
{
    return titulo;
}

string DtPelicula::getSinopsis()
{
    return sinopsis;
}

float DtPelicula::getPuntajePromedio()
{
    return puntajePromedio;
}

string DtPelicula::getPoster()
{
    return poster;
}

DtPelicula::~DtPelicula() {}
