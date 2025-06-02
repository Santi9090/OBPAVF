#include "Debito.h"

Debito::Debito(float costo, int cantEntradas, string banco) : Reserva(costo, cantEntradas), banco(banco) {}
string Debito::getBanco()
{
    return banco;
}
void Debito::setBanco(string banco)
{
    this->banco = banco;
}
Debito::~Debito() {}
