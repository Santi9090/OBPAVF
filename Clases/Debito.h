#ifndef DEBITO_H
#define DEBITO_H
#include "Reserva.h"
#include <string>
using namespace std;

class Debito : public Reserva {
private:
    string banco;
public:
    Debito(float costo, int cantEntradas, string banco);
    string getBanco();
    void setBanco(string banco);
    ~Debito();
};

#endif
