#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <cmath>

using namespace std;

void LimpiarPantalla(){
	if(system("cls") == -1){
		cout<<"Error al borrar la pantalla  :(";
	}
}

int enter_num() {
    string entrada;
    bool entradaValida = false;  // Variable booleana para controlar el ciclo
    int valor = 0;  // Variable para almacenar el valor entero

    while (!entradaValida) {  // Continuar hasta que la entrada sea válida
        cout << "Introduce numero: ";
        cin >> entrada;

        try {
            valor = stoi(entrada);  // Intentar convertir la entrada en un entero
            entradaValida = true;  // Establecer la entrada como válida
        } catch (const invalid_argument&) {
            cout << "La entrada no es un numero entero valido." << endl;
        } catch (const out_of_range&) {
            cout << "El numero es demasiado grande para ser representado como un entero." << endl;
        }
    }

    return valor;  // Devolver el valor entero válido
}

void play_game(int level){
    int secret_number;
    int max_intents;
    string texto;
    srand(static_cast<unsigned int>(std::time(nullptr)));
    switch (level){
    case 1:
        texto = "Valor entre 0 y 100: ";
        secret_number = std::rand() % 101;
        max_intents = 50;
        break;
    case 2:
        texto = "Valor entre 0 y 1000: ";
        secret_number = std::rand() % 1001;
        max_intents = 500;
        break;
    case 3:
        texto = "Valor entre 0 y 10000: ";
        secret_number = std::rand() % 10001;
        max_intents = 5000;
        break;
    case 4:
        texto = "Valor entre 0 y 100000: ";
        secret_number = std::rand() % 100001;
        max_intents = 50000;
        break;
    default:
        cout << "Opcion no valida" << endl;
        break;
    }
    cout << texto << secret_number << endl;
    int guessed;
    int counter = 0;
    int diferencia;
    int nueva_diferencia;
    int max_value = pow(10, level+1);
    cout << max_value << endl;

    while(guessed != secret_number && counter < max_intents){
        guessed = enter_num();
        if(guessed > 0 && guessed <= max_value){
            counter++;
            nueva_diferencia = abs(guessed - secret_number);

            if(counter > 1 && guessed != secret_number){
                if(nueva_diferencia <= diferencia){
                    cout << "Te estas acercando (intentos " << counter <<")" << endl;
                }else{
                    cout << "Te estas alejando (intentos " << counter <<")" << endl;
                }
            }
            diferencia = nueva_diferencia;
        }else{
            cout << "Incorrect value for level " << level << " (must be 0 - " << max_value << ")"  << endl;
        }
    }
    if(guessed == secret_number){
        cout << "You win! in " << counter << " times." << endl;
    }else{
        cout << "Sorry, you loose." << endl;
    }
}

int choose_level(){
    int level;
    cout << "\nESCOJA NIVEL DE DIFICULTAD" << endl;
    cout << "NIVEL 1: ENTRE 0 Y 100" << endl;
    cout << "NIVEL 2: ENTRE 0 Y 1000" << endl;
    cout << "NIVEL 3: ENTRE 0 Y 10000" << endl;
    cout << "NIVEL 4: ENTRE 0 Y 100000" << endl;

    while (true){
        cout << "\nINGRESE OPCION: "; cin >> level;

        if (level >= 1 && level <= 4){
            play_game(level);
            break;
        }else{
            cout << "El nivel debe estar entre 1 y 4. Por favor, intente de nuevo." << endl;
        }
    }
    return level;
}

int main(){
    string play = "Y";
    while(play == "Y" | play == "y"){
        LimpiarPantalla();
        cout << "\n------------ADIVINA NUMERO SUPER-DESAFIO------------" << endl;
        cout << "En este juego el usuario tiene que adivinar" << endl;
        cout << "un numero escogido, al azar, por la computadora" << endl;
        cout << "dentro de un rango determinado en funcion." << endl;
        cout << "----------------------------------------------------" << endl;

        int nivel = choose_level();
        //cout << "NIVEL: " << nivel << endl;
        cout << "\nDo you want to continue(Y/n)?: "; cin >> play;
        while(play != "Y" && play != "y" && play != "n" && play != "N"){
        cout << "Wrong input: "; cin >> play;
        }
        //cin >> play;
    }
    cout << "\nBye Bye..." << endl;
    return 0;
}
