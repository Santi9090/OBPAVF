#ifndef RESERVA_H
#define RESERVA_H

class Reserva
{
protected:
    float costo;
    int cantEntradas;

public:
    Reserva(float costo, int cantEntradas);
    float getCosto();
    int getCantEntradas();
    void setCosto(float costo);
    void setCantEntradas(int cantEntradas);
    virtual ~Reserva();
};

#endif
