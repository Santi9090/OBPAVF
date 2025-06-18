#include <iostream>
#include "../Controladores/ControladorAltaFuncion.h"
#include "../Manejadores/ManejadorCine.h"
#include "../Manejadores/ManejadorFuncion.h"
#include "../Clases/Sala.h"
#include "../Clases/Funcion.h"
using namespace std;

ControladorAltaFuncion::ControladorAltaFuncion() {}

void ControladorAltaFuncion::AltaFuncion(int idCine, int idSala, DtFecha fecha, DtHorario horario) {
    ManejadorCine *mC = ManejadorCine::getInstancia();
    ManejadorFuncion *mF = ManejadorFuncion::getInstancia();

    if (!mC->existeCine(idCine)) {
        cout << "El cine no existe." << endl;
        return;
    }

    Cine *cine = mC->buscarCine(idCine);
    if (!cine->existeSala(idSala)) {
        cout << "La sala no existe." << endl;
        return;
    }

    Sala *sala = cine->buscarSala(idSala);
    int idFuncion = mF->generarIdFuncion();
    Funcion *funcion = new Funcion(idFuncion, fecha, horario);
    
    sala->agregarFuncion(funcion);
    mF->agregarFuncion(funcion);

    cout << "Función registrada con éxito." << endl;

}


