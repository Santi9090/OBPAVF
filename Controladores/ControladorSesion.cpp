#include "ControladorSesion.h"
#include "../Manejadores/ManejadorUsuario.h"
#include "../Clases/Usuario.h"
#include "../Clases/Sesion.h"
using namespace std;

ControladorSesion::ControladorSesion()
{
}

void ControladorSesion::iniciarSesion(string nickname, string pass)
{
    ManejadorUsuario *mU = ManejadorUsuario::getInstancia();
    if (mU->existeUsuario(nickname))
    {
        Usuario *usuario = mU->buscarUsuario(nickname);
        if (usuario->getContrasena() == pass)
        {
            Sesion *sesion = Sesion::getInstancia();
            sesion->setUsuario(usuario);
            printf("Inicio de sesión exitoso.\n");
        }
        else
        {
            printf("Contraseña incorrecta.\n");
        }
    }
    else
    {
        printf("El usuario no existe.\n");
    }
}

void ControladorSesion::registrarUsuario(string nickname, string pass, string urlFoto)
{
    ManejadorUsuario *mU = ManejadorUsuario::getInstancia();
    if (!mU->existeUsuario(nickname))
    {
        Usuario *usuario = new Usuario(nickname, pass, urlFoto);
        mU->agregarUsuario(usuario);
        printf("Usuario registrado con éxito.\n");
    }
    else
    {
        printf("El usuario ya existe.\n");
    }
}

void ControladorSesion::cerrarSesion()
{
    Sesion *sesion = Sesion::getInstancia();
    sesion->setUsuario(nullptr);
    printf("Sesión cerrada.\n");
}

bool ControladorSesion::existeUsuario(string nickname)
{
    ManejadorUsuario *mU = ManejadorUsuario::getInstancia();
    return mU->existeUsuario(nickname);
}

bool ControladorSesion::existeSesion(){
    Sesion *sesion = Sesion::getInstancia();
    if(sesion->getUsuario() != nullptr)
        return true;
    return false;
}

ControladorSesion::~ControladorSesion()
{
}
