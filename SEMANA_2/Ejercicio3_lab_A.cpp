//
// Created by joel on 2/04/2025.
//
#include <iostream>
#include <vector>
#include <cstdlib> // Para rand()
#include <ctime>   // Para srand(time(0))
using namespace std;

struct Carta {
    int numero;
    char simbolo; // C:Corazones, D:Diamantes, E:Espadas, T:Trebol
    Carta(int n, char s): numero(n), simbolo(s){}
};

class Cartas {
    friend ostream& operator<<(ostream& os, const Cartas& C);
    vector<Carta> cartas;

    void desordenar() {
        int size = cartas.size();
        for(int i = 0; i < size; i++)
            swap(cartas[i], cartas[rand() % size]); // Mezclar cartas aleatoriamente
    }

public:
    Cartas() {
        string simbolos = "CDET";
        for(char simbolo : simbolos) {
            for(int i = 1; i <= 13; i++)
                cartas.push_back(Carta(i, simbolo));
        }
    }

    Cartas& operator>>(int veces) { // Permite encadenamiento
        for(int i = 0; i < veces; i++)
            this->desordenar();
        return *this;
    }
};

ostream& operator<<(ostream& os, const Cartas& C) {
    os << "Cartas barajadas (3 primeras cartas mostradas):\n";
    for (int i = 0; i < 3; i++) {
        os << C.cartas[i].numero << C.cartas[i].simbolo << " ";
    }
    os << endl;

    // Evaluar puntuación
    Carta c1 = C.cartas[0];
    Carta c2 = C.cartas[1];
    Carta c3 = C.cartas[2];

    int puntos = 0;
    if (c1.numero == c2.numero && c2.numero == c3.numero)
        puntos = 2;
    else if (c1.simbolo == c2.simbolo && c2.simbolo == c3.simbolo)
        puntos = 1;
    else if (c1.numero == c2.numero || c1.numero == c3.numero || c2.numero == c3.numero)
        puntos = 1;

    os << "Puntos: " << puntos << endl;
    return os;
}

int main() {
    srand(time(0)); // Semilla para números aleatorios
    int barajar;

    cout << "Ingrese cuántas veces quiere barajar (> 1): ";
    cin >> barajar;

    if (barajar > 1) {
        Cartas cartas;
        cartas >> barajar; // Barajar las cartas
        cout << cartas;    // Mostrar las primeras 3 cartas y la puntuación
    } else {
        cout << "Debe ingresar un número mayor que 1 para barajar." << endl;
    }

    return 0;
}
