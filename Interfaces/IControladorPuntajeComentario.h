#ifndef ICONTROLADORPUNTAJECOMENTARIO_H
#define ICONTROLADORPUNTAJECOMENTARIO_H
#include "../Clases/Puntaje.h"
#include "../Clases/Comentario.h"
#include <string>
using namespace std;

class IControladorPuntajeComentario
{
public:
    virtual void agregarComentario(string comentario, string titulo) = 0;
    virtual void agregarRespuesta(int idComentario, string comentario, string titulo) = 0;
    virtual void listarComentarios(string titulo) = 0;
    virtual void agregarPuntaje(int puntaje, string titulo) = 0;
    virtual void listarPuntaje(string titulo) = 0;
    virtual void listarPuntajes(string titulo) = 0;
};

#endif