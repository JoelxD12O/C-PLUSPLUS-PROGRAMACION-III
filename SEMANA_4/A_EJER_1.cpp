//
// Created by joel on 16/04/2025.
//
#include <iostream>
using namespace std;

template <typename T>
T sumar(T x1, T x2) {
    return x1 + x2;
}
char sumar(int x1, char x2) {
  return x1 + x2;
}

int main() {
    cout << sumar(7, 8) << endl;        // Resultado: 15
    cout << sumar('A', 1) << endl;      // Resultado: B (carácter 'A' + 1)
    cout << sumar(2, 'b') << endl;      // Resultado: d (2 + 'b' -> 98 + 2)
    cout << sumar('1', '2') << endl;    // Resultado: c (carácter '1' + '2' -> 49 + 50)
    cout << sumar(int('1'), int('2')) << endl; // Resultado: 99 (ASCII de '1' (49) + '2' (50))

    return 0;
};