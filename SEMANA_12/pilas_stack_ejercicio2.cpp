//
// Created by user on 10/06/2025.
//
#include <iostream>
#include <stack>
using namespace std;
string decimalABinario(int numero) {
    stack<int> pila;
    while (numero > 0) {
        pila.push(numero % 2);
        numero /= 2;
    }

    string binario = "";
    while (!pila.empty()) {
        binario += to_string(pila.top());
        pila.pop();
    }

    return binario;
}


int main() {
    int decimal = 42;
    string binario = decimalABinario(decimal);
    cout << decimal << " -> " << binario << endl;
    // Salida: 42 -> 101010

    return 0;
}
