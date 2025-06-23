#ifndef CONTROLADORPUNTAJECOMENTARIO_H
#define CONTROLADORPUNTAJECOMENTARIO_H
#include "../Interfaces/IControladorPuntajeComentario.h"
#include "../Clases/Puntaje.h"
#include "../Clases/Comentario.h"
#include <string>
using namespace std;
class ControladorPuntajeComentario : public IControladorPuntajeComentario
{
public:
    void agregarComentario(string comentario, string titulo);
    void agregarRespuesta(int idComentario, string comentario, string titulo);
    void listarComentarios(string titulo);

    void agregarPuntaje(int puntaje, string titulo);
    void listarPuntaje(string titulo);
    void listarPuntajes(string titulo);


};

#endif