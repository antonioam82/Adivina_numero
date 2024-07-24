#include <iostream>
#include <limits>
#include <ctime>
#include <cmath>

using namespace std;

int seleccionarDificultad(){
    bool opcion_valida = false;
    int nivelDificultad;

    while(opcion_valida == false){
       cout << "********DIFICULTAD********" << endl;
       cout << "NIVEL 1: ENTRE 0 Y 100" << endl;
       cout << "NIVEL 2: ENTRE 0 Y 1000" << endl;
       cout << "NIVEL 3: ENTRE 0 Y 10000" << endl;
       cout << "NIVEL 4: ENTRE 0 Y 100000" << endl;
       cout << "Introduzca nivel de dificultad: ";
       cin >> nivelDificultad;

       if(cin.fail()) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada inválida
            cout << "OPCION INVALIDA. Por favor, ingrese un numero entero (1, 2, 3 o 4).\n" << endl;
            opcion_valida = false; // Restablecer 'opcion' para mantener el bucle
        }else{
            switch(nivelDificultad){
                case 1:
                    cout << "NIVEL 1\n" << endl;
                    opcion_valida = true;
                    break;
                case 2:
                    cout << "NIVEL 2\n" << endl;
                    opcion_valida = true;
                    break;
                case 3:
                    cout << "NIVEL 3\n" << endl;
                    opcion_valida = true;
                    break;
                case 4:
                    cout << "NIVEL 4\n" << endl;
                    opcion_valida = true;
                    break;
                default:
                    cout << "OPCION NO VALIDA\n" << endl;
                    //opcion_valida = false;
                    break;
            }
        }
    }
    return nivelDificultad;
}

void game(int num){
    int secretNum;
    int intentos = 0;
    int numero;
    srand(time(NULL));
    secretNum = (rand() % num) + 1;
    cout << "MAXIMO: " << num << endl;
    cout << "SECRET NUM: " << secretNum << endl;

    while(numero != secretNum){
        cout << "Introduce numero: ";
        cin >> numero;
        intentos++;
        if(numero != secretNum){
            if(numero < secretNum){
                cout << "EL NUMERO INTRODUCIDO ES MENOR QUE EL NUMERO  SECRETO" << endl;
            }else{
                cout << "EL NUMERO INTRODUCIDO ES MAYOR QUE EL NUMERO  SECRETO" << endl;
        };
        }
    }
    cout << "Numero adivinado en " << intentos << " intentos" << endl;

}

int main() {
    int opcion = 1;
    int dificultad;
    int n;

    while(opcion != 2) {
        cout << "*****ADIVINA NUMERO****" << endl;
        cout << "1 --------------- JUGAR" << endl;
        cout << "2 ----------------SALIR" << endl;
        cout << "INGRESE OPCION: ";
        cin >> opcion;

        if(cin.fail()) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada inválida
            cout << "OPCION INVALIDA. Por favor, ingrese un numero entero (1 o 2).\n" << endl;
            opcion = 1; // Restablecer 'opcion' para mantener el bucle
        } else {
            switch(opcion) {
                case 1:
                    cout << "Ha escogido jugar" << endl;
                    // Aquí puedes agregar el código del juego
                    dificultad = seleccionarDificultad();
                    n = pow(10, dificultad + 1);
                    game(n);

                    break;
                case 2:
                    cout << "Ha elegido salir" << endl;
                    break;
                default:
                    cout << "OPCION INVALIDA\n" << endl;
                    break;
            }
        }
    }

    return 0;
}
