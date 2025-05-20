#include <iostream>
#include <vector>
#include <thread>
using namespace std;

// Función que suma elemento a elemento dos vectores en un rango [inicio, fin)
void sumar(const vector<int>& v1, const vector<int>& v2, vector<int>& v3, int inicio, int fin) {
    for(int i = inicio; i < fin; i++) {
        v3[i] = v1[i] + v2[i];
    }
}

int main() {
    int N = 1000000;              // Tamaño de los vectores
    vector<int> A(N, 1);          // Vector A lleno de 1's
    vector<int> B(N, 2);          // Vector B lleno de 2's
    vector<int> C(N, 0);          // Vector C inicializado en 0 para guardar resultados

    int n_hilos = 2;              // Número de hilos que se van a usar

    // Crear hilo t1 para sumar la primera mitad de los vectores
    thread t1(sumar, cref(A), cref(B), ref(C), 0, N / 2);
    // Crear hilo t2 para sumar la segunda mitad de los vectores
    thread t2(sumar, cref(A), cref(B), ref(C), N / 2, N);

    // Esperar que ambos hilos terminen antes de continuar
    t1.join();
    t2.join();

    // Validar resultados: verificar que cada elemento sea 3 (1+2)
    for(int i = 0; i < N; i++) {
        if (C[i] != 3) {
            cout << "Error en posición " << i << endl;
            break;
        }
    }
    cout << "Suma vectorial completada correctamente." << endl;

    return 0;
}

/*====================TEORIA====================

* std::thread
// Permite ejecutar funciones en paralelo en hilos separados.
// Ejemplo: thread t(funcion, args...);

* std::ref() y std::cref()
// Usados para pasar argumentos por referencia a funciones en threads.
// cref() para pasar referencias constantes (no modificar).
// ref() para pasar referencias modificables.

* División del trabajo entre hilos
// El vector se divide en segmentos para que cada hilo procese una parte.
// Evita condiciones de carrera porque cada hilo escribe en partes diferentes.

* join()
// Espera a que un hilo termine su ejecución antes de continuar en el hilo principal.

================================================*/
