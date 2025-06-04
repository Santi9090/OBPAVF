#include "ControladorPelicula.h"
#include "ManejadorCine.h"
#include "Sala.h"
#include "Funcion.h"
using namespace std;

ControladorPelicula::ControladorPelicula() {}

void ControladorPelicula::EliminarPelicula(string titulo) {
    ManejadorCine* manejadorCine = ManejadorCine::getInstancia();
    // Lógica para eliminar la película
}
