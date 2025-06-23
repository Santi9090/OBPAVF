#include "Funcion.h"
#include "Reserva.h"
#include "Debito.h"
#include "Credito.h"
#

Funcion::Funcion(int idFuncion, DtFecha fecha, DtHorario horario, Pelicula *pelicula)
{
    this->idFuncion = idFuncion;
    this->fecha = fecha;
    this->horario = horario;
    this->pelicula = pelicula;
    this->reservas = map<int, Reserva *>();
}

int Funcion::getIdFuncion()
{
    return idFuncion;
}

DtFecha Funcion::getFecha()
{
    return fecha;
}

DtHorario Funcion::getHorario()
{
    return horario;
}
Pelicula *Funcion::getPelicula()
{
    return pelicula;
}

void Funcion::setIdFuncion(int idFuncion)
{
    this->idFuncion = idFuncion;
}

void Funcion::setFecha(DtFecha fecha)
{
    this->fecha = fecha;
}

void Funcion::setHorario(DtHorario horario)
{
    this->horario = horario;
}
void Funcion::setPelicula(Pelicula *pelicula)
{
    this->pelicula = pelicula;
}

void Funcion::agregarReserva(Reserva *reserva)
{
    try
    {
        Debito &debito = dynamic_cast<Debito &>(*reserva);
        Debito *auxdebito = new Debito(debito.getCosto(), debito.getCantEntradas(), debito.getIdReserva(), debito.getBanco());
        this->reservas.insert(std::pair<int, Reserva *>(auxdebito->getIdReserva(), auxdebito));
        cout << "Id de reserva: " << auxdebito->getIdReserva() << endl;
        cout << "Reserva agregada exitosamente(Debito)" << endl;
    }
    catch (bad_cast)
    {
        try
        {
            Credito &credito = dynamic_cast<Credito &>(*reserva);
            Credito *auxcredito = new Credito(credito.getCosto(), credito.getCantEntradas(), credito.getIdReserva(), credito.getDescuento(), credito.getFinanciera());
            this->reservas.insert(std::pair<int, Reserva *>(auxcredito->getIdReserva(), auxcredito));
            cout << "Id de reserva: " << auxcredito->getIdReserva() << endl;
            cout << "Reserva agregada exitosamente(Credito)" << endl;
        }
        catch (bad_cast)
        {
            cout << "No se pudo agregar la reserva" << endl;
        }
    }
}

list<Reserva *> Funcion::listarReservas()
{
    list<Reserva *> lstReservas;
    for (map<int, Reserva *>::iterator it = this->reservas.begin(); it != this->reservas.end(); ++it)
        lstReservas.push_back(it->second);
    return lstReservas;
}
void Funcion::eliminarReserva(int idReserva)
{
    auto it = reservas.find(idReserva);
    if (it != reservas.end()) {
        delete it->second; // Libera la memoria de la reserva
        reservas.erase(it);
    }
    else
    {
        cout << "No se encontró la reserva con ID: " << idReserva << endl;
    }
}

Funcion::~Funcion() {}
