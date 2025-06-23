#ifndef PELICULA_H
#define PELICULA_H

#include <string>
#include <map>
#include "Cine.h"
#include "Funcion.h"
#include "Comentario.h"
#include "Puntaje.h"
using namespace std;
class Pelicula
{
private:
    map<int, Comentario *> comentarios;
    map <int, Puntaje*> puntajes;
    string titulo;
    string sinopsis;
    float puntajePromedio;
    string poster;

public:
    Pelicula(string &titulo, string &sinopsis, float puntajePromedio, string &poster);
    string getTitulo();
    string getSinopsis();
    float getPuntajePromedio();
    string getPoster();
    void setTitulo(string &titulo);
    void setSinopsis(string &sinopsis);
    void setPuntajePromedio(float puntaje);
    void setPoster(string &poster);
    string getTituloPelicula();
    void OlvidateDePelicula();
    void obtenerMasInfo();
    void getDtPelicula();
    void verInformacionAdicional(string &p);
    void setComentarios(map<int, Comentario *> comentarios);
    Comentario *getComentario(int idComentario);
    void agregarComentario(Comentario *comentario);
    list<Comentario *> getComentarios();


    void SetPuntajes(map <int, Puntaje*> puntajes);
    void agregarPuntaje(Puntaje *puntaje);
    list<Puntaje *> getPuntajes();

};

#endif
