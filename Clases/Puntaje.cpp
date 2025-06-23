#include "Puntaje.h"
using namespace std;
Puntaje::Puntaje(int valor, Usuario *usuario, int idPuntaje) : valor(valor), usuario(usuario), idPuntaje(idPuntaje) {}
int Puntaje::getValor()
{
    return valor;
}
void Puntaje::setValor(int valor)
{
    this->valor = valor;
}

void Puntaje::setUsuario(Usuario *usuario)
{
    this->usuario = usuario;
}
Usuario *Puntaje::getUsuario()
{
    return this->usuario;
}
void Puntaje::setIdPuntaje(int idPuntaje){
    this->idPuntaje = idPuntaje;
}
int Puntaje::getIdPuntaje(){
    return this->idPuntaje;
}
Puntaje::~Puntaje() {}
