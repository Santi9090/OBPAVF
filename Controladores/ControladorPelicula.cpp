#include "ControladorPelicula.h"
#include "../Clases/Sala.h"
#include "../Clases/Funcion.h"
#include "../Manejadores/ManejadorPelicula.h"
#include "../Manejadores/ManejadorCine.h"
#include "../Manejadores/ManejadorFuncion.h"
#include <vector>
#include <map>
#include <set>
using namespace std;

void ControladorPelicula::RegistrarPelicula(string titulo, string sinopsis, string urlFoto)
{
	ManejadorPelicula *mP = ManejadorPelicula::getInstancia();
	Pelicula *pelicula = new Pelicula(titulo, sinopsis, 0.0f, urlFoto);
	mP->agregarPelicula(pelicula);
}

list<DtPelicula> ControladorPelicula::ListarPeliculas()
{
	ManejadorPelicula *mP = ManejadorPelicula::getInstancia();
	return (mP->listarPeliculas());
}

bool ControladorPelicula::ExistePelicula(string titulo)
{
	ManejadorPelicula *mP = ManejadorPelicula::getInstancia();
	return (mP->existePelicula(titulo));
}

DtPelicula ControladorPelicula::BuscarPelicula(string titulo)
{
	ManejadorPelicula *mP = ManejadorPelicula::getInstancia();
	Pelicula *pelicula = mP->buscarPelicula(titulo);
	if (pelicula != NULL)
	{
		return DtPelicula(pelicula->getTitulo(), pelicula->getSinopsis(), pelicula->getPuntajePromedio(), pelicula->getPoster());
	}
	throw runtime_error("La película no existe.");
}

void ControladorPelicula::EliminarPelicula(string titulo)
{
	ManejadorCine *mC = ManejadorCine::getInstancia();
	ManejadorFuncion *mF = ManejadorFuncion::getInstancia();
	list<Funcion *> funciones = mF->getFunciones();
	for (auto &funcion : funciones)
	{
		if (funcion->getPelicula()->getTitulo() == titulo)
		{
			for (auto &reserva : funcion->listarReservas())
			{
				funcion->eliminarReserva(reserva->getIdReserva());
			}
			mF->eliminarFuncion(funcion->getIdFuncion());
		}
	}
	for (auto &cine : mC->getCines())
	{
		if (cine->existePelicula(titulo))
		{
			cine->eliminarPelicula(cine->buscarPelicula(titulo));
		}
	}




	ManejadorPelicula *mP = ManejadorPelicula::getInstancia();
	if (mP->existePelicula(titulo))
	{
		mP->eliminarPelicula(titulo);
	}
	else
	{
		throw runtime_error("La película no existe.");
	}

}