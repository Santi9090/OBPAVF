#ifndef COMENTARIO_H
#define COMENTARIO_H
#include <string>
using namespace std;

class Comentario {
private:
    string texto;
public:
    Comentario(string texto);
    string getTexto();
    void setTexto(string texto);
    ~Comentario();
};

#endif
