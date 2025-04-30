//
// Created by alumno08 on 29/04/2025.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



template<typename T>
void print(T inicio, T fin) {
    for (auto it = inicio; it != fin; ++it) {
        cout << *it << ' ';
    }
    cout << endl;
}


template<typename T>
auto maximo(T inicio, T fin) -> T {
    T it_max = inicio;
    for (auto it = next(inicio); it != fin; ++it) {
        if (*it > *it_max) {
            it_max = it;
        }
    }
    return it_max;
}

template<typename T>
double promedio(T it_begin, T it_end) {
    double suma = 0;

    for (auto it = it_begin; it != it_end; ++it) {
        suma += *it;
    }
    return suma / (it_end-it_begin);
}


int main() {

    srand(time(0)); // Semilla para números aleatorios

    // Ejercicio 1: Vector con 10 números aleatorios
    vector<int> v(10);
    generate(v.begin(), v.end(), []() { return rand() % 100; });

    cout << "Vector generado: ";
    print(v.begin(), v.end());

    // Encontrar el máximo
    auto it_max = maximo(v.begin(), v.end());
    cout << "El valor maximo es: " << *it_max
         << " en la posicion: " << distance(v.begin(), it_max) << endl;


    cout << "Promedio: " << promedio(v.begin(), v.end()) << endl;

return 0;
}
