#include "ControladorSesion.h"
using namespace std;

ControladorSesion::ControladorSesion()
{
}

void ControladorSesion::iniciarSesion(string nickname, string pass)
{
    ManejadorUsuario *mU = ManejadorUsuario::getInstancia();
    if(mU->existeUsuario(nickname))
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

void ControladorSesion::cerrarSesion()
{
    Sesion *sesion = Sesion::getInstancia();
    if (sesion->getUsuario() != nullptr)
    {
        sesion->setUsuario(nullptr);
        printf("Sesión cerrada exitosamente.\n");
    }
}


void ControladorSesion::registrarUsuario(string nickname, string pass, string urlFoto)
{
    ManejadorUsuario *mU = ManejadorUsuario::getInstancia();
    Usuario *usuario;
    if (!mU->existeUsuario(nickname))
    {
        usuario = new Usuario(nickname, pass, urlFoto);
        mU->agregarUsuario(usuario);
    }
    else
    {
        printf("El usuario ya existe.\n");
    }
}

ControladorSesion::~ControladorSesion()
{
}