#include "DtDebito.h"
DtDebito::DtDebito(float costo, int cantEntradas, string banco,int idReserva)
    : DtReserva(costo, cantEntradas,idReserva) {
        this->banco = banco;
    }

    string DtDebito::getBanco() {
    return banco;
}
