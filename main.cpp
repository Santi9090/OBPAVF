using namespace std;
#include <iostream>
#include "Fabrica.h"
#include "DataTypes/DtCine.h"
#include "DataTypes/DtHorario.h"
#include "DataTypes/DtFecha.h"
#include "DataTypes/DtFuncion.h"
#include "DataTypes/DtPelicula.h"
#include "DataTypes/DtCredito.h"
#include "DataTypes/DtDebito.h"
#include "DataTypes/DtReserva.h"

Fabrica *fabrica;
IControladorSesion *iconSesion;
IControladorPelicula *iconPelicula;
IControladorAltaCine *iconCine;
IControladorAltaFuncion *iconFuncion;
IControladorCrearReserva *iconReserva;
IControladorVerReservaPelicula *iconVerReservaPelicula;
IControladorPuntajeComentario *iconPuntajeComentario;

struct RelojSistema
{
    DtFecha fecha;
    DtHorario hora;
};
RelojSistema *reloj = new (RelojSistema);
void menu()
{
    cout << "_____________________________________________" << endl;
    cout << "_____________BIENVENIDO AL CINE DEL MOMO_____________" << endl;
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
            int opcion = 0;
            do
            {
                cout << "_____________________________________________" << endl;
                cout << "___________LISTA DE SALAS____________" << endl;
                list<DtSala> salas = iconCine->listarSalas(idCine);
                for (auto &sala : salas)
                {
                    cout << "ID de Sala: " << sala.getIdSala() << endl;
                    cout << "Capacidad: " << sala.getCapacidad() << endl;
                }
                cout << "_____________________________________________" << endl;
                cout << "___________Seleccione una Sala____________" << endl;
                int idSala;
                cout << "Ingrese el ID de la sala: ";
                cin >> idSala;
                DtHorario horario;
                DtFecha fecha;
                int anio, mes, dia;
                string horaComienzo, horaFin;
                cout << "Ingrese dia : " << endl;
                cin >> dia;
                cout << "Ingrese mes : " << endl;
                cin >> mes;
                cout << "Ingrese año : " << endl;
                cin >> anio;
                fecha = DtFecha(dia, mes, anio);
                cout << "Ingrese la hora comienzo : " << endl;
                cin >> horaComienzo;
                cout << "Ingrese la hora fin : " << endl;
                cin >> horaFin;
                horario = DtHorario(horaComienzo, horaFin);
                iconFuncion->AltaFuncion(idCine, idSala, fecha, horario, titulo);
                cout << "Función registrada exitosamente." << endl;
                cout << "_____________________________________________" << endl;
                cout << "¿Desea registrar otra función? (1-Sí, 0-No): ";
                cin >> opcion;
            } while (opcion != 0);
        }
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

