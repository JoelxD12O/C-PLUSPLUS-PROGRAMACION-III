#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Estructura "dato" que contiene un puntero genérico (void*) y un tipo para identificar el tipo de dato.
struct dato {
    void* ptr;  // Puntero genérico que puede apuntar a cualquier tipo de dato
    char tipo;  // Variable para almacenar el tipo del dato (C para char, I para int, D para double, B para bool)

    // Constructor para tipo 'char'
    dato(char x) : ptr(new char(x)), tipo('C') {}

    // Constructor para tipo 'int'
    dato(int x) : ptr(new int(x)), tipo('I') {}

    // Constructor para tipo 'double'
    dato(double x) : ptr(new double(x)), tipo('D') {}

    // Constructor para tipo 'bool'
    dato(bool x) : ptr(new bool(x)), tipo('B') {}

    // Sobrecarga del operador '<<' para imprimir el valor almacenado en el puntero
    friend ostream& operator<<(ostream& os, const dato& d) {
        // Verifica el tipo de dato y realiza el casteo correspondiente
        if (d.tipo == 'C') os << *(char*)d.ptr;    // Si es char, se casteará el puntero a char y se imprimirá
        else if (d.tipo == 'I') os << *(int*)d.ptr; // Si es int, se casteará el puntero a int y se imprimirá
        else if (d.tipo == 'D') os << *(double*)d.ptr; // Si es double, se casteará el puntero a double y se imprimirá
        else if (d.tipo == 'B') os << *(bool*)d.ptr; // Si es bool, se casteará el puntero a bool y se imprimirá
        return os;  // Se retorna el flujo de salida para que la impresión funcione correctamente
    }
};

// Estructura "lista" que contiene un vector de objetos "dato"
struct lista {
    vector<dato> datos; // Vector para almacenar los objetos de tipo dato

    // Función plantilla para insertar un dato en la lista (puede ser de cualquier tipo)
    template<typename T>
    void insertar(T x) {
        datos.push_back(dato(x));  // Crea un objeto "dato" con el tipo correspondiente y lo inserta en el vector
    }

    // Sobrecarga del operador [] para acceder a los elementos de la lista
    auto operator[](int indice) -> dato& {
        return datos[indice];  // Devuelve el objeto 'dato' completo
    }
};

int main() {
    // Crear una lista l1
    lista l1;
    l1.insertar('A');   // Inserta un 'char'
    l1.insertar(7);     // Inserta un 'int'
    l1.insertar(1.101); // Inserta un 'double'
    l1.insertar(true);  // Inserta un 'bool'

    // Imprimir el tercer elemento de l1 (índice 2), que es el valor de tipo 'double' (1.101)
    cout << l1[2] << endl;  // Salida esperada: 1.101

    // Crear una segunda lista l2
    lista l2;
    l2.insertar(9);    // Inserta un 'int' en l2

    // Inserta todos los elementos de l1 en l2
    for (const auto& item : l1.datos) {
        l2.insertar(item);  // Inserta cada elemento de l1 en l2
    }

    return 0;
}
