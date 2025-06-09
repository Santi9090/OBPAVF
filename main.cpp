using namespace std;
#include <iostream>
#include "Fabrica.h"

Fabrica *fabrica;
IControladorSesion *iconSesion;
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
int main()
{
    fabrica = Fabrica::getInstancia();
    iconSesion = fabrica->getIControladorSesion();
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
