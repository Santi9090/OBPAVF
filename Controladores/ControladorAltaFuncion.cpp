#include "../Controladores/ControladorAltaFuncion.h"
#include "../Manejadores/ManejadorCine.h"
#include "../Manejadores/ManejadorFuncion.h"
#include "../Manejadores/ManejadorPelicula.h"
#include "../Clases/Sala.h"
#include "../Clases/Funcion.h"
using namespace std;

ControladorAltaFuncion::ControladorAltaFuncion() {}

void ControladorAltaFuncion::AltaFuncion(int idCine, int idSala, DtFecha fecha, DtHorario horario, string titulo)
{

    ManejadorCine *mC = ManejadorCine::getInstancia();
    ManejadorFuncion *mF = ManejadorFuncion::getInstancia();
    ManejadorPelicula *mP = ManejadorPelicula::getInstancia();
    if (!mC->existeCine(idCine))
    {
        cout << "El cine no existe." << endl;
        return;
    }
    Cine *cine = mC->buscarCine(idCine);
    if (!cine->existeSala(idSala))
    {
        cout << "La sala no existe." << endl;
        return;
    }
    if (!mP->existePelicula(titulo))
    {
        cout << "La película no existe." << endl;
        return;
    }

    Sala *sala = cine->buscarSala(idSala);

    int idFuncion = mF->generarIdFuncion();

    Pelicula *peli = mP->buscarPelicula(titulo);

    Funcion *funcion = new Funcion(idFuncion, fecha, horario, peli);

    sala->agregarFuncion(funcion);

    mF->agregarFuncion(funcion);

    cout << "Función registrada con éxito." << endl;
}

list<DtFuncion> ControladorAltaFuncion::listarFunciones()
{
    ManejadorFuncion *mF = ManejadorFuncion::getInstancia();
    list<DtFuncion> listaFunciones;
    for (auto &funcion : mF->getFunciones())
    {
        int id = funcion->getIdFuncion();
        DtFecha fecha = funcion->getFecha();
        DtHorario horario = funcion->getHorario();
        DtPelicula pelicula = DtPelicula(funcion->getPelicula()->getTitulo(), funcion->getPelicula()->getSinopsis(), funcion->getPelicula()->getPuntajePromedio(), funcion->getPelicula()->getPoster());
        DtFuncion dtFuncion(id, fecha, horario, pelicula);
        listaFunciones.push_back(dtFuncion);
    }
    return listaFunciones;
}
