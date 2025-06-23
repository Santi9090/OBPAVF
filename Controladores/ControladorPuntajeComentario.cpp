#include "ControladorPuntajeComentario.h"
#include "../Manejadores/ManejadorPelicula.h"
#include "../Clases/Pelicula.h"
#include "../Clases/Comentario.h"
#include "../Clases/Sesion.h"
void ControladorPuntajeComentario::agregarComentario(string comentario, string titulo)
{
    ManejadorPelicula *mP = ManejadorPelicula::getInstancia();
    Pelicula *pelicula = mP->buscarPelicula(titulo);
    Sesion *sesion = Sesion::getInstancia();
    Usuario *usuario = sesion->getUsuario();
    Comentario *comentario1 = new Comentario(comentario, nullptr, usuario, pelicula->getComentarios().size());
    pelicula->agregarComentario(comentario1);
}
void ControladorPuntajeComentario::agregarRespuesta(int idComentario, string comentario, string titulo)
{
    ManejadorPelicula *mP = ManejadorPelicula::getInstancia();
    Pelicula *pelicula = mP->buscarPelicula(titulo);
    Sesion *sesion = Sesion::getInstancia();
    Usuario *usuario = sesion->getUsuario();
    Comentario *comentariorespuesta = pelicula->getComentario(idComentario);
    Comentario *comentario1 = new Comentario(comentario, comentariorespuesta, usuario, (pelicula->getComentarios().size() + 1));
    pelicula->agregarComentario(comentario1);
}

void ControladorPuntajeComentario::listarComentarios(string titulo)
{
    ManejadorPelicula *mP = ManejadorPelicula::getInstancia();
    Pelicula *pelicula = mP->buscarPelicula(titulo);
    list<Comentario *> comentarios = pelicula->getComentarios();
    for (auto &Comentario : comentarios)
    {
        if (Comentario->getComentario() == nullptr)
        {
            cout << "ID:" << Comentario->getIdComentario() << "<" << Comentario->getUsuario()->getNickname() << ">: "
                 << "<" << Comentario->getTexto() << ">" << endl;
        }
        else
        {
            cout << "ID:" << Comentario->getIdComentario() << "<" << Comentario->getUsuario()->getNickname() << ">: "
                 << "<" << Comentario->getTexto() << "Respuesta al comentario de:"
                 << Comentario->getComentario()->getUsuario()->getNickname() << ">" << endl;
        }
    }
}

void ControladorPuntajeComentario::agregarPuntaje(int puntaje, string titulo)
{
    ManejadorPelicula *mP = ManejadorPelicula::getInstancia();
    Pelicula *pelicula = mP->buscarPelicula(titulo);
    Sesion *sesion = Sesion::getInstancia();
    Usuario *usuario = sesion->getUsuario();
    list<Puntaje *> puntajes = pelicula->getPuntajes();
    for (auto &Puntaje : puntajes)
    {
        if (Puntaje->getUsuario() == usuario)
        {
            Puntaje->setValor(puntaje);
            return;
        }
    }
    Puntaje *puntaje1 = new Puntaje(puntaje, usuario, (pelicula->getPuntajes().size() + 1));
    pelicula->agregarPuntaje(puntaje1);
}
void ControladorPuntajeComentario::listarPuntaje(string titulo)
{
    ManejadorPelicula *mP = ManejadorPelicula::getInstancia();
    Pelicula *pelicula = mP->buscarPelicula(titulo);
    Sesion *sesion = Sesion::getInstancia();
    Usuario *usuario = sesion->getUsuario();
    list<Puntaje *> puntajes = pelicula->getPuntajes();
    cout << "Usuario en sesion " << usuario->getNickname() << endl;
    for (auto &Puntaje : puntajes)
    {
        if (Puntaje->getUsuario() == usuario)
        {
            cout << "Puntaje Anterior: " << Puntaje->getValor() << endl;
        }
    }
}
void ControladorPuntajeComentario::listarPuntajes(string titulo)
{
    ManejadorPelicula *mP = ManejadorPelicula::getInstancia();
    Pelicula *pelicula = mP->buscarPelicula(titulo);
    list<Puntaje *> puntajes = pelicula->getPuntajes();
    for (auto &Puntaje : puntajes)
    {
        cout << "<" << Puntaje->getUsuario()->getNickname() << ">"
             << "<" << Puntaje->getValor() << ">" << endl;
    }
}