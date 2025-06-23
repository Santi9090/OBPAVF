#ifndef PUNTAJE_H
#define PUNTAJE_H
#include "Usuario.h"
class Puntaje {
private:
int idPuntaje;
    int valor;
    Usuario *usuario;
public:
    Puntaje(int valor, Usuario *usuario, int idPuntaje);
    int getValor();
    void setValor(int valor);
    void setUsuario(Usuario *usuario);
    Usuario *getUsuario();
    void setIdPuntaje(int idPuntaje);
    int getIdPuntaje();
    ~Puntaje();
};

#endif
