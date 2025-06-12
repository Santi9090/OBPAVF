#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <map>
#include "Reserva.h"
using namespace std;

class Usuario
{
private:
    string nickname;
    string contrasena;
    string urlFoto;
    map<string, Reserva*> reservas;
public:
    Usuario(string nickname, string contrasena, string urlFoto);
    string getNickname();
    string getContrasena();
    string getUrlFoto();
    void setNickname(string nickname);
    void setContrasena(string contrasena);
    void setUrlFoto(string urlFoto);


    void agregarReserva(Reserva* reserva);
    Reserva* buscarReserva(string titulo);
    bool existeReserva(string titulo);

    ~Usuario();
};

#endif
