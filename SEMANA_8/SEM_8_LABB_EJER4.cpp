#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <cstdlib>
using namespace std;

// Función que simula una descarga con retardo y escribe un archivo
void descargar(string ruta) {
    clog << "Descargando...";                              // Mensaje por flujo de logs
    this_thread::sleep_for(chrono::seconds(rand() % 3 + 3));  // Pausa aleatoria de 3 a 5 segundos
    clog << "OK" << endl;
    ofstream file("descarga.txt");                         // Crear archivo de salida
    file << "Descarga completa!" << endl;                  // Escribir texto en el archivo
    file.close();                                          // Cerrar archivo
}

int main() {
    descargar("www.utec.com.pe/notas");                    // Llamar función simulando descarga
    cout << "Proceso de descarga finalizado." << endl;    // Mensaje final
    return 0;
}

/*====================TEORIA====================

* this_thread::sleep_for()
// Pausa la ejecución del hilo actual por un tiempo determinado.
// Ejemplo: this_thread::sleep_for(chrono::seconds(2)); // pausa 2 segundos

* flujo clog
// Usado para mensajes de logging o errores que no deben mezclarse con salida normal (cout).

* ofstream
// Clase para escribir en archivos de texto.
// Metodo close() cierra el archivo y libera recursos.

* rand() % 3 + 3
// Genera un número aleatorio entre 3 y 5 (inclusive).

================================================*/
