#ifndef CREDITO_H
#define CREDITO_H
#include "Reserva.h"
#include <string>
using namespace std;

class Credito : public Reserva
{
private:
    float descuento;
    string financiera;

public:
    Credito(float costo, int cantEntradas, float descuento, string financiera,int idReserva);
    float getDescuento();
    string getFinanciera();
    void setDescuento(float descuento);
    void setFinanciera(string financiera);
    ~Credito();
};

#endif
