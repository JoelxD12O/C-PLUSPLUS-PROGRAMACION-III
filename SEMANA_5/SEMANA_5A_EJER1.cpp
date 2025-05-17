//
// Created by user on 17/05/2025.
//
#include <iostream>
#include <vector>
#include <cmath> // Para usar abs()
using namespace std;

// Función de comparación: devuelve true si a > b
// Lo usaremos para ordenar de menor a mayor (porque si a > b, se intercambian)
bool F1(int a, int b) {
    return a > b;
}

// Bubble sort usando función de comparación F
// Compara los elementos usando su valor absoluto
void bubble_sort(vector<int> &A, bool(*F)(int, int)) {
    for (int i = 0; i < A.size() - 1; i++) {
        for (int j = 0; j < A.size() - i - 1; j++) {
            // Comparación usando valor absoluto
            if (F(abs(A[j]), abs(A[j+1]))) {
                swap(A[j], A[j+1]);
            }
        }
    }
}

// Función genérica para imprimir un vector
template<typename T>
void print(vector<T> vec) {
    for (const T& e : vec)
        cout << e << " ";
    cout << endl;
}

int main() {
    // Vector con valores positivos y negativos
    vector<int> A = {-10, 2, -3, 4, -5, 6, -7, 8, -9, 1};

    /*for (int &x : A)
        x = abs(x);*/

    // Ordenamos según valor absoluto usando F1
    bubble_sort(A, F1);

    // Mostramos el vector ordenado (por valor absoluto, pero manteniendo signos)
    print(A);

    return 0;
}
