#include <iostream>
#include "ControladorAltaFuncion.h"
#include "ManejadorCine.h"
#include "Sala.h"
#include "Funcion.h"
using namespace std;

ControladorAltaFuncion::ControladorAltaFuncion() {}

void ControladorAltaFuncion::AltaFuncion(int idCine, int idSala, int idFuncion, DtFecha fecha, DtHorario horario) {
    ManejadorCine* manejadorCine = ManejadorCine::getInstancia();
    Cine* cine = manejadorCine->buscarCine(idCine);
    if (!cine) {
        cout << "No se encontró el cine con id: " << idCine << endl;
        return;
    }
    Sala* sala = cine->buscarSala(idSala);
    if (!sala) {
        cout << "No se encontró la sala con id: " << idSala << endl;
        return;
    }
    Funcion* funcion = new Funcion(idFuncion, fecha, horario);
    sala->agregarFuncion(funcion);
    cout << "Función agregada correctamente a la sala " << idSala << " del cine " << idCine << endl;
}

void ControladorAltaFuncion::obtenerFunciones() {
    ManejadorCine* manejadorCine = ManejadorCine::getInstancia();
    list<Cine*> cines = manejadorCine->getCines();
    for (Cine* cine : cines) {
        cout << "Cine ID: " << cine->getIdCine() << endl;
        list<Sala*> salas = cine->getSalas();
        for (Sala* sala : salas) {
            cout << "  Sala ID: " << sala->getId() << endl;
            list<Funcion*> funciones = sala->getFunciones();
            for (Funcion* funcion : funciones) {
                cout << "    Funcion ID: " << funcion->getIdFuncion() << endl;
            }
        }
    }
}

