#ifndef FUNCION_H
#define FUNCION_H
#include "../DataTypes/DtFecha.h"
#include "../DataTypes/DtHorario.h"
#include "Reserva.h"
#include <iostream>
#include <map>
#include <list>
using namespace std;

// Forward declaration
class Pelicula;

class Funcion
{
private:
    int idFuncion;
    DtFecha fecha;
    DtHorario horario;
    Pelicula *pelicula;
    map<int, Reserva *> reservas;

public:
    Funcion(int idFuncion, DtFecha fecha, DtHorario horario, Pelicula *pelicula);
    int getIdFuncion();
    DtFecha getFecha();
    DtHorario getHorario();
    Pelicula *getPelicula();
    void setIdFuncion(int idFuncion);
    void setFecha(DtFecha fecha);
    void setHorario(DtHorario horario);
    void setPelicula(Pelicula *pelicula);
    void agregarReserva(Reserva *reserva);
    list<Reserva *> listarReservas();

    ~Funcion();
};

#endif