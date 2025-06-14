#include "DtDebito.h"
DtDebito::DtDebito(float costo, int cantEntradas, string banco)
    : DtReserva(costo, cantEntradas) {
        this->banco = banco;
    }

    string DtDebito::getBanco() {
    return banco;
}
