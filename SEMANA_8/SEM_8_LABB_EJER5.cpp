#include <iostream>
#include <fstream>
#include <thread>
#include <cstdlib>
#include <chrono>
using namespace std;

// Función que simula un sensor que genera lecturas periódicas y las guarda en archivo
void sensorT() {
    int lectura;
    int i = 0;
    ofstream file("sensorT.txt");  // Archivo donde se escriben las lecturas
    while (i < 100) {
        lectura = rand() % 21 + 15; // Genera valores aleatorios entre 15 y 35
        this_thread::sleep_for(chrono::seconds(2));  // Pausa 2 segundos
        file << "i: " << i << "\t:" << lectura << endl;  // Guarda la lectura en archivo
        i++;
    }
    file.close();  // Cierra el archivo
}

int main() {
    thread t1(sensorT);  // Crear hilo para ejecutar la función sensorT
    t1.detach();         // Desvincular hilo para que corra en segundo plano

    while (true) {
        this_thread::sleep_for(chrono::seconds(3));  // Pausa 3 segundos
        cout << "-------------------\n";
        ifstream file("sensorT.txt");  // Abrir archivo para leer las lecturas
        string linea;
        while (getline(file, linea)) {
            cout << linea << endl;  // Imprime cada línea leída
        }
    }
    return 0;
}

/*====================TEORIA====================

* std::thread y detach()
// Permite ejecutar funciones en hilos separados.
// detach() permite que el hilo siga corriendo en background sin bloquear el main.

* std::ifstream y std::ofstream
// Manejo de archivos para lectura y escritura.

* this_thread::sleep_for()
// Pausa la ejecución del hilo actual durante el tiempo indicado.

* rand() % 21 + 15
// Genera números aleatorios en rango 15 a 35 inclusive.

================================================*/
