#ifndef MANEJADORUSUARIO_H
#define MANEJADORUSUARIO_H

#include <string>
#include <map>
#include "../Clases/Usuario.h"
#include "../Clases/Sesion.h"
#include <list>
using namespace std;
class ManejadorUsuario {
private:
    static ManejadorUsuario* instancia;
    map<string, Usuario*> usuarios;
    ManejadorUsuario();
public:
    static ManejadorUsuario* getInstancia();
    void agregarUsuario(Usuario *);
    Usuario* buscarUsuario(string nickname);
    bool existeUsuario(string nickname);
    void eliminarUsuario(string nickname);
    list<Usuario*> getUsuarios();
    ~ManejadorUsuario();
};

#endif
