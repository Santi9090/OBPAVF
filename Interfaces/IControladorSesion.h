#ifndef ICONTROLADORSESION_H
#define ICONTROLADORSESION_H
#include <string>
using namespace std;

class IControladorSesion
{
public:
    virtual void iniciarSesion(string nickname, string pass) = 0;
    virtual void registrarUsuario(string nickname, string pass, string urlFoto) = 0;
    virtual void cerrarSesion() = 0;
};

#endif
