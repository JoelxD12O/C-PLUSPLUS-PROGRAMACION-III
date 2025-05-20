#include <iostream>
#include <thread>
using namespace std;

// Estructura que representa un pixel con componentes RGB
struct Pixel {
    int r, g, b;
    Pixel(int _r, int _g, int _b) : r(_r), g(_g), b(_b) {}  // Constructor con valores
    Pixel() : r(0), g(0), b(0) {}                            // Constructor por defecto
};

// Función que convierte a escala de grises un bloque de filas [inicio, fin)
void convertirParalelo(Pixel** imagen, int** result, int inicio, int fin) {
    for (int i = inicio; i < fin; i++) {
        for (int j = 0; j < 100; j++) {
            result[i][j] = (imagen[i][j].r + imagen[i][j].g + imagen[i][j].b) / 3;
        }
    }
}

int main() {
    // Reservar memoria dinámica para imagen y resultado
    Pixel** imagen = new Pixel*[100];
    int** result = new int*[100];
    for (int i = 0; i < 100; i++) {
        imagen[i] = new Pixel[100];
        result[i] = new int[100];
        // Inicializar imagen con valores RGB aleatorios
        for (int j = 0; j < 100; j++)
            imagen[i][j] = Pixel(rand() % 256, rand() % 256, rand() % 256);
    }

    // Crear dos hilos para convertir la imagen en paralelo
    thread t1(convertirParalelo, imagen, result, 0, 50);
    thread t2(convertirParalelo, imagen, result, 50, 100);

    // Esperar a que ambos hilos terminen
    t1.join();
    t2.join();

    // Mostrar un pixel aleatorio y su valor en escala de grises
    int im = rand() % 100, jm = rand() % 100;
    cout << "Pixel original[" << im << "][" << jm << "]: ("
         << imagen[im][jm].r << "," << imagen[im][jm].g << "," << imagen[im][jm].b << ")" << endl;
    cout << "Pixel gris[" << im << "][" << jm << "]: " << result[im][jm] << endl;

    // Liberar memoria dinámica
    for (int i = 0; i < 100; i++) {
        delete[] imagen[i];
        delete[] result[i];
    }
    delete[] imagen;
    delete[] result;

    return 0;
}

/*====================TEORIA====================

* Paralelización con std::thread
// Se divide la tarea en dos hilos que procesan distintas filas para acelerar el proceso.
// Cada hilo ejecuta convertirParalelo en un rango diferente.

* join()
// Sincroniza el hilo principal esperando que los hilos secundarios terminen.

* Memoria dinámica para matrices 2D
// Uso de punteros a punteros para reservar y liberar memoria en filas y columnas.

* Conversión a escala de grises
// Se promedian los canales RGB para obtener la intensidad de gris de cada pixel.

================================================*/
