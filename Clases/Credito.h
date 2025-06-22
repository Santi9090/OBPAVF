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
    Credito(float costo, int cantEntradas,int idReserva, float descuento, string financiera);
    float getDescuento();
    string getFinanciera();
    void setDescuento(float descuento);
    void setFinanciera(string financiera);
    ~Credito();
};

#endif
