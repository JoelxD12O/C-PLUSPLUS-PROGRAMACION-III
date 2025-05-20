//
// Created by user on 20/05/2025.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>  // para srand, rand
#include <ctime>    // para time
using namespace std;

// Función plantilla para obtener la clave con el valor máximo (moda)
template<typename T>
auto moda(T it_begin, T it_end) {
    T it_max = it_begin;
    for(auto it = it_begin; it != it_end; ++it) {
        if (it->second > it_max->second)
            it_max = it;
    }
    return it_max->first;
}

int main() {
    srand(time(0)); // Semilla para números aleatorios

    vector<int> v(100);
    generate(v.begin(), v.end(), [](){ return rand() % 20 + 1; });  // Genera 100 números aleatorios entre 1 y 20

    for(int e : v)
        cout << e << ' ';
    cout << endl;

    unordered_map<int,int> contador;  // Mapa para contar ocurrencias de cada número
    for(int e : v)
        contador[e]++;  // Incrementa el contador para el número e

    for(auto e : contador)
        cout << e.first << " -> " << e.second << " rep." << endl;

    cout << "Moda: " << moda(contador.begin(), contador.end()) << endl;  // Imprime la moda (valor con mayor frecuencia)

    return 0;
}


/*====================TEORIA====================
*unordered_map<int,int> contador = {{5,3}, {10,7}, {2,4}};
// Aquí:
// - la clave 5 tiene valor 3 (aparece 3 veces)
// - la clave 10 tiene valor 7 (aparece 7 veces)
// - la clave 2 tiene valor 4 (aparece 4 veces)

// Al recorrer este mapa, it->first puede ser 5, 10 o 2
// it->second sería 3, 7 o 4 respectivamente
================================================*/