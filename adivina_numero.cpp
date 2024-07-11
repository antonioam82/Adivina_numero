#include <iostream>
#include <limits>

using namespace std;

int main() {
    int opcion = 1;

    while(opcion != 2) {
        cout << "*****ADIVINA NUMERO****" << endl;
        cout << "1 --------------- JUGAR" << endl;
        cout << "2 ----------------SALIR" << endl;
        cout << "INGRESE OPCION: ";
        cin >> opcion;

        if(cin.fail()) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada inválida
            cout << "OPCION INVALIDA. Por favor, ingrese un numero entero (1 o 2)." << endl;
            opcion = 1; // Restablecer 'opcion' para mantener el bucle
        } else {
            switch(opcion) {
                case 1:
                    cout << "Ha escogido jugar" << endl;
                    // Aquí puedes agregar el código del juego
                    break;
                case 2:
                    cout << "Ha elegido salir" << endl;
                    break;
                default:
                    cout << "OPCION INVALIDA" << endl;
                    break;
            }
        }
    }

    return 0;
}