void mostrarFunciones()
{

    cout << "_____________________________________________" << endl;
    cout << "___________LISTA DE FUNCIONES____________" << endl;
    list<DtFuncion> funciones = iconFuncion->listarFunciones();
    for (list<DtFuncion>::iterator it = funciones.begin(); it != funciones.end(); ++it)
    {
        cout << "ID de Función: " << it->getIdFuncion() << endl;
        cout << "Fecha: " << it->getFecha().getDia() << "/" << it->getFecha().getMes() << "/" << it->getFecha().getAnio() << endl;
        cout << "Horario: " << it->getHorario().getHoraComienzo() << " - " << it->getHorario().getHoraFin() << endl;
        cout << "Película: " << it->getPelicula().getTitulo() << endl;
        cout << "Sinopsis: " << it->getPelicula().getSinopsis() << endl;
    }
}
void altaReserva()
{
    string pelicula;
    cout << "_____________________________________________" << endl;
    cout << "___________LISTA DE PELICULAS____________" << endl;
    list<DtPelicula> peliculas = iconPelicula->ListarPeliculas();
    for (list<DtPelicula>::iterator it = peliculas.begin(); it != peliculas.end(); ++it)
    {
        cout << "Título: " << it->getTitulo() << endl;
    }
    cout << "Ingrese el título de la película: (0 para cancelar) ";
    cin >> pelicula;
    if (pelicula == "0")
    {
        cout << "SE CANCELA LA RESERVA" << endl;
    }
    else
    {

        cout << "Desea ver información de la película? (1-Sí, 0-No): ";
        int opcion;
        cin >> opcion;
        if (opcion == 0)
        {
            cout << "SE CANCELA LA RESERVA" << endl;
        }
        else
        {
            cout << "_____________________________________________" << endl;
            cout << "___________OTROS DATOS DE LA PELICULA____________" << endl;
            list<DtPelicula> peliculas = iconPelicula->ListarPeliculas();
            for (list<DtPelicula>::iterator it = peliculas.begin(); it != peliculas.end(); ++it)
            {
                if (pelicula == it->getTitulo())
                {
                    DtPelicula lapelicula = *it;
                    cout << "Poster: " << it->getPoster() << endl;
                    cout << "Sinopsis: " << it->getSinopsis() << endl;
                }
            }
            cout << "_____________________________________________" << endl;
            cout << "_________CINES QUE TIENEN LA PELICULA________" << endl;
            list<DtCine> cines = iconCine->getCines();
            for (list<DtCine>::iterator it = cines.begin(); it != cines.end(); ++it)
            {

                list<DtPelicula> peliculas = it->getPeliculas();
                for (list<DtPelicula>::iterator it2 = peliculas.begin(); it2 != peliculas.end(); ++it2)
                {
                    if (it2->getTitulo() == pelicula)
                    {

                        cout << "Cine: " << it->getDireccion().getCalle() << endl;
                        cout << "Número: " << it->getDireccion().getNumero() << endl;
                        cout << "ID: " << it->getIdCine() << endl;
                    }
                }
            }
            cout << "Ingrese el ID del cine: (0 Para cancelar) ";
            int idCine;
            cin >> idCine;
            if (idCine == 0)
            {
                cout << "SE CANCELA LA RESERVA" << endl;
            }
            else
            {
                DtCine cine = iconCine->encontrarCine(idCine);
                mostrarSalas(idCine);
                cout << "Ingrese el ID de la sala: (0 Para cancelar) ";
                int idSala;
                cin >> idSala;
                if (idSala == 0)
                {
                    cout << "SE CANCELA LA RESERVA" << endl;
                }
                else
                {
                    cout << "_____________________________________________" << endl;
                    cout << "_________FUNCIONES DE LA PELICULA____________" << endl;
                    list<DtSala> salas = cine.getSalas();
                    iconReserva->ListarFuncionesPeli(pelicula, idCine, reloj->fecha, reloj->hora);
                    int idFuncion, asientos, pago;
                    cout << "_____Seleccionar Funcion_____" << endl;
                    cout << "Selecionar id: " << endl;
                    cin >> idFuncion;
                    cout << "Selccionar cantidad de asientos: " << endl;
                    cin >> asientos;
                    cout << "Ingresar Medio de pago: (1-debito 2-Credito) " << endl;
                    cin >> pago;
                    if (pago == 1)
                    {
                        string banco;
                        cout << "Ingresar Nombre del banco : " << endl;
                        cin >> banco;
                        cout << "El precio es de : " << 500 * asientos << endl;
                        cout << "Desea crear la reserva (1-Si 0-No)." << endl;
                        int opc;
                        cin >> opc;
                        if (opc == 1)
                        {
                            DtDebito debito = DtDebito(500 * asientos, asientos, 0, banco);
                            iconReserva->CrearReserva(idCine, idSala, idFuncion, pelicula, debito);
                            cout << "SE CREO LA RESERVA EXITOSAMENTE" << endl;
                        }
                    }
                    else if (pago == 2)
                    {
                        string financiera;
                        int opt;
                        cout << "Ingresar Financiera : " << endl;
                        cin >> financiera;
                        cout << "Sin descuento " << endl;
                        cout << "El precio es de : " << 500 * asientos << endl;
                        cout << "Quiere continuar: (1-Si 0-No)" << endl;
                        cin >> opt;
                        if (opt == 1)
                        {
                            cout << "Desea crear la reserva (1-Si 0-No)." << endl;
                            int opc;
                            cin >> opc;
                            if (opc == 1)
                            {
                                DtCredito credito(500 * asientos, asientos, 0, 0.0, financiera);
                                iconReserva->CrearReserva(idCine, idSala, idFuncion, pelicula, credito);
                            }
                            else
                            {
                            }
                        }
                        else
                        {
                        }
                    }
                }
            }
        }
    }
}
void cambiarHoraSistema()
{
    int dia, mes, anio;
    string hora, minuto;
    cout << "____________________________" << endl;
    cout << "________CAMBIAR HORA________" << endl;
    cout << "Ingresar hora : [dd mm aaaa hh mm]" << endl;
    cin >> dia >> mes >> anio >> hora >> minuto;
    DtFecha fecha(dia, mes, anio);
    DtHorario fhora(hora, minuto);
    reloj->fecha = fecha;
    reloj->hora = fhora;
}
void VerReservaDePelicula()
{
    string titulo;
    cout << "_____________________________________________" << endl;
    cout << "___________VER RESERVA DE PELICULA____________" << endl;
    listarPeliculas();
    cout << "Ingrese el título de la película: ";
    cin >> titulo;
    iconVerReservaPelicula->VerReservaDePelicula(titulo);
    cout << "_____________________________________________" << endl;
}
void consultarHoraSistema()

