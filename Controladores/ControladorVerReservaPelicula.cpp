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
        if (funcion->getPelicula()->getTitulo() == titulo)
        {
            cout << "ID de Función: " << funcion->getIdFuncion() << endl;
            cout << "Fecha: " << funcion->getFecha().getDia();
            cout << funcion->getFecha().getMes() << "/";
            cout << funcion->getFecha().getAnio();
            cout << " Horario: " << funcion->getHorario().getHoraComienzo() << ":";
            cout << funcion->getHorario().getHoraFin() << endl;
            cout << "Película: " << funcion->getPelicula()->getTitulo() << endl;

            list<Reserva *> reservas = funcion->listarReservas();

            cout << "Tamaño de reservas " << reservas.size() << endl;
            for (auto &reserva : reservas)
            {
                try
                {
                    Debito &debito = dynamic_cast<Debito &>(*reserva);
                    cout << "___________RESERVA___________" << endl;
                    cout << "Forma de pago : Debito" << endl;
                    cout << "Reserva ID: " << debito.getIdReserva() << endl;
                    cout << " Costo: " << debito.getCosto() << endl;
                    cout << "Cantidad de Entradas: " << debito.getCantEntradas() << endl;
                }
                catch (bad_cast &)
                {
                    try
                    {
                        Credito &credito = dynamic_cast<Credito &>(*reserva);
                        cout << "___________RESERVA___________" << endl;
                        cout << "Forma de pago : Credito" << endl;
                        cout << "Reserva ID: " << credito.getIdReserva() << endl;
                        cout << " Costo: " << credito.getCosto() << endl;
                        cout << "Cantidad de Entradas: " << credito.getCantEntradas() << endl;
                    }
                    catch (bad_cast &)
                    {
                        cout << "No hay reservas" << endl;
                    }
                }
            }
        }
    }
}
