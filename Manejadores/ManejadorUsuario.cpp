#include "ManejadorUsuario.h"
#include <list>
ManejadorUsuario* ManejadorUsuario::instancia = NULL;
ManejadorUsuario* ManejadorUsuario::getInstancia() {
    if (instancia == NULL)
        instancia = new ManejadorUsuario();
    return instancia;
}

void ManejadorUsuario::agregarUsuario(Usuario *usuario) {
    usuarios.insert(std::pair<string,Usuario*>(usuario->getNickname(),usuario));
}

Usuario* ManejadorUsuario::buscarUsuario(string nickname) {
    map<string,Usuario*>::iterator it = this->usuarios.find(nickname);
    return it->second;
}

bool ManejadorUsuario::existeUsuario(string nickname) {
    map<string,Usuario*>::iterator it = this->usuarios.find(nickname);
    return (it != this->usuarios.end());
}

void ManejadorUsuario::eliminarUsuario(string nickname) {
   map<string,Usuario*>::iterator it = this->usuarios.find(nickname);
   this->usuarios.erase(it);
}

list<Usuario*> ManejadorUsuario::getUsuarios() {
   list<Usuario*> lstUsuarios;
    for (map<string,Usuario*>::iterator it=this->usuarios.begin(); it!=usuarios.end(); ++it)
        lstUsuarios.push_back(it->second);
    return lstUsuarios;
}

ManejadorUsuario::ManejadorUsuario() {}