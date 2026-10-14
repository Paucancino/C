#include <iostream>
using namespace std;

//CLASE BASE
class Fraccion {
private:
    int numerador;
    int denominador;

public:
    Fraccion(int numerador, int denominador)
        : numerador(numerador), denominador(denominador) {
        if (denominador == 0) {
            cout << "Error: el denominador no puede ser 0, se usara 1" << endl;
            this->denominador = 1;
        }
    }

    //SOBRECARGA
    Fraccion operator+(const Fraccion& otra) const {
        int nuevoNum = numerador * otra.denominador + otra.numerador * denominador;
        int nuevoDen = denominador * otra.denominador;
        return Fraccion(nuevoNum, nuevoDen);
    }
    bool operator==(const Fraccion& otra) const {
        return numerador * otra.denominador == otra.numerador * denominador;
    }

    void mostrar() const {
        cout << numerador << "/" << denominador;
    }
};

int main() {
    Fraccion f1(1, 2);
    Fraccion f2(1, 3);
    Fraccion f3(2, 4);

    Fraccion suma = f1 + f2;
    f1.mostrar();
    cout << " + ";
    f2.mostrar();
    cout << " = ";
    suma.mostrar();
    cout << endl << endl;

    f1.mostrar();
    cout << " y ";
    f3.mostrar();
    if (f1 == f3) {
        cout << " SON equivalentes" << endl;
    }
    else {
        cout << " NO son equivalentes" << endl;
    }

    f1.mostrar();
    cout << " y ";
    f2.mostrar();
    if (f1 == f2) {
        cout << " SON equivalentes" << endl;
    }
    else {
        cout << " NO son equivalentes" << endl;
    }

    return 0;
}
