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
    cout << "9-CerrarSesion: " << endl;
    cout << "0-CerrarSesion: " << endl;
    cout << "_____________________________________________" << endl;
}

void registrarUsuario()
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
    string nick, pass;
    cout << "_____________________________________________" << endl;
    cout << "___________INICIAR SESION____________" << endl;
    cout << "Ingrese su nick: ";
    cin >> nick;
    cout << "Ingrese su contraseña: ";
    cin >> pass;
    iconSesion->iniciarSesion(nick, pass);
    cout << "_____________________________________________" << endl;
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

void registrarCine(){
    string nombre, direccion;
    cout << "_____________________________________________" << endl;
    cout << "___________REGISTRAR CINE____________" << endl;
    cout << "Ingrese el nombre del cine: ";
    cin >> nombre;
    cout << "Ingrese la dirección del cine: ";
    cin >> direccion;
 
    cout << "Cine registrado exitosamente." << endl;
    cout << "_____________________________________________" << endl;
}
int main()
{
    fabrica = Fabrica::getInstancia();
    iconSesion = fabrica->getIControladorSesion();
    iconPelicula = fabrica->getIControladorPelicula();
    int opcion;
    menu();
    menu();
    cout << "Seleccione una opción: ";
    cin >> opcion;
    do
    {
        switch (opcion)
        {
        case 1:
            iniciarSesion();
            break;
        case 2:
            registrarUsuario();
            break;

        default:
            cout << "Opción no válida. Intente de nuevo." << endl;
            break;
        }
    } while (opcion != 0);
    cout << "Seleccione una opción: ";
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        registrarPelicula();
        break;
    case 2:
        registrarCine();
        break;
    case 9:
        registrarUsuario();
        break;
    case 0:
        iconSesion->cerrarSesion();
        break;
    default:
        cout << "Opción no válida. Intente de nuevo." << endl;
        break;
    }
    cout << "Gracias por usar el sistema del momo." << endl;
}
