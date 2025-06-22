#ifndef ICONTROLADORCREARRESERVA_H
#define ICONTROLADORCREARRESERVA_H

#include <string>
#include "../DataTypes/DtReserva.h"
#include "../DataTypes/DtFecha.h"
#include "../DataTypes/DtHorario.h" 
using namespace std;

class IControladorCrearReserva {
public:
    
    virtual void CrearReserva(int idCine,int idSala, int idfuncion,string pelicula ,DtReserva &Reserva) = 0;
    virtual int GenerarIdReserva(int idfuncion) = 0;
    virtual void ListarFuncionesPeli(string pelicula, int idCine, DtFecha fecha, DtHorario hora) = 0;
};

#endif
