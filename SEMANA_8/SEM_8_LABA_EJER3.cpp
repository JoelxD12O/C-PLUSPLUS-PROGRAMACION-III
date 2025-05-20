#include <iostream>
#include <thread>
#include <vector>
#include <cstdlib> // para rand
using namespace std;

// Función que suma filas de dos matrices y guarda el resultado en otra matriz
// Procesa un bloque de 'filas' comenzando en 'inicio'
void sumMPar(int** M1, int** M2, int** M3, int filas, int n, int inicio) {
    for(int i = inicio; i < inicio + filas; i++) {
        for(int j = 0; j < n; j++) {
            M3[i][j] = M1[i][j] + M2[i][j];
        }
    }
}

int main() {
    int m = 1000, n = 2000; // dimensiones de las matrices

    // Reservar memoria dinámica para matrices A, B y C
    int** A = new int*[m];
    int** B = new int*[m];
    int** C = new int*[m];
    for(int i = 0; i < m; i++) {
        A[i] = new int[n];
        B[i] = new int[n];
        C[i] = new int[n];
        for(int j = 0; j < n; j++) {
            A[i][j] = rand() % 10; // llenar con números aleatorios 0-9
            B[i][j] = rand() % 10;
        }
    }

    int n_hilos = 10; // cantidad de hilos para paralelizar
    vector<thread> hilos;

    // Lanzar hilos para sumar bloques de filas paralelamente
    for(int i = 0; i < n_hilos; i++) {
        hilos.push_back(thread(sumMPar, A, B, C, m / n_hilos, n, i * (m / n_hilos)));
    }
    // Esperar que terminen todos los hilos
    for(int i = 0; i < n_hilos; i++) {
        hilos[i].join();
    }

    // Liberar memoria dinámica
    for(int i = 0; i < m; i++) {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }
    delete[] A;
    delete[] B;
    delete[] C;

    cout << "Suma de matrices completada." << endl;
    return 0;
}

/*====================TEORIA====================

* Memoria dinámica para matrices con punteros dobles (int**)
// Se reservan arreglos de punteros para las filas,
// y luego para cada fila se reserva un arreglo de columnas.

* Paralelización con std::thread
// Se divide la matriz en bloques de filas para que cada hilo procese un bloque.
// Evita conflictos porque cada hilo trabaja en filas distintas.

* join()
// Se espera que cada hilo termine para asegurar la integridad de los datos.

================================================*/
