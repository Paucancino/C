#include <iostream>
#include <string>
using namespace std;

//CLASE BASE (vehiculo)
class Vehiculo {
protected:
    string marca;
    string modelo;
    int velocidadMax;

public:
    Vehiculo(const string& marca, const string& modelo, int velocidadMax)
        : marca(marca), modelo(modelo), velocidadMax(velocidadMax) {
    }

    virtual void mostrarInfo() const {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Velocidad maxima: " << velocidadMax << " km/h" << endl;
    }

    virtual ~Vehiculo() {}
};

//CLASE DERIVADA (auto)
class Auto : public Vehiculo {
private:
    int numPuertas;
    string tipoCombustible;

public:
    Auto(const string& marca, const string& modelo, int velocidadMax,
        int numPuertas, const string& tipoCombustible)
        : Vehiculo(marca, modelo, velocidadMax),
        numPuertas(numPuertas), tipoCombustible(tipoCombustible) {
    }

    void mostrarInfo() const override {
        cout << "--- AUTO --" << endl;
        Vehiculo::mostrarInfo();
        cout << "Numero de puertas: " << numPuertas << endl;
        cout << "Combustible: " << tipoCombustible << endl;
    }
};

//CLASE DERIVADA (moto)
class Motocicleta : public Vehiculo {
private:
    int cilindrada;
    bool tieneSidecar;

public:
    Motocicleta(const string& marca, const string& modelo, int velocidadMax,
        int cilindrada, bool tieneSidecar)
        : Vehiculo(marca, modelo, velocidadMax),
        cilindrada(cilindrada), tieneSidecar(tieneSidecar) {
    }

    void mostrarInfo() const override {
        cout << "--- MOTOCICLETA ---" << endl;
        Vehiculo::mostrarInfo();
        cout << "Cilindrada: " << cilindrada << " cc" << endl;
        if (tieneSidecar) {
            cout << "Sidecar: Si" << endl;
        }
        else {
            cout << "Sidecar: No" << endl;
        }
    }
};

int main() {

    Vehiculo* garage[4];
    garage[0] = new Auto("Toyota", "Corolla", 180, 4, "Gasolina");
    garage[1] = new Motocicleta("Yamaha", "MT-07", 210, 689, false);
    garage[2] = new Auto("Tesla", "Model 3", 225, 4, "Electrico");
    garage[3] = new Motocicleta("Ural", "Gear Up", 110, 749, true);

    for (int i = 0; i < 4; i++) {
        garage[i]->mostrarInfo();
        cout << endl;
    }

    for (int i = 0; i < 4; i++) {
        delete garage[i];
    }

    return 0;
}
