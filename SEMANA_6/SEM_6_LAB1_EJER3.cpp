#include <iostream>
#include <forward_list>
#include <ctime>
using namespace std;

// Inserta x al final de la forward_list
void funcionxd(forward_list<int>& list, int x) {
    for (auto it = list.begin(); it != list.end(); ++it) {
        if (next(it) == list.end()) {
            list.insert_after(it, x);
            break;
        }
    }
}

int main() {
    forward_list<int> lista;
    srand(time(0));

    for (int i = 0; i < 10; ++i) {
        lista.push_front(rand() % 100);
    }

    funcionxd(lista, 99);

    // Imprimir para verificar
    for (int n : lista)
        cout << n << " ";
    cout << endl;

    return 0;
}
