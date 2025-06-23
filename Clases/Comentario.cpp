#include "Comentario.h"
using namespace std;
Comentario::Comentario(string texto, Comentario *comentario, Usuario *usuario, int idComentario)
{
    this->texto = texto;
    this->comentario = comentario;
    this->usuario = usuario;
    this->idComentario = idComentario;
}

void Comentario::setIdComentario(int idComentario)
{
    this->idComentario = idComentario;
}

int Comentario::getIdComentario()
{
    return idComentario;
}
string Comentario::getTexto()
{
    return texto;
}
void Comentario::setTexto(string texto)
{
    this->texto = texto;
}

Comentario *Comentario::getComentario()
{
    return this->comentario;
}
void Comentario::setComentario(Comentario *comentario)
{
    this->comentario = comentario;
}
void Comentario::setUsuario(Usuario *usuario)
{
    this->usuario = usuario;
}
Usuario *Comentario::getUsuario()
{
    return this->usuario;
}

void Comentario::agregarComentario(Comentario *comentario)
{
    this->comentario = comentario;
}

Comentario *Comentario::getComentario(int idComentario)
{
    return this->comentario;
}
Comentario::~Comentario() {}
