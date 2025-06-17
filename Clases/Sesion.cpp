#include "Sesion.h"
#include "Usuario.h"

Sesion* Sesion::instancia = NULL;

Sesion::Sesion() {
    usuario = NULL;
}

Sesion* Sesion::getInstancia() {
    if (instancia == NULL) {
        instancia = new Sesion();
    }
    return instancia;
}

void Sesion::setUsuario(Usuario *usuario) {
    this->usuario = usuario;
}

Usuario* Sesion::getUsuario() {
    return usuario;
}


Sesion::~Sesion() {}

