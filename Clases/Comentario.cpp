#include "Comentario.h"
using namespace std;
Comentario::Comentario(string texto) : texto(texto)
{
}
string Comentario::getTexto()
{
    return texto;
}
void Comentario::setTexto(string texto)
{
    this->texto = texto;
}
Comentario::~Comentario() {}
