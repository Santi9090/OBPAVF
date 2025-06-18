using namespace std;
#include <iostream>
#include "Fabrica.h"
#include "DataTypes/DtCine.h"
#include "DataTypes/DtHorario.h"
#include "DataTypes/DtFecha.h"
Fabrica *fabrica;
IControladorSesion *iconSesion;
IControladorPelicula *iconPelicula;
IControladorAltaCine *iconCine;
IControladorAltaFuncion *iconFuncion;

void menu()
{
    cout << "_____________________________________________" << endl;
    cout << "_____________SISTEMA DEL MOMO_____________" << endl;
    cout << "1- iniciarSesion: " << endl;
    cout << "2- RegistrarUsuario: " << endl;
    cout << "_____________________________________________" << endl;
}

void AltaUsuario()
{
    string nick, pass, urlFoto;
    cout << "_____________________________________________" << endl;
    cout << "___________REGISTRAR USUARIO____________" << endl;
    cout << "Ingrese su nick: ";
    cin >> nick;
    cout << "Ingrese su contraseña: ";
    cin >> pass;
    cout << "Ingrese la URL de su foto: ";
    cin >> urlFoto;
    iconSesion->registrarUsuario(nick, pass, urlFoto);
    cout << "_____________________________________________" << endl;
}
void iniciarSesion()
{
    int opcion2;
    string nick, pass;
    cout << "_____________________________________________" << endl;
    cout << "___________INICIAR SESION____________" << endl;
    cout << "Ingrese su nick: ";
    cin >> nick;
    cout << "Ingrese su contraseña: ";
    cin >> pass;
    iconSesion->iniciarSesion(nick, pass);
    cout << "_____________________________________________" << endl;
    while (iconSesion->existeUsuario(nick) and !iconSesion->existeSesion())
    {
        cout << "1-Reingresar Contraseña" << endl;
        cout << "2-Cancelar Incio de sesion " << endl;
        cin >> opcion2;
        switch (opcion2)
        {
        case 1:
            cout << "Ingrese su contraseña: ";
            cin >> pass;
            iconSesion->iniciarSesion(nick, pass);
            break;

        case 2:
            iconSesion->cerrarSesion();
            break;
        default:
            cout << "Opción no válida. Intente de nuevo." << endl;
            break;
        }
    }
}
void registrarPelicula()
{
    string titulo, sinopsis, urlFoto;
    int continua = 1;
    do
    {
        cout << "_____________________________________________" << endl;
        cout << "___________REGISTRAR PELICULA____________" << endl;
        cout << "Ingrese el título de la película: ";
        cin >> titulo;
        cout << "Ingrese la sinopsis de la película: ";
        cin >> sinopsis;
        cout << "Ingrese la URL de la foto de la película: ";
        cin >> urlFoto;
        if (!iconPelicula->ExistePelicula(titulo))
        {
            iconPelicula->RegistrarPelicula(titulo, sinopsis, urlFoto);
            cout << "Película registrada exitosamente." << endl;
        }
        else
        {
            cout << "La película ya existe." << endl;
        }
        cout << "_____________________________________________" << endl;

        cout << "¿Desea registrar otra película? (1-Sí, 0-No): ";
        cin >> continua;

    } while (continua != 0);
}

void altaCine()
{
    int opcion, numero;
    string calle;
    do
    {
        cout << "_____________________________________________" << endl;
        cout << "___________REGISTRAR CINE____________" << endl;
        cout << "Ingrese la dirección del cine: ";
        cin >> calle;
        cout << "Ingrese el número de la dirección: ";
        cin >> numero;
        DtDireccion direccion(calle, numero);
        cout << "_____________________________________________" << endl;
        map<int, DtSala> dtSalas;
        int idSala = 1;
        int capacidad;
        do
        {
            cout << "Ingrese la capacidad de la sala (0 para terminar): ";
            cin >> capacidad;
            if (capacidad > 0)
            {
                DtSala dtSala(idSala, capacidad);
                dtSalas.insert(pair<int, DtSala>(idSala, dtSala));
                idSala++;
            }
        } while (capacidad > 0);
        cout << "_____________________________________________" << endl;
        cout << "Desea registrar el cine (1-Sí, 0-No): ";
        cin >> opcion;
        if (opcion == 1)
        {
            iconCine->AltaCine(direccion, dtSalas);
            cout << "Cine registrado exitosamente." << endl;
        }
        cout << "_____________________________________________" << endl;
        cout << "¿Desea registrar otro cine? (1-Sí, 0-No): ";
        cin >> opcion;
    } while (opcion != 0);
}
void listarCines()
{
    cout << "_____________________________________________" << endl;
    cout << "___________LISTA DE CINES____________" << endl;
    list<DtCine> cines = iconCine->getCines();
    for (list<DtCine>::iterator it = cines.begin(); it != cines.end(); ++it)
    {
        cout << "Cine: " << it->getDireccion().getCalle() << endl;
        cout << "Número: " << it->getDireccion().getNumero() << endl;
        cout << "ID: " << it->getIdCine() << endl;
    }
}
void listarPeliculas()
{
    cout << "_____________________________________________" << endl;
    cout << "___________LISTA DE PELICULAS____________" << endl;
    list<DtPelicula> peliculas = iconPelicula->ListarPeliculas();
    for (list<DtPelicula>::iterator it = peliculas.begin(); it != peliculas.end(); ++it)
    {
        cout << "Título: " << it->getTitulo() << endl;
        cout << "Sinopsis: " << it->getSinopsis() << endl;
    }
}

