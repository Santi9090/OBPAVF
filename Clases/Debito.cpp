#include "Debito.h"

Debito::Debito(float costo, int cantEntradas, int idReserva,string banco) : Reserva(costo, cantEntradas, idReserva), banco(banco) {}
string Debito::getBanco()
{
    return banco;
}
void Debito::setBanco(string banco)
{
    this->banco = banco;
}
Debito::~Debito() {}
