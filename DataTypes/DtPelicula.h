#ifndef DTPELICULA_H
#define DTPELICULA_H
#include <iostream>
using namespace std;

class DtPelicula {
private:
    string titulo;
    string sinopsis;
    float puntajePromedio;
    string poster;
public:
    DtPelicula(string titulo, string sinopsis, float puntajePromedio, string poster);
    string getTitulo() const;
    string getSinopsis() const;
    float getPuntajePromedio() const;
    string getPoster() const;
    ~DtPelicula();
};