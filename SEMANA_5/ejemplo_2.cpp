//
// Created by user on 17/05/2025.
//

#include <iostream>
#include <cmath>
using namespace std;

struct Foo {
    int _a;  // Atributo privado para almacenar un entero

    // Constructor que inicializa _a con el valor 'a'
    Foo(int a) : _a(a) {}

    // Método para mostrar el valor de _a
    void ver() {
        cout << _a << endl;
    }

    // Sobrecarga del operador () para que Foo se comporte como una "función"
    int operator()(int x) {
        // Devuelve (x - _a) elevado a la potencia x
        return pow(_a, x); // pow(base, exponente)
    }
};

int main() {

    // Creamos un objeto Foo llamado 'f' con _a = 3
    Foo f(3);

    // Mostramos el valor de _a usando el método ver()
    f.ver(); // Imprime: 3

    // Llamamos al operador () sobre el objeto f como si fuera una función
    cout << f(4) << endl;

    return 0;
}

