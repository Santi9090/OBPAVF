#ifndef PELICULA_H
#define PELICULA_H

#include <string>
#include <map>
#include "Cine.h"
#include "Funcion.h"
using namespace std;
class Pelicula {
private:
   string titulo;
    string sinopsis;
    float puntajePromedio;
    string poster;
public:
    Pelicula(string& titulo, string& sinopsis, float puntajePromedio, string& poster);
    string getTitulo();
    string getSinopsis();
    float getPuntajePromedio();
    string getPoster();
    void setTitulo(string& titulo);
    void setSinopsis(string& sinopsis);
    void setPuntajePromedio(float puntaje);
    void setPoster(string& poster);
    string getTituloPelicula();
    void OlvidateDePelicula();
    void obtenerMasInfo();
    void getDtPelicula();
    void verInformacionAdicional(string& p);
    


};

#endif 
