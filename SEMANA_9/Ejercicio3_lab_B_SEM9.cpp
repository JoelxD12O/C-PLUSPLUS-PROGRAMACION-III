#include <iostream>
#include <vector>
#include <cmath>
#include <thread>
#include <future>
#include <algorithm> // para std::generate
#include <cstdlib>   // para rand

using namespace std;

// Función para calcular la media y desviación estándar
void desv_est(const vector<int>& vec, promise<double>& prom, double& sigma) {
    double media = 0.0;

    // Calcular la media
    for (int elem : vec)
        media += elem;
    media = media / vec.size();

    // Enviar la media usando la promesa
    prom.set_value(media);

    // Calcular la varianza y luego la desviación estándar
    double var = 0.0;
    for (int elem : vec)
        var += (elem - media) * (elem - media);
    var = var / vec.size();

    sigma = sqrt(var); // Guardar desviación estándar por referencia
}

int main() {
    // Crear un vector de 10,000,000 números aleatorios entre 0 y 99
    vector<int> vec(10000000);
    generate(vec.begin(), vec.end(), []() -> int { return rand() % 100; });

    // Crear una promesa y su correspondiente futuro
    promise<double> prom;
    future<double> media_fut = prom.get_future();

    double sigma; // Para guardar la desviación estándar

    // Lanzar la función en un hilo, pasando por referencia la promesa y sigma
    thread t1(desv_est, cref(vec), ref(prom), ref(sigma));

    // Obtener la media desde el future (espera a que esté lista)
    double media = media_fut.get();

    // Calcular la desviación media absoluta (DMA)
    double DMA = 0.0;
    for (int elem : vec)
        DMA += abs(elem - media);

    cout << "DMA = " << DMA / vec.size() << endl;
    cout << "Desviacion Estandar = " << sigma << endl;

    t1.join(); // Esperar a que termine el hilo

return 0;
}