#include "ControladorVerReservaPelicula.h"
#include "../Manejadores/ManejadorCine.h"

using namespace std;

ControladorVerReservaPelicula::ControladorVerReservaPelicula() {}

void ControladorVerReservaPelicula::VerReservaDePelicula(string titulo) {
    ManejadorCine* manejadorCine = ManejadorCine::getInstancia();
    // Lógica para ver la reserva de la película
}
