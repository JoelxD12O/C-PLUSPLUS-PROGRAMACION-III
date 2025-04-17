//
// Created by joel on 16/04/2025.
//
#include <iostream>
#include <string>
using namespace std;

// Plantilla genérica para tipos no punteros
template <typename T>
string Tipo(T x) {
    return "No es puntero";
}

// Especialización de la plantilla para punteros a int
template<>
string Tipo(int* x) {
    return "Es puntero 'int'";
}

// Plantilla genérica para punteros en general
template <typename T>
string Tipo(T* x) {
    return "Es puntero";
}

int main() {
    // Variables
    double x;            // No es puntero
    double* y = new double(4);  // Es puntero a double
    int z = 10;          // No es puntero

    // Usando la plantilla genérica y especializaciones
    cout << Tipo(x) << endl;  // Llamada con un tipo no puntero (double)
    cout << Tipo(y) << endl;  // Llamada con un puntero a double
    cout << Tipo(z) << endl;  // Llamada con un tipo no puntero (int)

    // Limpiar la memoria asignada dinámicamente
    delete y;

    return 0;
}
