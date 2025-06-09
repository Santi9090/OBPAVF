#ifndef CONTROLADORSESION_H
#define CONTROLADORSESION_H
#include <string>
#include "Interfaces/IControladorSesion.h"
#include "Manejadores/ManejadorUsuario.h"

using namespace std;
class ControladorSesion: public IControladorSesion {
public:
    ControladorSesion();
    void iniciarSesion(string nickname, string pass);
    void cerrarSesion();
    void registarUsuario(string nickname, string pass,string urlFoto);
    ~ControladorSesion();

};
#endif