{

    cout << "________HORA SISTEMA________" << endl;
    cout << reloj->fecha.getAnio() << "/" << reloj->fecha.getMes() << "/" << reloj->fecha.getDia() << " "
         << reloj->hora.getHoraComienzo() << ":" << reloj->hora.getHoraFin() << endl;
    cout << "____________________________" << endl;
}

void EliminarPelicula()
{
    string titulo;
    cout << "_____________________________________________" << endl;
    cout << "___________ELIMINAR PELICULA____________" << endl;
    listarPeliculas();
    cout << "Ingrese el título de la película a eliminar: ";
    cin >> titulo;
    if (iconPelicula->ExistePelicula(titulo))
    {
        iconPelicula->EliminarPelicula(titulo);
        cout << "Película eliminada exitosamente." << endl;
    }
    else
    {
        cout << "La película no existe." << endl;
    }
}
void mostrarComentarios(string titulo)
{

    iconPuntajeComentario->listarComentarios(titulo);
}
void mostrarPuntajes(string titulo)
{

    iconPuntajeComentario->listarPuntajes(titulo);
}
void puntuarPelicula()
{
    int opc;
    string titulo;
    cout << "_____________________________________________" << endl;
    cout << "___________PUNTUAR PELICULA____________" << endl;
    listarPeliculas();
    cout << "Ingrese el título de la pelicula: ";
    cin >> titulo;
    iconPuntajeComentario->listarPuntaje(titulo);

    cout << "Desea puntuar la pelicula (1-Si 0-No)" << endl;
    cin >> opc;
    if (opc == 1)
    {
        cout << "Ingresar Puntaje: " << endl;
        cin >> opc;
        iconPuntajeComentario->agregarPuntaje(opc, titulo);
    }
    else
    {
    }
}
void comentarPelicula()
{
    int opc;
    string titulo, comentario;
    cout << "_____________________________________________" << endl;
    cout << "___________COMENTAR PELICULA____________" << endl;
    listarPeliculas();
    cout << "Ingrese el título de la pelicula: ";
    cin >> titulo;
    mostrarComentarios(titulo);
    cout << "Desea comentar la pelicula (1-Si 0-Responde comentario)" << endl;
    cin >> opc;
    if (opc == 0)
    {
        cout << "Elegir Comentario (ID): " << endl;
        cin >> opc;
        cout << "Ingresar Comentario: " << endl;
        cin.ignore();
        getline(cin, comentario);
        iconPuntajeComentario->agregarRespuesta(opc, comentario, titulo);
    }
    else
    {
        cout << "Ingresar Comentario: " << endl;
        cin.ignore();
        getline(cin, comentario);
        iconPuntajeComentario->agregarComentario(comentario, titulo);
    }
}

