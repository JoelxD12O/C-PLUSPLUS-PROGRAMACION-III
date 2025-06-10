//
// Created by user on 10/06/2025.
//
#include <iostream>
#include <stack>
using namespace std;

//=============================================== TRES ===============================================
class EditorTexto {
private:
    stack<string> historial;
    stack<string> futural;
    string texto;
public:

    void agregarTexto(string palabras) {
        texto += palabras;
        historial.push(texto);
    }

    string getTexto() const {
        return texto;
    }

    void deshacer() {
        futural.push(historial.top());
        historial.pop();
        texto = historial.top();
    }

    void rehacer() {
        texto = futural.top();
        futural.pop();
        historial.push(texto);
    }
};


    int main() {
        EditorTexto editor;

        editor.agregarTexto("Hola ");
        cout << editor.getTexto() << endl; // Salida: Hola

        editor.agregarTexto("Mundo ");
        editor.agregarTexto("en C++");
        cout << editor.getTexto() << endl; // Salida: Hola Mundo en C++

        editor.deshacer();
        cout << editor.getTexto() << endl; // Salida: Hola Mundo

        editor.deshacer();
        cout << editor.getTexto() << endl; // Salida: Hola

        editor.rehacer();
        cout << editor.getTexto() << endl; // Salida: Hola Mundo
        return 0;
    }

