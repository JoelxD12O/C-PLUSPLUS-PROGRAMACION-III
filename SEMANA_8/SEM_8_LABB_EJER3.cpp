#include <iostream>
#include <fstream>
using namespace std;

// Función que cuenta palabras en la primera línea de un archivo
void contador_palabras(string ruta, int& cont) {
    ifstream file(ruta);
    string linea;
    getline(file, linea);  // Lee la primera línea completa
    for (char c : linea) {
        if (c == ' ')       // Cuenta espacios como separadores de palabras
            cont++;
    }
    cont++;  // Se suma 1 para contar la última palabra después del último espacio
}

int main() {
    int cont = 0;
    string archivo = "archivo_ejemplo.txt"; // Nombre del archivo a procesar

    contador_palabras(archivo, cont);

    cout << "Cantidad de palabras en la primera línea: " << cont << endl;

    return 0;
}

/*====================TEORIA====================

* ifstream
// Objeto para abrir y leer archivos de texto.
// getline(file, linea) lee una línea completa del archivo.

* Conteo de palabras simple
// Cuenta palabras en una línea contando los espacios y sumando 1 para la última palabra.
// Asume que las palabras están separadas por un solo espacio.

* Paso por referencia (int& cont)
// Permite modificar la variable cont directamente desde la función.

================================================*/
