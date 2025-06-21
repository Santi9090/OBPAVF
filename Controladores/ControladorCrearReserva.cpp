#ifndef CONTROLADORCREARRESERVA_CPP
#define CONTROLADORCREARRESERVA_CPP

#include "ControladorCrearReserva.h"
#include "../Manejadores/ManejadorCine.h"
#include "../Manejadores/ManejadorPelicula.h"
#include "../Manejadores/ManejadorFuncion.h"
#include "../Clases/Reserva.h"
#include "../DataTypes/DtReserva.h"
#include "../DataTypes/DtDebito.h"
#include "../DataTypes/DtCredito.h"
#include "../Clases/Reserva.h"
#include "../Clases/Debito.h"
#include "../Clases/Credito.h"
#include "../Clases/Sala.h"
#include "../Clases/Funcion.h"
#include "../Clases/Pelicula.h"

using namespace std;

void ControladorCrearReserva::CrearReserva(int idfuncion, string pelicula, DtReserva dtReserva)
{
    ManejadorFuncion *mF = ManejadorFuncion::getInstancia();
    Funcion *funcion = mF->buscarFuncion(idfuncion);

    try
    {
        DtDebito &dtDebito = dynamic_cast<DtDebito &>(dtReserva);
        Debito *debito = new Debito(dtDebito.getCosto(), dtDebito.getCantEntradas(), dtDebito.getBanco(), GenerarIdReserva(idfuncion));

        funcion->agregarReserva(debito);
    }
    catch (bad_cast)
    {
        try
        {
            DtCredito &dtCredito = dynamic_cast<DtCredito&>(dtReserva);
            Credito *credito = new Credito(dtCredito.getCosto(), dtCredito.getCantEntradas(), 0.0, dtCredito.getFinanciera(), GenerarIdReserva(idfuncion));
            funcion->agregarReserva(credito);
        }
        catch (bad_cast)
        {
        }
    }
}

int ControladorCrearReserva::GenerarIdReserva(int idfuncion)
{
    int contador = 0;
    ManejadorFuncion *mF = ManejadorFuncion::getInstancia();
    Funcion *funcion = mF->buscarFuncion(idfuncion);
    list<Reserva *> reservas = funcion->listarReservas();
    for (list<Reserva *>::iterator it = reservas.begin(); it != reservas.end(); ++it)
    {
        contador++;
    }
    return contador + 1;
}

#endif
