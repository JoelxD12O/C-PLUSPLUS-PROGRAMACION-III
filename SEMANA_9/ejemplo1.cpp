//
// Created by user on 22/05/2025.
//
#include <iostream>
#include <future> // Para usar std::async y std::future
using namespace std;

// Función f1 realiza un conteo hasta 100 millones
int f1() {
    int s1 = 0;
    for (int i = 0; i < 100000000; i++)
        s1 += 1;
    return s1;
}

// Función f2 realiza un conteo hasta 200 millones
int f2() {
    int s2 = 0;
    for (int i = 0; i < 200000000; i++)
        s2 += 1;
    return s2;
}

int main() {
    // Se lanza la función f1 de manera asíncrona, devolviendo un std::future<int>
    future<int> res = async(f1);

    // Aquí se ejecuta la función f2 en el hilo principal
    cout << "Respuesta f2 = " << f2() << endl;

    // Se espera (bloquea) hasta que la tarea asíncrona de f1 termine y se obtenga el resultado
    cout << "Respuesta f1 = " << res.get() << endl;

    return 0;

}