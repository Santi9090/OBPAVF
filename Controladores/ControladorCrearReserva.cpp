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

void ControladorCrearReserva::CrearReserva(int idCine,int idSala, int idfuncion, string pelicula, DtReserva dtReserva)
{
    ManejadorFuncion *mF = ManejadorFuncion::getInstancia();
    ManejadorCine *mC = ManejadorCine::getInstancia();
    Funcion *funcion = mF->buscarFuncion(idfuncion);
    Cine *cine = mC->buscarCine(idCine);
    Sala *sala = cine->buscarSala(idSala);
    sala->setCapacidad(sala->getCapacidad() - dtReserva.getCantEntradas());


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
            DtCredito &dtCredito = dynamic_cast<DtCredito &>(dtReserva);
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
    if(contador == 0)
    {
        return contador;
    }else
    return contador + 1;
}

void ControladorCrearReserva::ListarFuncionesPeli(string pelicula, int idCine, DtFecha fecha, DtHorario hora)
{

    struct RelojSistema
    {
        DtFecha fecha;
        DtHorario hora;
    };
    RelojSistema *reloj = new (RelojSistema);
    reloj->fecha = fecha;
    reloj->hora = hora;
    ManejadorCine *mC = ManejadorCine::getInstancia();
    ManejadorPelicula *mP = ManejadorPelicula::getInstancia();
    ManejadorFuncion *mF = ManejadorFuncion::getInstancia();

    if (!mC->existeCine(idCine))
    {
        cout << "El cine no existe." << endl;
        return;
    }

    Cine *cine = mC->buscarCine(idCine);
    if (!mP->existePelicula(pelicula))
    {
        cout << "La película no existe." << endl;
        return;
    }

    Pelicula *peli = mP->buscarPelicula(pelicula);
    list<Funcion *> funciones = mF->getFunciones();
    list<Sala *> salas = cine->getSalas();
    for (list<Sala *>::iterator it = salas.begin(); it != salas.end(); ++it)
    {
        cout << "1" << endl;
        list<Funcion *> funciones = (*it)->getFunciones();
        for (list<Funcion *>::iterator it2 = funciones.begin(); it2 != funciones.end(); ++it2)
        {
            cout << "2" << endl;
            if (peli->getTitulo() == (*it2)->getPelicula()->getTitulo())
            {
                cout << "3" << endl;

                if (reloj->fecha.getAnio() < (*it2)->getFecha().getAnio())
                {
                    cout << "Asientos Disponibles : " << (*it)->getCapacidad() << endl;
                    cout << "Id de la funcion : " << (*it2)->getIdFuncion() << endl;
                }
                else if (reloj->fecha.getAnio() == (*it2)->getFecha().getAnio())
                {
                    if (reloj->fecha.getMes() < (*it2)->getFecha().getMes())
                    {
                        cout << "Asientos Disponibles : " << (*it)->getCapacidad() << endl;
                        cout << "Id de la funcion : " << (*it2)->getIdFuncion() << endl;
                    }
                    else if (reloj->fecha.getMes() == (*it2)->getFecha().getMes())
                    {
                        if (reloj->fecha.getDia() < (*it2)->getFecha().getDia())
                        {
                            cout << "Asientos Disponibles : " << (*it)->getCapacidad();
                            cout << "Id de la funcion : " << (*it2)->getIdFuncion() << endl;
                        }
                    }
                }
            }
        }
    }
}

#endif
