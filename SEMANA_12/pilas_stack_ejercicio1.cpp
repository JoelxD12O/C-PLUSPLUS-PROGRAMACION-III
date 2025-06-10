//
// Created by user on 10/06/2025.
//
#include <iostream>
#include <stack>
#include "windows.h"

using namespace std;

// Función para verificar si los paréntesis están balanceados
bool verificarParentesis(const string& cadena) {
    stack<char> pila;
    for (char c : cadena) {
        if (c == '(' || c == '{' || c == '[') {
            pila.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (pila.empty()) return "operacion incorrecta!";
            char top = pila.top();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
                }
            pila.pop();
        }
    }
    return pila.empty();
}


int main() {
    SetConsoleOutputCP(CP_UTF8);

string cadena="({[()]})"; // Cadena de ejemplo
    if (verificarParentesis(cadena)) {
        cout << "Los paréntesis están balanceados." << endl;
    } else {
        cout << "Los paréntesis no están balanceados." << endl;
    }

    string cadena2 = "({[(]}))";
    if (verificarParentesis(cadena2)) {
        cout << "Los paréntesis están balanceados." << endl;
    } else {
        cout << "Los paréntesis no están balanceados." << endl;
    }
    return 0;

}