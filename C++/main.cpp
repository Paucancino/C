#include <iostream>
#include "calculadora.h"

using namespace std;

int main() {
    int opc;
    float num1, num2, resultado;

    do {
        menu(opc);

        if (opc >= 1 && opc <= 4) {
            pedirOperandos(num1, num2); 
        }

        switch (opc) {
        case 1:
            resultado = suma(num1, num2);
            cout << "El resultado es: " << resultado << endl;
            break;

        case 2:
            resultado = resta(num1, num2);
            cout << "El resultado es: " << resultado << endl;
            break;

        case 3:
            resultado = multiplicacion(num1, num2);
            cout << "El resultado es: " << resultado << endl;
            break;

        case 4:

            if (division(num1, num2, resultado)) {
                cout << "El resultado es: " << resultado << endl;
            }
            else {
                cout << "Error: No se puede dividir entre cero." << endl;
            }
            break;

        case 5:
            cout << "Saliendo del programa..." << endl;
            break;

        default:
            cout << "Opcion invalida." << endl;
            break;
        }

    } while (opc != 5);

    return 0;
}