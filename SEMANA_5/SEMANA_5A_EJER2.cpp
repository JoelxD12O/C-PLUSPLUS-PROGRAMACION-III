#include <iostream>
using namespace std;

// Clase para cifrado afín
struct CAfin {
    int a, b;

    // Constructor
    CAfin(int _x, int _y) : a(_x), b(_y) {}

    // Sobrecarga de () para cifrar una letra
    char operator()(char x) {
        int x_num = x - 'A';                  // Convertir letra a número (A = 0)
        int c_num = (a * x_num + b) % 26;     // Fórmula afín
        return 'A' + c_num;                   // Convertir número de nuevo a letra
    }
};

// Función para cifrar una frase completa
string cifrar_frase(CAfin F, string entrada) {
    string salida = "";
    for (char x : entrada) {
        salida += F(x); // Cifra cada letra y la agrega a la salida
    }
    return salida;
}

int main() {
    // Crear cifrador afín con a = 7 y b = 3
    CAfin cifrador(7, 3);

    // Pruebas individuales de letras
    cout << cifrador('H') << endl; // H → A
    cout << cifrador('O') << endl; // O → X
    cout << cifrador('L') << endl; // L → C
    cout << cifrador('A') << endl; // A → D

    // Cifrar una frase completa
    string mensaje = "HOLAMUNDOENCMASMAS";
    string cifrado = cifrar_frase(cifrador, mensaje);
    cout << cifrado << endl;

    return 0;
}
