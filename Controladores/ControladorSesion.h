#ifndef CONTROLADORSESION_H
#define CONTROLADORSESION_H
#include <string>
#include "../Interfaces/IControladorSesion.h"
using namespace std;
class ControladorSesion: public IControladorSesion {
public:
    ControladorSesion();
    virtual void iniciarSesion(string nickname, string pass) ;
    virtual void cerrarSesion();
    virtual void registrarUsuario(string nickname, string pass, string urlFoto) ;
    virtual ~ControladorSesion();

};
#endif