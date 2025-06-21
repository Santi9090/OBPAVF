#ifndef RESERVA_H
#define RESERVA_H

class Reserva
{
protected:
    int idReserva;
    float costo;
    int cantEntradas;

public:
    Reserva(int idReserva, float costo, int cantEntradas);
    float getCosto();
    int getCantEntradas();
    void setCosto(float costo);
    void setCantEntradas(int cantEntradas);
    int getIdReserva();
    virtual ~Reserva();
};

#endif
