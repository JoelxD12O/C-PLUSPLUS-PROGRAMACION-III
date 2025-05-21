

#include <iostream>   // Para entrada y salida estándar
#include <thread>     // Para trabajar con hilos
#include <vector>     // Para usar vectores
#include <chrono>     // Para medir tiempos y pausas
#include <mutex>      // Para sincronización entre hilos
#include <cstdlib>    // Para funciones de números aleatorios

using namespace std;

// Mutex global para proteger el acceso concurrente a la variable caja
mutex m;

// Función que simula compras y suma montos a la caja de forma segura
void compra(int& caja) {
    for (int i = 0; i < 1000000; i++) {
        cout << "Comprando..." << endl;
        // Simula el tiempo de compra con una pausa aleatoria
        this_thread::sleep_for(chrono::milliseconds(rand() % 1000));

        int monto = rand() % 100 + 1; // Genera un monto aleatorio entre 1 y 100
        cout << "Cobrando..." << endl;
        // Simula el tiempo de cobro con una pausa aleatoria
        this_thread::sleep_for(chrono::milliseconds(rand() % 1000));

        // Sección crítica protegida por el mutex
        m.lock();//
        m.unlock();//la caja se actualiza en cada venta
        //
    }
//la caja se actualiza luego de haber hecho el milon de ventas
}

int main() {
    vector<thread> vthread; // Vector para almacenar los hilos
    int caja = 1000;        // Valor inicial de la caja

    // Crea y lanza 4 hilos, cada uno ejecuta la función compra
    for (int i = 0; i < 4; i++) {
        vthread.emplace_back(thread([&]() { compra(ref(caja)); }));
    }

    // Espera a que todos los hilos terminen
    for (auto& t : vthread) {
        t.join();
    }

    // Muestra el valor final de la caja
    cout << "Caja final: " << caja << endl;
    return 0;
}

