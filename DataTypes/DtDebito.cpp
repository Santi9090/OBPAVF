#include "DtDebito.h"
DtDebito::DtDebito(float costo, int cantEntradas,int idReserva, string banco)
    : DtReserva(costo, cantEntradas,idReserva) {
        this->banco = banco;
    }

    string DtDebito::getBanco() {
    return banco;
}
