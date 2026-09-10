#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;

int main() {
    string frase;

    cout << "Ingresa una frase: ";
    getline(cin, frase);

    int numPalabras = 0;
    stringstream ss(frase);
    string palabra;
    while (ss >> palabra) {
        numPalabras++;
    }

    int numVocales = 0;
    for (char c : frase) {
        char letra = tolower(c);
        if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u') {
            numVocales++;
        }
    }

    string invertida = frase;
    int inicio = 0;
    int fin = invertida.length() - 1;
    while (inicio < fin) {
        char temp = invertida[inicio];
        invertida[inicio] = invertida[fin];
        invertida[fin] = temp;
        inicio++;
        fin--;
    }

    cout << "Numero de palabras: " << numPalabras << endl;
    cout << "Numero de vocales: " << numVocales << endl;
    cout << "Frase invertida: " << invertida << endl;

    return 0;
}
