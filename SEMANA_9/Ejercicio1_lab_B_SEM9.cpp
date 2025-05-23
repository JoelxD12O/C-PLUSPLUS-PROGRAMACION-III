#include <iostream>
#include <vector>
#include <cmath>
#include <future>  // Para async y future

using namespace std;

// Calcula el módulo (norma euclidiana) de un vector de enteros
double modulo(const vector<int>& vec) {
    double s = 0.;
    for (int elem : vec)
        s += elem * elem;
    return sqrt(s);
}

// Suma todos los elementos de un vector
double suma(const vector<int>& vec) {
    double sum = 0.;
    for (int elem : vec)
        sum += elem;
    return sum;
}

int main() {
    // Creamos un vector de 10 millones de elementos con valor 1
    vector<int> v1(10000000, 1);

    // Calculamos el módulo de forma asíncrona
    future<double> mod = async(modulo, v1);

    // Mientras se calcula el módulo, calculamos la suma
    double sum = suma(v1);

    // Esperamos a que termine el cálculo del módulo y obtenemos el resultado
    cout << "suma / mod = " << sum / mod.get() << endl;

    return 0;
}