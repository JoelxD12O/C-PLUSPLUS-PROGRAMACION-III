
#include <iostream> // Incluye la librería para entrada y salida estándar
#include <thread>   // Incluye la librería para trabajar con hilos
#include <vector>   // Incluye la librería para usar vectores
#include <algorithm>// Incluye funciones de algoritmos estándar (como generate)
#include <chrono>   // Incluye utilidades para medir tiempo
#include <mutex>    // Incluye la clase mutex para sincronización entre hilos

using namespace std; // Permite usar los nombres del espacio estándar sin el prefijo std::

mutex m; // Mutex global para proteger el acceso concurrente a la variable suma

// Función que suma todos los elementos de un vector de forma secuencial
void sumar(const vector<int>& vector, int& suma) {
    for (int i = 0; i < vector.size(); i++) { // Recorre todos los elementos del vector
        suma += vector[i]; // Suma cada elemento a la variable suma
    }
}

// Función que suma una parte del vector en paralelo
void sumarParalelo(const vector<int>& vec, int& suma, int inicio, int fin) {
    int suma_parcial = 0; // Variable local para acumular la suma parcial
    for (int i = inicio; i < fin; i++) { // Recorre el segmento asignado del vector
        suma_parcial += vec[i]; // Suma cada elemento a la suma parcial
    }

    // Sección crítica: se protege el acceso a la variable suma compartida
    lock_guard<mutex> lock(m); // Bloquea el mutex automáticamente en este bloque
    suma += suma_parcial; // Suma la suma parcial a la suma total
    // El mutex se libera automáticamente al salir del bloque
}

int main() {
    // Variables para medir el tiempo de ejecución
    chrono::time_point<chrono::high_resolution_clock> begin, end;

    vector<int> vec(10000); // Crea un vector de 10,000 elementos

    // Llena el vector con números aleatorios entre 1 y 10
    generate(vec.begin(), vec.end(), []() { return rand() % 10 + 1; });

    int suma = 0; // Variable para almacenar la suma total

    // Suma secuencial de todos los elementos del vector
    sumar(vec, suma);
    cout << "Suma secuencial: " << suma << endl;

    suma = 0; // Reinicia la suma para la suma paralela
    begin = chrono::high_resolution_clock::now(); // Marca el inicio del tiempo

    int num_hilos = 4; // Número de hilos a utilizar
    vector<thread> threads; // Vector para almacenar los hilos
    int N = vec.size(); // Tamaño del vector

    // Crea y lanza los hilos, cada uno suma una parte del vector
    for (int i = 0; i < num_hilos; i++) {
        threads.emplace_back(thread(sumarParalelo, ref(vec), ref(suma), i * N / num_hilos, (i + 1) * N / num_hilos));
    }

    // Espera a que todos los hilos terminen
    for (int i = 0; i < num_hilos; i++) {
        threads[i].join();
    }

    end = chrono::high_resolution_clock::now(); // Marca el final del tiempo
    cout << "Suma paralela: " << suma << endl;

    // Calcula y muestra el tiempo transcurrido en microsegundos
    double tiempo = chrono::duration_cast<chrono::microseconds>(end - begin).count();
    cout << "Tiempo: " << tiempo << " microsegundos" << endl;

    return 0; // Fin del programa
}
