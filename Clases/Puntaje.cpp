#include "Puntaje.h"
using namespace std;
Puntaje::Puntaje(int valor) : valor(valor) {}
int Puntaje::getValor()
{
    return valor;
}
void Puntaje::setValor(int valor)
{
    this->valor = valor;
}
Puntaje::~Puntaje() {}
