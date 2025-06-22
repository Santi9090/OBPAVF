#ifndef CONTROLADORCREARRESERVA_H
#define CONTROLADORCREARRESERVA_H

#include <string>
#include "../Interfaces/IControladorCrearReserva.h"
#include "../Clases/Pelicula.h"
#include "../Clases/Cine.h"
#include "../Clases/Funcion.h"
#include "../DataTypes/DtReserva.h"
#include <map>
using namespace std;

class ControladorCrearReserva : public IControladorCrearReserva
{
public:

    void CrearReserva(int idCine,int idSala,int idfuncion,string pelicula ,DtReserva Reserva);
    //void VerReservaDePelicula(string titulo, string nombreCliente, int cantidadEntradas);
    int GenerarIdReserva(int idfuncion);
    void ListarFuncionesPeli(string pelicula, int idCine, DtFecha fecha, DtHorario hora);
};

#endif
