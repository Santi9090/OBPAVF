#include "ControladorVerReservaPelicula.h"
#include "../Manejadores/ManejadorFuncion.h"
#include "../Clases/Funcion.h"
#include "../Clases/Reserva.h"
#include "../Clases/Pelicula.h"
#include "../Clases/Debito.h"
#include "../Clases/Credito.h"

using namespace std;

ControladorVerReservaPelicula::ControladorVerReservaPelicula() {}

void ControladorVerReservaPelicula::VerReservaDePelicula(string titulo)
{
    ManejadorFuncion *mF = ManejadorFuncion::getInstancia();
    list<Funcion *> funciones = mF->getFunciones();

    for (auto &funcion : funciones)
    {
        cout << "[DEBUG] Direccion de funcion: " << funcion << " | ID: " << funcion->getIdFuncion() << endl;
        if (funcion->getPelicula()->getTitulo() == titulo)
        {
            cout << "ID de Función: " << funcion->getIdFuncion() << endl;
            cout << "Fecha: " << funcion->getFecha().getDia() << endl;
            cout << funcion->getFecha().getMes() << endl;
            cout << funcion->getFecha().getAnio() << endl;
            cout << "Horario: " << funcion->getHorario().getHoraComienzo() << endl;
            cout << funcion->getHorario().getHoraFin() << endl;
            cout << "Película: " << funcion->getPelicula()->getTitulo() << endl;

            list<Reserva *> reservas = funcion->listarReservas();
            cout << "[DEBUG] Cantidad de reservas en funcion " << funcion->getIdFuncion() << ": " << reservas.size() << endl;

            for (auto &reserva : reservas)
            {
                cout << "[DEBUG] Direccion de reserva: " << reserva << " | ID: " << reserva->getIdReserva() << endl;
                cout << "Entro al for pa \n";
                try
                {
                    Debito *debito = dynamic_cast<Debito *>(reserva);
                    if (debito)
                    {
                        cout << "Reserva ID: " << reserva->getIdReserva() << endl;
                        cout << " Costo: " << reserva->getCosto() << endl;
                        cout << "Cantidad de Entradas: " << reserva->getCantEntradas() << endl;
                        cout << "Forma de pago : Debito" << endl;
                    }
                }
                catch (bad_cast)
                {
                    try
                    {
                        Credito *credito = dynamic_cast<Credito *>(reserva);
                        if (credito)
                        {
                            cout << "Reserva ID: " << reserva->getIdReserva() << endl;
                            cout << " Costo: " << reserva->getCosto() << endl;
                            cout << "Cantidad de Entradas: " << reserva->getCantEntradas() << endl;
                            cout << "Forma de pago : Credito" << endl;
                        }
                    }
                    catch (bad_cast &e)
                    {
                        cout << e.what() << endl;
                    }
                }
            }
        }
    }
}
