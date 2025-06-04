#include "ControladorSesion.h"
#include "ManejadorCine.h"
#include "Sala.h"
#include "Funcion.h"
using namespace std;

ControladorSesion::ControladorSesion() {}

bool ControladorSesion::iniciarSesion(string nick, string pass) {
    ManejadorCine* manejadorCine = ManejadorCine::getInstancia();
    // Lógica para iniciar sesión
    return true;
}
