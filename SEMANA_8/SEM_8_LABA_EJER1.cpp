//
// Created by user on 20/05/2025.
//
#include <iostream>
#include <thread>      // Para usar hilos (threads)
#include <chrono>      // Para medir tiempo y pausas
using namespace std;

// Función plantilla que recibe un valor 'a' y una referencia a 'b'.
// Simula un trabajo con retardo y luego suma 'a' a 'b'.
template<typename T>
void f(T a, T& b) {
    cout << "Iniciando hilo 't1'\n";
    this_thread::sleep_for(chrono::seconds(4)); // Pausa el hilo 4 segundos
    b = b + a;  // Modifica 'b' sumándole 'a'
    cout << "Finalizando hilo 't1'\n";
}

int main() {
    int b = 1; // Variable a modificar desde el hilo
    cout << "Iniciando hilo 't0'" << endl;
    cout << "b = " << b << endl;  // Mostrar el valor antes de ser actualizado


    // Crear un hilo 't1' que ejecuta la función 'f' con parámetros:
    // a = 3, y referencia a b para modificar su valor dentro del hilo
    thread t1(f<int>, 3, ref(b));

    // Esperar que 't1' termine antes de continuar (join)
    t1.join();

    cout << "b = " << b << endl;  // Mostrar el valor actualizado de b
    cout << "Finalizando hilo 't0'" << endl;
    return 0;
}

/*====================TEORIA====================

* std::thread
// Permite crear y manejar hilos para ejecución concurrente.
// Ejemplo: thread t(funcion, arg1, arg2);

* std::ref()
// Usado para pasar una variable por referencia a un hilo o función.
// Sin std::ref, los argumentos se pasan por valor y cambios no se reflejan afuera.
// Ejemplo: thread t(funcion, ref(var));

* this_thread::sleep_for()
// Detiene la ejecución del hilo actual por un tiempo especificado.
// Ejemplo: this_thread::sleep_for(chrono::seconds(2)); // pausa 2 segundos

* Funciones plantilla (template)
// Permiten definir funciones genéricas para diferentes tipos.
// En este código, 'f' puede operar con cualquier tipo T que soporte '+'.

================================================*/
