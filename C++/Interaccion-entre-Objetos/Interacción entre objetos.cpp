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

class Grupo {
private:
    Estudiante* estudiantes[3];
    int cantidad;

public:
    Grupo() {
        cantidad = 0;
    }

    void agregarEstudiante(Estudiante* e) {
        if (cantidad < 3) {
            estudiantes[cantidad] = e;
            cantidad++;
        }
    }

    double calcularPromedioGeneral() {
        double suma = 0;
        for (int i = 0; i < cantidad; i++) {
            suma += estudiantes[i]->getPromedio();
        }
        return suma / cantidad;
    }

    void mostrarGrupo() {
        for (int i = 0; i < cantidad; i++) {
            estudiantes[i]->mostrarInformacion();
            if (estudiantes[i]->enRiesgoAcademico()) {
                cout << "Estado: En riesgo academico" << endl;
            }
            else {
                cout << "Estado: Sin riesgo academico" << endl;
            }
            cout << "-------------------------" << endl;
        }
    }
};

int main() {
    Estudiante e1("Ana Perez", "A001", 85.5);
    Estudiante e2("Luis Gomez", "A002", 65.0);
    Estudiante e3("Maria Lopez", "A003", 92.3);

    Grupo grupo;
    grupo.agregarEstudiante(&e1);
    grupo.agregarEstudiante(&e2);
    grupo.agregarEstudiante(&e3);

    cout << "Informacion del grupo:" << endl;
    cout << "-------------------------" << endl;
    grupo.mostrarGrupo();

    cout << "Promedio general del grupo: " << grupo.calcularPromedioGeneral() << endl;

    return 0;
}
