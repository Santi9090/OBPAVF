#include "Funcion.h"
#include "Reserva.h"
#include "Debito.h"
#include "Credito.h"
#

Funcion::Funcion(int idFuncion, DtFecha fecha, DtHorario horario, Pelicula *pelicula) {
    this->idFuncion = idFuncion;
    this->fecha = fecha;
    this->horario = horario;
    this->pelicula = pelicula;
}

int Funcion::getIdFuncion() {
    return idFuncion;
}

DtFecha Funcion::getFecha() {
    return fecha;
}

DtHorario Funcion::getHorario() {
    return horario;
}
Pelicula * Funcion::getPelicula(){
    return pelicula;
}

void Funcion::setIdFuncion(int idFuncion) {
    this->idFuncion = idFuncion;
}

void Funcion::setFecha(DtFecha fecha) {
    this->fecha = fecha;
}

void Funcion::setHorario(DtHorario horario) {
    this->horario = horario;
}
void Funcion::setPelicula(Pelicula *pelicula) {
    this->pelicula = pelicula;
}

void Funcion::agregarReserva(Reserva *reserva)
{
    try
    {
        Debito *preserva = dynamic_cast<Debito *>(reserva);
        Debito *debito = new Debito(preserva->getCosto(), preserva->getCantEntradas(), preserva->getBanco(),preserva->getIdReserva());
        this->reservas.insert(std::pair<int, Reserva *>(debito->getIdReserva(), debito));
    }
    catch (bad_cast)
    {
        try{
        Credito *preserva = dynamic_cast<Credito *>(reserva);
        Credito *credito = new Credito(preserva->getCosto(), preserva->getCantEntradas(), preserva->getDescuento(), preserva->getFinanciera(),preserva->getIdReserva());
        this->reservas.insert(std::pair<int, Reserva *>(credito->getIdReserva(), credito));
        }
        catch (bad_cast){}
    }
   
}



 list<Reserva*> Funcion::listarReservas(){
    list<Reserva*> lstReservas;
    for (map<int, Reserva*>::iterator it=this->reservas.begin(); it!=this->reservas.end(); ++it)
        lstReservas.push_back(it->second);
    return lstReservas;
 }


Funcion::~Funcion() {}
