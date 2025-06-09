#ifndef CONTROLADORSESION_H
#define CONTROLADORSESION_H
#include <string>
#include "Interfaces/IControladorSesion.h"
#include "Manejadores/ManejadorUsuario.h"

using namespace std;
class ControladorSesion: public IControladorSesion {
public:
    
    void iniciarSesion(string nickname, string pass) override;
    void cerrarSesion() override;
    void registrarUsuario(string nickname, string pass, string urlFoto) override;
};
#endif