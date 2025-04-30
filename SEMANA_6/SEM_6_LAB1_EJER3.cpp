//
// Created by alumno08 on 29/04/2025.
//

#include <iostream>
#include <forward_list>
#include <cstdlib>  // Para rand()
#include <ctime>    // Para time()
#include <cmath>
#include <iostream>
using namespace std;


void funcionxd(forward_list<int>& list, int x) {
    auto it = list.end;
    for(auto it=list.begin(); it!=list.end(); it++) {
        if(next(it)==list.end()) {
            list.insert_after(it, x);
            break;
        }

    }
};


int main() {
    forward_list<int> lista;
    srand(time(0)); // Semilla para números aleatorios

    for(int i = 0; i < 10; ++i) {
        lista.push_front(rand() % 100); // Inserta al frente (más eficiente)
    }

    funcionxd(lista, 99);

}