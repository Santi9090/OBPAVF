#include "ControladorPelicula.h"
#include "../Clases/Sala.h"
#include "../Clases/Funcion.h"
#include "../Manejadores/ManejadorPelicula.h"
#include <map>
using namespace std;

void ControladorPelicula::RegistrarPelicula(string titulo, string sinopsis, string urlFoto)
{
	ManejadorPelicula* mP = ManejadorPelicula::getInstancia();
	Pelicula* pelicula = new Pelicula(titulo, sinopsis, 0.0f, urlFoto);
	mP->agregarPelicula(pelicula);
}

list<DtPelicula> ControladorPelicula::ListarPeliculas()
{
	ManejadorPelicula* mP = ManejadorPelicula::getInstancia();
	return (mP->listarPeliculas());
}

bool ControladorPelicula::ExistePelicula(string titulo)
{
	ManejadorPelicula* mP = ManejadorPelicula::getInstancia();
	return (mP->existePelicula(titulo));
}


DtPelicula ControladorPelicula::BuscarPelicula(string titulo)
{
	ManejadorPelicula* mP = ManejadorPelicula::getInstancia();
	Pelicula* pelicula = mP->buscarPelicula(titulo);
	if (pelicula != NULL) {
		return DtPelicula(pelicula->getTitulo(), pelicula->getSinopsis(), pelicula->getPuntajePromedio(), pelicula->getPoster());
	}
	throw runtime_error("La película no existe.");
}


