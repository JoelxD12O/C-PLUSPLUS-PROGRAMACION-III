#include <iostream>
#include <map>
#include <string>
#include <cctype>  // para tolower
using namespace std;

// Función para convertir una cadena a minúsculas
void minuscula(string& s) {
    for (char& c : s)
        c = tolower(c);
}

int main() {
    string palabra;
    map<string, int> contador;

    cout << "Ingrese palabras (enter vacío para terminar):" << endl;
    while (true) {
        getline(cin, palabra);
        if (palabra.length() == 0)
            break;  // Termina si línea vacía

        minuscula(palabra);  // Convierte a minúsculas

        cout << "Palabra ingresada: <" << palabra << ">" << endl;

        if (contador.find(palabra) == contador.end())
            contador[palabra] = 1;  // Primera vez que aparece
        else
            contador[palabra]++;    // Incrementa contador
    }

    cout << "\nConteo de palabras:" << endl;
    for (auto par : contador)
        cout << par.first << " : " << par.second << " rep." << endl;

    return 0;
}


/*====================TEORIA====================
* string.length()
// Retorna la cantidad de caracteres que tiene la cadena string.
// Ejemplo: "hola".length() es 4.

* tolower(char c)
// Función que convierte un caracter a su versión minúscula.
// Ejemplo: tolower('A') devuelve 'a'.

* string.find(string s)
// Busca la primera ocurrencia de la subcadena s dentro de la cadena original.
// Retorna la posición (índice) donde inicia s, o string::npos si no se encuentra.

* map<string, int> contador;
// Estructura asociativa que almacena pares clave-valor donde:
// - la clave es una palabra (string).
// - el valor es un entero que cuenta cuántas veces aparece esa palabra.

// Ejemplo:
// contador["casa"] = 3; // la palabra "casa" aparece 3 veces

// Se usa para contar ocurrencias de palabras ingresadas y luego consultar frecuencias.
================================================*/