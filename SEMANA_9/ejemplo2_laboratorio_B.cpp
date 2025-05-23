//
// Created by user on 22/05/2025.
//
#include <iostream>
#include <future>   // Para promise y future
#include <thread>   // Para usar hilos

using namespace std;

// Una función que simula una tarea pesada
int f1() {
    int s = 0;
    for (int i = 0; i < 200000000; i++)
        s += 1;
    return s;
}

// Esta función recibe un puntero a std::promise<int> y simula una tarea
void foo(promise<int>* obj) {
    int sum = 0;
    for (int i = 0; i < 100000000; i++)
        sum += 1;

    // Envía el resultado a través del promise
    obj->set_value(sum);

    // Continúa ejecutando cosas, pero ya no afecta el valor que será "prometido"
    for (int i = 0; i < 100000000; i++)
        sum += 1;
}

int main() {
    // Creamos un objeto promise, que se usará para comunicar el resultado
    promise<int> promise_obj;

    // A partir del promise se obtiene un future que se usará para recibir el valor
    future<int> future_obj = promise_obj.get_future();

    // Lanzamos la función foo en un hilo, pasándole el promise por puntero
    thread t1(foo, &promise_obj);

    // Ejecutamos f1 en el hilo principal
    cout << "Respuesta f1 = " << f1() << endl;

    // Esperamos y obtenemos el valor enviado desde foo usando future_obj.get()
    cout << "Respuesta foo = " << future_obj.get() << endl;

    // Esperamos a que termine el hilo t1
    t1.join();

return 0;
}