void AltaFuncion()
{
    string titulo;
    listarPeliculas();
    cout << "_____________________________________________" << endl;
    cout << "___________Seleccione una Película____________" << endl;
    cout << "Ingrese el título de la película: ";
    cin >> titulo;
    if (!iconPelicula->ExistePelicula(titulo))
    {
        cout << "La película no existe." << endl;
    }
    else
    {
        listarCines();
        cout << "_____________________________________________" << endl;
        cout << "___________Seleccione un Cine____________" << endl;
        int idCine;
        cout << "Ingrese el ID del cine: ";
        cin >> idCine;
        if (!iconCine->existeCine(idCine))
        {
            cout << "El cine no existe." << endl;
        }
        else
        {
           mostrarSalas(idCine);
           cout << "_____________________________________________" << endl;
           cout << "___________Seleccione una Sala____________" << endl;
           int idSala;
           cout << "Ingrese el ID de la sala: ";
           cin >> idSala;

           DtHorario horario;
           DtFecha fecha;
           int anio,mes,dia;
           string horaComienzo, horaFin;
            
           cout << "Ingrese la fecha de la función (DD MM AAAA): ";
           cin >> dia >> mes >> anio;
           fecha = DtFecha(dia, mes, anio);
           cout << "Ingrese la hora de la función (HH MM): ";
           cin >> horaComienzo >> horaFin;
           horario = DtHorario(horaComienzo, horaFin);

           iconFuncion->AltaFuncion(idCine, idSala, fecha, horario);

        }return;
    }
}
void mostrarSalas(int idCine)
{
    cout << "_____________________________________________" << endl;
    cout << "___________LISTA DE SALAS____________" << endl;
    list<DtSala> salas = iconCine->listarSalas(idCine);
    for (auto &sala : salas)
    {
        cout << "ID de Sala: " << sala.getIdSala() << endl;
        cout << "Capacidad: " << sala.getCapacidad() << endl;
    }
}

void menu2()
{
    cout << "_____________________________________________" << endl;
    cout << "_____________MENU ___________________________" << endl;
    cout << "1- Registrar Película" << endl;
    cout << "2- Registrar Cine" << endl;
    cout << "3- Registrar Funcion" << endl;
    cout << "7- Listar Películas" << endl;
    cout << "8- Listar Cines" << endl;
    cout << "9- Registrar Usuario" << endl;
    cout << "0- Cerrar Sesión" << endl;
    cout << "_____________________________________________" << endl;
}

int main()
{
    fabrica = Fabrica::getInstancia();
    iconSesion = fabrica->getIControladorSesion();
    iconPelicula = fabrica->getIControladorPelicula();
    iconCine = fabrica->getIControladorAltaCine();

    int opcion;
    do
    {
        menu();
        cout << "Seleccione una opción: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            iniciarSesion();
            break;
        case 2:
            AltaUsuario();
            break;

        default:
            cout << "Opción no válida. Intente de nuevo." << endl;
            break;
        }
    } while (!iconSesion->existeSesion());
    do
    {
        menu2();
        cout << "Seleccione una opción: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            registrarPelicula();
            break;
        case 2:
            altaCine();
            break;
        case 3:
            AltaFuncion();
            break;

        case 7:
            listarPeliculas();
            break;
        case 8:
            listarCines();
            break;
        case 9:
            AltaUsuario();
            break;
        case 0:
            iconSesion->cerrarSesion();
            break;
        default:
            cout << "Opción no válida. Intente de nuevo." << endl;
            break;
        }
    } while (iconSesion->existeSesion());

    cout << "Gracias por usar el sistema del momo." << endl;
}
