using namespace std;
#include <iostream>

void menu()
{
    cout << "_____________________________________________" << endl;
    cout << "____________CINE____________" << endl;
    cout << "1-Iniciar sesion: " << endl;
    cout << "_____________________________________________" << endl;
}

int main()
{
    Fabrica= Fabrica::getInstancia();
    do
    { 
        string nick, pass;
        cout << "_____________________________________________" << endl;
        cout << "___________INICIAR SESION____________" << endl;
        cout << "Ingrese su nick: ";
        cin >> nick;
        cout << "Ingrese su contraseña: ";
        cin >> pass;

    } while (true);
}