#ifndef COMENTARIO_H
#define COMENTARIO_H
#include <string>
#include "Usuario.h"
using namespace std;

class Comentario {
private:
    string texto;
    Comentario * comentario ;
    Usuario * usuario;
    int idComentario;
public:
    Comentario(string texto, Comentario * comentario, Usuario * usuario, int idComentario);
    string getTexto();
    void setTexto(string texto);
    Comentario * getComentario();
    void setComentario(Comentario * comentario);
    void setUsuario(Usuario * usuario);
    Usuario * getUsuario();
    int getIdComentario();
    void setIdComentario(int idComentario);
    void agregarComentario(Comentario *comentario);
    Comentario *getComentario(int idComentario);
    ~Comentario();
};

#endif
