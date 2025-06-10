
#include <iostream>
#include <stack>

using namespace std;

int main() {
    // Declarar una pila de enteros
    stack<int> s;

    // Insertar elementos en la pila
    s.push(10);
    s.push(20);
    s.push(30);

    // Mostrar el elemento en la cima de la pila
    cout << s.top() << endl; // Imprime 30

    // Eliminar el elemento en la cima
    s.pop();

    // Mostrar el nuevo elemento en la cima
    cout << s.top() << endl; // Imprime 20

    return 0;
}

