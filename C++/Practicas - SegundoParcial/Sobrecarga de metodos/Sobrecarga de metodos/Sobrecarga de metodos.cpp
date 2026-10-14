#include <iostream>
using namespace std;

//CLASE CALCULADORA
class Calculadora {
public:
    //VERSION1 (suma dos enteros)
    int sumar(int a, int b) const {
        return a + b;
    }

    //VERSION2 (suma tres enteros)
    int sumar(int a, int b, int c) const {
        return a + b + c;
    }

    //VERSION3 (suma dos decimales)
    double sumar(double a, double b) const {
        return a + b;
    }
};

int main() {
    Calculadora calc;

    //El compilador elige la version segun el numero y tipo de parametros
    cout << "Suma de dos enteros (5 + 3): " << calc.sumar(5, 3) << endl;
    cout << "Suma de tres enteros (5 + 3 + 2): " << calc.sumar(5, 3, 2) << endl;
    cout << "Suma de dos decimales (2.5 + 1.75): " << calc.sumar(2.5, 1.75) << endl;

    return 0;
}
