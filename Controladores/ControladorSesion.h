#ifndef CONTROLADORSESION_H
#define CONTROLADORSESION_H
#include <string>
#include "IControladorSesion.h"
using namespace std;
class ControladorSesion: public IControladorSesion {
public:
    ControladorSesion();
    bool iniciarSesion(string nick, string pass);
};
#endif