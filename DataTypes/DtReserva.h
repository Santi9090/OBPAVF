#ifndef DTRESERVA_H
#define DTRESERVA_H

#include <string>
using namespace std;

class DtReserva
{
private:
    float costo;
    int cantEntradas;

public:
    DtReserva(float costo, int cantEntradas);
    float getCosto();
    int getCantEntradas();
};

#endif
