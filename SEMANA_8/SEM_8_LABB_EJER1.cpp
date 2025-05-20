#include <iostream>
using namespace std;

// Estructura que representa un pixel con valores RGB
struct Pixel {
    int r, g, b;
    Pixel(int _r, int _g, int _b) : r(_r), g(_g), b(_b) {} // Constructor con valores
    Pixel() : r(0), g(0), b(0) {}                           // Constructor por defecto
};

// Función que convierte una imagen RGB a escala de grises
// Recibe punteros a punteros (matrices dinámicas) de Pixels y resultado
void convertir(Pixel** imagen, int** result) {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            // Promedio de los canales RGB para escala de grises
            result[i][j] = (imagen[i][j].r + imagen[i][j].g + imagen[i][j].b) / 3;
        }
    }
}

int main() {
    // Reservar memoria dinámica para la imagen y resultado
    Pixel** imagen = new Pixel*[100];
    int** result = new int*[100];
    for (int i = 0; i < 100; i++) {
        imagen[i] = new Pixel[100];
        result[i] = new int[100];
        for (int j = 0; j < 100; j++)
            // Asignar valores RGB aleatorios para cada pixel
            imagen[i][j] = Pixel(rand() % 256, rand() % 256, rand() % 256);
    }

    // Convertir imagen a escala de grises
    convertir(imagen, result);

    // Mostrar un pixel aleatorio y su valor en escala de grises
    int im = rand() % 100, jm = rand() % 100;
    cout << "Pixel original[" << im << "][" << jm << "]: ("
         << imagen[im][jm].r << "," << imagen[im][jm].g << "," << imagen[im][jm].b << ")" << endl;
    cout << "Pixel gris[" << im << "][" << jm << "]: " << result[im][jm] << endl;

    // Liberar memoria reservada dinámicamente
    for (int i = 0; i < 100; i++) {
        delete[] imagen[i];
        delete[] result[i];
    }
    delete[] imagen;
    delete[] result;

    return 0;
}

/*====================TEORIA====================

* Pixel** y int**
// Punteros a punteros usados para manejar matrices dinámicas.
// En este caso, matrices 100x100 de pixels y enteros.

* Escala de grises
// Se calcula como el promedio de los canales rojo, verde y azul.
// Simplificación común para convertir imágenes a tonos de gris.

* Memoria dinámica
// Uso de 'new' para reservar memoria y 'delete[]' para liberar.
// Es importante liberar para evitar fugas de memoria.

* rand() % 256
// Genera números aleatorios entre 0 y 255, que corresponden a intensidad de color RGB.

================================================*/

