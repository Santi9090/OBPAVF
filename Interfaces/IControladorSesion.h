#ifndef ICONTROLADORSESION_H
#define ICONTROLADORSESION_H

#include <string>
using namespace std;

class IControladorSesion {
public:
    virtual bool iniciarSesion(string nick, string pass) = 0;
};

#endif
