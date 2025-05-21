// Incluye las librerías necesarias para el programa
#include <iostream>      // Para entrada y salida estándar
#include <algorithm>     // Para funciones de algoritmos como generate y random_shuffle
#include <thread>        // Para trabajar con hilos
#include <vector>        // Para usar el contenedor vector
#include <mutex>         // Para sincronización entre hilos (aunque no se declara el mutex aquí, debería agregarse)
#include <chrono>        // Para medir tiempos y pausas

using namespace std;

// Función que simula la venta de tickets
// Recibe un vector de tickets por referencia
void venta_tickets(vector<int>& tickets) {
    // Mientras queden tickets disponibles
    while (tickets.size() > 0) {
        int num_tickets = rand()%4+1; // Selecciona aleatoriamente entre 1 y 4 tickets a vender
        this_thread::sleep_for(chrono::milliseconds(rand()%100)); // Simula el tiempo de atención

        m.lock(); // Bloquea el acceso al recurso compartido (tickets)
        if (num_tickets > tickets.size())
            num_tickets = tickets.size(); // Ajusta si quedan menos tickets que los que se quieren vender
        for(int i=0; i < num_tickets; i++)
            tickets.pop_back(); // Elimina los tickets vendidos
        m.unlock(); // Libera el recurso compartido
    }
    cout << "Entradas agotadas!" << endl; // Mensaje cuando ya no quedan tickets
}

int main() {
    vector<int> vec(1000000); // Crea un vector con 1,000,000 de tickets
    generate(vec.begin(), vec.end(), [i=1]()mutable {return i++;}); // Llena el vector con números consecutivos
    random_shuffle(vec.begin(), vec.end()); // Mezcla los tickets aleatoriamente

    vector<thread> threads; // Vector para almacenar los hilos
    // Crea y lanza 10 hilos, cada uno ejecuta la función venta_tickets
    for(int i=0; i < 10; i++) {
        threads.push_back(thread(venta_tickets, ref(vec)));
    }
    // Espera a que todos los hilos terminen
    for(int i=0; i < 10; i++) {
        threads[i].join();
    }
}