void menu2()
{
    cout << "_____________________________________________" << endl;
    cout << "_____________MENU ___________________________" << endl;
    cout << "1- Registrar Película" << endl;
    cout << "2- Registrar Cine" << endl;
    cout << "3- Registrar Funcion" << endl;
    cout << "4- Registrar Reserva" << endl;
    cout << "5- Ver Reservas de pelicula" << endl;
    cout << "6- Listar Funciones" << endl;
    cout << "7- Listar Películas" << endl;
    cout << "8- Listar Cines" << endl;
    cout << "9- Registrar Usuario" << endl;
    cout << "10- Cambiar hora sistema " << endl;
    cout << "11- Ver Hora sistema" << endl;
    cout << "12- Eliminar Película" << endl;
    cout << "13- Puntuar pelicula" << endl;
    cout << "14- Comentar pelicula" << endl;
    cout << "15- Ver comentario y puntaje de pelicula" << endl;
    cout << "16- Ver Informacion de pelicula" << endl;
    cout << "17- Cargar Datos (para pruebas)" << endl;

    cout << "0- Cerrar Sesión" << endl;
    cout << "_____________________________________________" << endl;
}
void VerComentarioPuntajePelicula()
{
    cout << "_____________________________________________" << endl;
    cout << "___________VER COMENTARIO Y PUNTAJE DE PELICULA____________" << endl;
    string titulo;
    listarPeliculas();
    cout << "Ingrese el título de la pelicula: ";
    cin >> titulo;
    cout << "Comentarios" << endl;
    mostrarComentarios(titulo);
    cout << "Puntajes" << endl;
    mostrarPuntajes(titulo);
}
void VerInformacionPelicula()
{
    int salida = 0;
    do
    {
        string pelicula;
        cout << "_____________________________________________" << endl;
        cout << "___________LISTA DE PELICULAS____________" << endl;
        list<DtPelicula> peliculas = iconPelicula->ListarPeliculas();
        for (list<DtPelicula>::iterator it = peliculas.begin(); it != peliculas.end(); ++it)
        {
            cout << "Título: " << it->getTitulo() << endl;
        }
        cout << "Ingrese el título de la película: (0 para cancelar) ";
        cin >> pelicula;
        if (pelicula == "0")
        {
        }
        else
        {

            cout << "Desea ver información de la película? (1-Sí, 0-No): ";
            int opcion;
            cin >> opcion;
            if (opcion == 0)
            {
            }
            else
            {
                cout << "_____________________________________________" << endl;
                cout << "___________OTROS DATOS DE LA PELICULA____________" << endl;
                list<DtPelicula> peliculas = iconPelicula->ListarPeliculas();
                for (list<DtPelicula>::iterator it = peliculas.begin(); it != peliculas.end(); ++it)
                {
                    if (pelicula == it->getTitulo())
                    {
                        DtPelicula lapelicula = *it;
                        cout << "Poster: " << it->getPoster() << endl;
                        cout << "Sinopsis: " << it->getSinopsis() << endl;
                    }
                }
                cout << "_____________________________________________" << endl;
                cout << "_________CINES QUE TIENEN LA PELICULA________" << endl;
                list<DtCine> cines = iconCine->getCines();
                for (list<DtCine>::iterator it = cines.begin(); it != cines.end(); ++it)
                {

                    list<DtPelicula> peliculas = it->getPeliculas();
                    for (list<DtPelicula>::iterator it2 = peliculas.begin(); it2 != peliculas.end(); ++it2)
                    {
                        if (it2->getTitulo() == pelicula)
                        {

                            cout << "Cine: " << it->getDireccion().getCalle() << endl;
                            cout << "Número: " << it->getDireccion().getNumero() << endl;
                            cout << "ID: " << it->getIdCine() << endl;
                        }
                    }
                }
                cout << "Ingrese el ID del cine: (0 Para cancelar) ";
                int idCine;
                cin >> idCine;
                if (idCine == 0)
                {
                }
                else
                {
                    DtCine cine = iconCine->encontrarCine(idCine);

                    cout << "_____________________________________________" << endl;
                    cout << "_________FUNCIONES DE LA PELICULA____________" << endl;
                    list<DtSala> salas = cine.getSalas();
                    iconReserva->ListarFuncionesPeli(pelicula, idCine, reloj->fecha, reloj->hora);
                }
            }
        }
        cout << "_____________________________________________" << endl;
        cout << "Desea ver otra información de una pelicula? (1-Sí, 0-No): ";
        cin >> salida;
    } while (salida != 0);
}
void cargarDatos()
{
    cout << "Cargando datos..." << endl;
    //Usuarios
    iconSesion->registrarUsuario("juan","1234","foto1.jpg");
    iconSesion->registrarUsuario("ana","abcd","foto2.jpg");
    iconSesion->registrarUsuario("mario","pass","foto3.jpg");
    iconSesion->iniciarSesion("juan","1234");

    //Peliculas
    iconPelicula->RegistrarPelicula("Pelicula1","SinopsisPelicula1","urlFoto1");
    iconPelicula->RegistrarPelicula("Pelicula2","SinopsisPelicula2","urlFoto2");
    iconPelicula->RegistrarPelicula("Pelicula3","SinopsisPelicula3","urlFoto3");

    //Cines y Salas
    DtDireccion direccion1("Av.Principal",123);
    DtDireccion direccion2("CalleSecundaria",456);
    map<int,DtSala> salas1;
    salas1[1]=DtSala(1,100);
    salas1[2]=DtSala(2,80);
    map<int,DtSala> salas2;
    salas2[1]=DtSala(1,120);
    iconCine->AltaCine(direccion1,salas1);
    iconCine->AltaCine(direccion2,salas2);

    //Funciones
    DtFecha fecha1(23,6,2025);
    DtHorario horario1("20:00","22:00");
    DtHorario horario2("18:00","20:00");
    iconFuncion->AltaFuncion(1,1,fecha1,horario1,"Pelicula1");
    iconFuncion->AltaFuncion(1,2,fecha1,horario2,"Pelicula2");
    iconFuncion->AltaFuncion(2,1,fecha1,horario1,"Pelicula3");

    //Reservas
    DtDebito debito1(1000,2,0,"BancoEjemplo");
    DtCredito credito1(1500,3,0,0.0,"FinancieraEjemplo");
    iconReserva->CrearReserva(1,1,1,"Pelicula1",debito1);
    iconReserva->CrearReserva(1,2,2,"Pelicula2",credito1);
    iconSesion->cerrarSesion();
    iconSesion->iniciarSesion("ana","abcd");
    DtDebito debito2(500,1,0,"BancoAna");
    iconReserva->CrearReserva(2,1,3,"Pelicula3",debito2);
    iconSesion->cerrarSesion();
    iconSesion->iniciarSesion("mario","pass");
    DtCredito credito2(2000,4,0,0.0,"FinancieraMario");
    iconReserva->CrearReserva(1,1,1,"Pelicula1",credito2);
    iconSesion->cerrarSesion();
    iconSesion->iniciarSesion("juan","1234");

    //Puntajes y comentarios
    iconPuntajeComentario->agregarPuntaje(5,"Pelicula1");
    iconPuntajeComentario->agregarComentario("Muybuenapelicula","Pelicula1");
    iconSesion->cerrarSesion();
    iconSesion->iniciarSesion("ana","abcd");
    iconPuntajeComentario->agregarPuntaje(3,"Pelicula1");
    iconPuntajeComentario->agregarComentario("Me gustó pero esperaba más","Pelicula1");
    iconSesion->cerrarSesion();
    iconSesion->iniciarSesion("mario","pass");
    iconPuntajeComentario->agregarPuntaje(4,"Pelicula2");
    iconPuntajeComentario->agregarComentario("Entretenida,super","Pelicula2");
    iconSesion->cerrarSesion();
    iconSesion->iniciarSesion("juan","1234");
    cout << "Datos cargados exitosamente." << endl;
}
void lobby()
{
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
        int opcion;
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
        case 4:
            altaReserva();
            break;
        case 5:
            VerReservaDePelicula();
            break;
        case 6:
            mostrarFunciones();
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
        case 10:
            cambiarHoraSistema();
            break;
        case 11:
            consultarHoraSistema();
            break;
        case 12:
            EliminarPelicula();
            break;
        case 13:
            puntuarPelicula();
            break;
        case 14:
            comentarPelicula();
            break;
        case 15:
            VerComentarioPuntajePelicula();
            break;
        case 16:
            VerInformacionPelicula();
            break;
        case 17:
        cargarDatos();
            cout << "Datos cargados exitosamente." << endl;
            break;
        case 0:
            iconSesion->cerrarSesion();
            break;
        default:
            cout << "Opción no válida. Intente de nuevo." << endl;
            break;
        }
    } while (iconSesion->existeSesion());
}
int main()
{

    fabrica = Fabrica::getInstancia();
    iconSesion = fabrica->getIControladorSesion();
    iconPelicula = fabrica->getIControladorPelicula();
    iconCine = fabrica->getIControladorAltaCine();
    iconFuncion = fabrica->getIControladorAltaFuncion();
    iconReserva = fabrica->getIControladorCrearReserva();
    iconVerReservaPelicula = fabrica->getIControladorVerReservaPelicula();
    iconPuntajeComentario = fabrica->getIControladorPuntajeComentario();
    DtFecha fecha(1, 1, 1);
    DtHorario fhora("0", "0");
    reloj->fecha = fecha;
    reloj->hora = fhora;
    do
    {
        lobby();
    } while (true);

    cout << "Gracias por usar el sistema del momo." << endl;
}
