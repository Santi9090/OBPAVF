#include "Usuario.h"
#include "Debito.h"
#include "Credito.h"
#include "../Manejadores/ManejadorUsuario.h"
#include <list>

using namespace std;
Usuario::Usuario(string nickname, string contrasena, string urlFoto)
    : nickname(nickname), contrasena(contrasena), urlFoto(urlFoto)
{
    this->nickname = nickname;
    this->contrasena = contrasena;
    this->urlFoto = urlFoto;
}
string Usuario::getNickname()
{
    return nickname;
}
string Usuario::getContrasena()
{
    return contrasena;
}
string Usuario::getUrlFoto()
{
    return urlFoto;
}
void Usuario::setNickname(string nickname)
{
    this->nickname = nickname;
}
void Usuario::setContrasena(string contrasena)
{
    this->contrasena = contrasena;
}
void Usuario::setUrlFoto(string urlFoto)
{
    this->urlFoto = urlFoto;
}


Usuario::~Usuario() {}
