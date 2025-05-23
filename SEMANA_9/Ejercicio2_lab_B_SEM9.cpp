#include <iostream>
#include <vector>
#include <cmath>
#include <thread>
#include <future>  // para std::promise y std::future

using namespace std;

// Calcula el módulo (norma euclidiana) y envía el resultado usando una promesa
void calcularModulo(const vector<int>& vec, promise<double>* prom) {
    double s = 0.;
    for (int elem : vec)
        s += elem * elem;
    double resultado = sqrt(s);

    // Enviar el resultado a través de la promesa
    prom->set_value(resultado);
}

// Calcula la suma de todos los elementos de un vector
double suma(const vector<int>& vec) {
    double sum = 0.;
    for (int elem : vec)
        sum += elem;
    return sum;
}

int main() {
    // Crear un vector con 10 millones de elementos con valor 1
    vector<int> v1(10000000, 1);

    // Crear la promesa y obtener el futuro asociado
    promise<double> promesa;
    future<double> futuro = promesa.get_future();

    // Lanzar un hilo que calcule el módulo y comunique el resultado
    thread t(calcularModulo, cref(v1), &promesa);

    // Mientras tanto, calcular la suma en el hilo principal
    double sumaTotal = suma(v1);

    // Esperar el resultado del módulo y usarlo
    double moduloResultado = futuro.get();
    cout << "suma / mod = " << sumaTotal / moduloResultado << endl;

    // Unir el hilo
    t.join();

    return 0;
}