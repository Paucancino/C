#include <iostream>
#include <string>
using namespace std;

class Estudiante {
private:
    string nombre;
    string matricula;
    double promedio;

public:
    Estudiante(string nombre, string matricula, double promedio) {
        this->nombre = nombre;
        this->matricula = matricula;
        this->promedio = promedio;
    }

    void mostrarInformacion() {
        cout << "Nombre: " << nombre << endl;
        cout << "Matricula: " << matricula << endl;
        cout << "Promedio: " << promedio << endl;
    }

    bool enRiesgoAcademico() {
        return promedio < 70;
    }

    double getPromedio() {
        return promedio;
    }

    string getNombre() {
        return nombre;
    }
};

int main() {
    Estudiante e1("Ana Perez", "A001", 85.5);

    cout << "Informacion del estudiante:" << endl;
    cout << "-------------------------" << endl;
    e1.mostrarInformacion();

    if (e1.enRiesgoAcademico()) {
        cout << "Estado: En riesgo academico" << endl;
    }
    else {
        cout << "Estado: Sin riesgo academico" << endl;
    }

    return 0;
}
