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
    string getTitulo();
    string getSinopsis() ;
    float getPuntajePromedio() ;
    string getPoster();
    ~DtPelicula();
};

#endif