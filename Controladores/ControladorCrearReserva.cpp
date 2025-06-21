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
using namespace std;

void ControladorCrearReserva::CrearReserva(int idfuncion, string pelicula, DtReserva dtReserva)
{
    ManejadorFuncion *mF = ManejadorFuncion::getInstancia();
    Funcion *funcion = mF->buscarFuncion(idfuncion);
    Pelicula *pelicula = funcion->getPelicula();
    try
    {
        DtDebito &dtDebito = dynamic_cast<DtDebito &>(dtReserva);
        Debito *debito = new Debito(dtDebito.getCosto(), dtDebito.getCantEntradas(), dtDebito.getBanco());

        funcion->agregarReserva(debito);
    }
    catch (bad_cast)
    {
        try
        {
            DtCredito &dtCredito = dynamic_cast<DtCredito&>(dtReserva);
            Credito *credito = new Credito(dtCredito.getCosto(), dtCredito.getCantEntradas(), 0.0, dtCredito.getFinanciera());
            funcion->agregarReserva(credito);
        }
        catch (bad_cast)
        {
        }
    }
}
#endif
