#include "Pelicula.h"
#include <iostream>
#include <map>
using namespace std;

Pelicula::Pelicula(string &titulo, string &sinopsis, float puntajePromedio, string &poster)
    : titulo(titulo), sinopsis(sinopsis), puntajePromedio(puntajePromedio), poster(poster) {}

string Pelicula::getTitulo()
{
    return titulo;
}

string Pelicula::getSinopsis()
{
    return sinopsis;
}

float Pelicula::getPuntajePromedio()
{
    return puntajePromedio;
}

string Pelicula::getPoster()
{
    return poster;
}

void Pelicula::setTitulo(string &titulo)
{
    this->titulo = titulo;
}

void Pelicula::setSinopsis(string &sinopsis)
{
    this->sinopsis = sinopsis;
}

void Pelicula::setPuntajePromedio(float puntaje)
{
    this->puntajePromedio = puntaje;
}

void Pelicula::setPoster(string &poster)
{
    this->poster = poster;
}

string Pelicula::getTituloPelicula()
{
    return titulo;
}

void Pelicula::setComentarios(map<int, Comentario *> comentarios)
{
    this->comentarios = comentarios;
}

Comentario *Pelicula::getComentario(int idComentario)
{
    for (auto it = comentarios.begin(); it != comentarios.end(); it++)
    {
        if (it->second->getIdComentario() == idComentario)
        {
            return it->second;
        }
    }
    return nullptr;
}
void Pelicula::agregarComentario(Comentario *comentario)
{
    comentarios.insert({comentario->getIdComentario(), comentario});
}

list<Comentario *> Pelicula::getComentarios()
{
    list<Comentario *> listaComentarios;
    for (auto it = comentarios.begin(); it != comentarios.end(); it++)
    {
        listaComentarios.push_back(it->second);
    }
    return listaComentarios;
}

void Pelicula::SetPuntajes(map<int, Puntaje *> puntajes)
{
    this->puntajes = puntajes;
}

void Pelicula::agregarPuntaje(Puntaje *puntaje)
{
    puntajes.insert({puntaje->getIdPuntaje(), puntaje});
}

list<Puntaje *> Pelicula::getPuntajes()
{
    list<Puntaje *> listaPuntajes;
    for (auto it = puntajes.begin(); it != puntajes.end(); it++)
    {
        listaPuntajes.push_back(it->second);
    }
    return listaPuntajes;
}