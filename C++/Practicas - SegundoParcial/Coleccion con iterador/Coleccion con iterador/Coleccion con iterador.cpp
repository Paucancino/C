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
        cout << "=== AUTO ===" << endl;
        Vehiculo::mostrarInfo();
        cout << "Numero de puertas: " << numPuertas << endl;
        cout << "Combustible: " << tipoCombustible << endl;
    }
};

//CLASE DERIVADA (moto)
class Motocicleta : public Vehiculo {
private:
    int cilindrada; // cc
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

//CLASE COLECCION (garage)
class Garage {
private:
    Vehiculo* vehiculos[10];
    int cantidad;

public:
    Garage() : cantidad(0) {
    }

    void agregar(Vehiculo* v) {
        if (cantidad < 10) {
            vehiculos[cantidad] = v;
            cantidad++;
        }
        else {
            cout << "El garage esta lleno" << endl;
        }
    }

    int getCantidad() const {
        return cantidad;
    }

    Vehiculo* obtener(int posicion) const {
        return vehiculos[posicion];
    }

    ~Garage() {
        for (int i = 0; i < cantidad; i++) {
            delete vehiculos[i];
        }
    }
};

//CLASE ITERADOR (propio)
class IteradorGarage {
private:
    const Garage& garage;
    int posicion;

public:
    IteradorGarage(const Garage& garage) : garage(garage), posicion(0) {
    }

    bool hayMas() const {
        return posicion < garage.getCantidad();
    }

    Vehiculo* siguiente() {
        Vehiculo* actual = garage.obtener(posicion);
        posicion++;
        return actual;
    }
};

int main() {
    Garage garage;
    garage.agregar(new Auto("Toyota", "Corolla", 180, 4, "Gasolina"));
    garage.agregar(new Motocicleta("Yamaha", "MT-07", 210, 689, false));
    garage.agregar(new Auto("Nissan", "Versa", 170, 4, "Gasolina"));
    garage.agregar(new Motocicleta("Ural", "Gear Up", 110, 749, true));
    garage.agregar(new Auto("Tesla", "Model 3", 225, 4, "Electrico"));

    cout << "Vehiculos en el garage: " << garage.getCantidad() << endl << endl;

    //RECORRIDO CON EL ITERADOR
    IteradorGarage it(garage);
    while (it.hayMas()) {
        Vehiculo* v = it.siguiente();
        v->mostrarInfo();
        cout << endl;
    }

    return 0;
}
