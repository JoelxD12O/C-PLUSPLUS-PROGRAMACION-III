#include <iostream>
#include <future>  // Para async y future

using namespace std;

// Función recursiva clásica de Fibonacci
int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

// Función paralela de Fibonacci usando async/future
int fibPara(int n) {
    if (n <= 1)
        return n;

    // Lanza una llamada recursiva a fibPara(n-1) en un hilo asincrónico