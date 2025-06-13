#include <iostream>
#include <queue>
#include <string>
#include "windows.h"

using namespace std;

// Definición de la estructura Documento
struct Documento {
    string archivo;
    Documento(const string& _archivo)
        : archivo(_archivo) {}
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    // Paso 1: Crear una cola de impresión
    queue<Documento> colaImpresion;

    // Paso 2: Agregar algunos documentos manualmente
    colaImpresion.push(Documento("informe.pdf"));
    colaImpresion.push(Documento("anotaciones.txt"));
    colaImpresion.push(Documento("presentacion-1.ppt"));

    // Paso 3: Mostrar la cola actual (sin vaciarla)
    queue<Documento> copia = colaImpresion;
    int i = 1;
    cout << "Cola de impresión:\n";
    cout << "-------------------\n";
    while (!copia.empty()) {
        cout << i << ": " << copia.front().archivo << "\n";
        copia.pop();
        ++i;
    }
    cout << "\n";

    // Paso 4: Procesar la cola de impresión, una por una
    while (!colaImpresion.empty()) {
        cout << "Imprimiendo... " << colaImpresion.front().archivo << "\n";
        colaImpresion.pop();
    }

    cout << "\nTodas las tareas de impresión fueron procesadas.\n";
    return 0;
}
