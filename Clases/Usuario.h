#ifndef USUARIO_H
#define USUARIO_H
#include <string>
using namespace std;

class Usuario {
private:
    string nickname;
    string contrasena;
    string urlFoto;
public:
    Usuario(string nickname, string contrasena, string urlFoto);
    string getNickname();
    string getContrasena();
    string getUrlFoto();
    void setNickname(string nickname);
    void setContrasena(string contrasena);
    void setUrlFoto(string urlFoto);
    ~Usuario();
};

#endif
