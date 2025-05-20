#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm> // para sort
using namespace std;

bool algoritmo1(const vector<int>& S) {
    int n = S.size();
    int i=0, j=n-1;
    while(i != j) {
        if (S[i] + S[j] == 10)
            return true;
        else if (S[i] + S[j] > 10)
            j--;
        else
            i++;
    }
    return false;
}

bool algoritmo2(const vector<int>& S) {
    int n = S.size();
    unordered_set<int> C;
    for(int i=0; i<n; i++) {
        if (C.find(10 - S[i]) != C.end())
            return true;
        else
            C.insert(S[i]);
    }
    return false;
}

int main() {
    vector<int> S1 = {9,4,2,3,5,1,0}; // No ordenado
    vector<int> S2 = S1;
    sort(S2.begin(), S2.end());       // Ahora ordenado para algoritmo1

    cout << "algoritmo2 con S1 (no ordenado): " << algoritmo2(S1) << endl;
    cout << "algoritmo1 con S2 (ordenado): " << algoritmo1(S2) << endl;

    vector<int> S3 = {1, 2, 3, 4};  // No tiene suma 10
    vector<int> S4 = S3;
    sort(S4.begin(), S4.end());

    cout << "algoritmo2 con S3 (no ordenado): " << algoritmo2(S3) << endl;
    cout << "algoritmo1 con S4 (ordenado): " << algoritmo1(S4) << endl;

    return 0;
}

/*====================TEORIA====================

* unordered_set<int>
// Contenedor que almacena elementos únicos sin orden específico.
// Permite búsqueda rápida (promedio O(1)) para ver si un elemento existe.
// Usado aquí para buscar si el complemento (10 - x) ya fue visto.

* Algoritmo de dos punteros (algoritmo1)
// Técnica que usa dos índices, uno al inicio y otro al final de un vector ordenado.
// Mueve los índices hacia el centro para buscar pares que cumplen una condición (suma 10).
// Es eficiente (O(n)) pero requiere que el vector esté ordenado.

* sort()
// Función de la STL que ordena un vector o arreglo en orden ascendente.
// Necesario para que algoritmo1 funcione correctamente.

* Diferencia clave entre algoritmo1 y algoritmo2:
// algoritmo1 necesita vector ordenado y usa dos punteros para encontrar suma 10.
// algoritmo2 no necesita orden, usa unordered_set para buscar complementos rápidamente.

================================================*/
