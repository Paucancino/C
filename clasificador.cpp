#include <iostream>
using namespace std;

int main() {
    double calificacion;

    cout << "Ingresa la calificacion (0-100): ";
    cin >> calificacion;

    if (calificacion < 0 || calificacion > 100) {
        cout << "Calificacion invalida." << endl;
    }
    else if (calificacion < 60) {
        cout << "NA (No Acreditado)" << endl;
    }
    else if (calificacion < 70) {
        cout << "S (Suficiente)" << endl;
    }
    else if (calificacion < 80) {
        cout << "B (Bien)" << endl;
    }
    else if (calificacion < 90) {
        cout << "MB (Muy Bien)" << endl;
    }
    else {
        cout << "E (Excelente)" << endl;
    }

    return 0;
}