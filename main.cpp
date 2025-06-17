using namespace std;
#include <iostream>
#include "Fabrica.h"

Fabrica *fabrica;
IControladorSesion *iconSesion;
IControladorPelicula *iconPelicula;
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
    string nombre, direccion;
    cout << "_____________________________________________" << endl;
    cout << "___________REGISTRAR CINE____________" << endl;
    cout << "Ingrese el nombre del cine: ";
    cin >> nombre;
    cout << "Ingrese la dirección del cine: ";
    cin >> direccion;
}

void menu2()
{
    cout << "_____________________________________________" << endl;
    cout << "_____________MENU ___________________________" << endl;
    cout << "1- Registrar Película" << endl;
    cout << "2- Registrar Cine" << endl;
    cout << "9- Registrar Usuario" << endl;
    cout << "0- Cerrar Sesión" << endl;
    cout << "_____________________________________________" << endl;
}

int main()
{
    fabrica = Fabrica::getInstancia();
    iconSesion = fabrica->getIControladorSesion();
    iconPelicula = fabrica->getIControladorPelicula();

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
