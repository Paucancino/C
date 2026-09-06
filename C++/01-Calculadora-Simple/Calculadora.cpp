#include <iostream>
#include "calculadora.h"

using namespace std;

void menu(int& opc) {
    cout << "\n-- BIENVENIDO A LA CALCULADORA --\n";
    cout << "1. Sumar\n";
    cout << "2. Restar\n";
    cout << "3. Multiplicar\n";
    cout << "4. Dividir\n";
    cout << "5. Salir\n";
    cout << "Opcion elegida: ";
    cin >> opc;
}

void pedirOperandos(float& a, float& b) {
    cout << "Ingresa el primer numero: ";
    cin >> a;
    cout << "Ingresa el segundo numero: ";
    cin >> b;
}

float suma(float a, float b) {
    return a + b;
}

float resta(float a, float b) {
    return a - b;
}

float multiplicacion(float a, float b) {
    return a * b;
}

bool division(float a, float b, float& resultado) {
    if (b == 0) {
        return false; 
    }
    resultado = a / b;
    return true; 
}
