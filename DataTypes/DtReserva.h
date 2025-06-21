#ifndef DTRESERVA_H
#define DTRESERVA_H

#include <string>
using namespace std;

class DtReserva
{
private:
    int idReserva;
    float costo;
    int cantEntradas;

public:
    DtReserva(float costo, int cantEntradas,int idReserva);
    float getCosto();
    int getCantEntradas();
    int getIdReserva();
    virtual ~DtReserva();  
};

#endif
