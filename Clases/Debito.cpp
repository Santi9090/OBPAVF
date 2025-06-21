#include "Debito.h"

Debito::Debito(float costo, int cantEntradas, string banco, int idReserva) : Reserva(costo, cantEntradas, idReserva), banco(banco) {}
string Debito::getBanco()
{
    return banco;
}
void Debito::setBanco(string banco)
{
    this->banco = banco;
}
Debito::~Debito() {}
