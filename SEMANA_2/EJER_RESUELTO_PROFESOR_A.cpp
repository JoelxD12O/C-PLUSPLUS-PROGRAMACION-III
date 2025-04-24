#include <iostream>
#include <vector>
using namespace std;
class Pj {
    friend ostream& operator<<(ostream& os, const Pj& pj);
    string nombre, raza;
    int vida, ataque;
public:
    Pj(string n, string r, int v, int a): nombre(n), raza(r), vida(v), ataque(a){}
    void operator>>(Pj& pj_derecha) {
        // (*this): operando de la izquierda
        // pj_derecha: operando de la derecha
        pj_derecha.vida -= this->ataque;
    }
    void operator+(int puntos) {
        this->vida += puntos;
    }
};
ostream& operator<<(ostream& os, const Pj& pj) {
    os << "------------------------\n";
    os << "Nombre: " << pj.nombre << '\n';
    os << "Raza: " << pj.raza << '\n';
    os << "Vida: " << pj.vida << '\n';
    os << "Ataque: " << pj.ataque << '\n';
    return os;
}
class Complejo {
    double real, imag;
    friend istream& operator>>(istream& is, Complejo& comp);
    friend ostream& operator<<(ostream& os, const Complejo& comp);
public:
    Complejo(): real(0), imag(0) {}
    Complejo(double r, double i): real(r), imag(i){}
    Complejo operator+(const Complejo& comp) {
        Complejo c(this->real+comp.real, this->imag+comp.imag);
        return c;
    }
    void operator++() {
        this->real += 1;
        this->imag += 1;
    }
};
istream& operator>>(istream& is, Complejo& comp) {
    cout << "Ingrese la parte real: ";
    cin >> comp.real;
    cout << "Ingrese la parte imaginaria: ";
    cin >> comp.imag;
    return is;
}
ostream& operator<<(ostream& os, const Complejo& comp) {
    os << comp.real << '+' << comp.imag << 'j';
    return os;
}

struct Carta {
    int numero;
    char simbolo; // C:Corazones, D:Diamantes, E:Espadas, T:Trebol
    Carta(int n, char s): numero(n), simbolo(s){}
};

class Cartas {
    friend int operator<<(ostream& os, const Cartas& C);
    vector<Carta> cartas;
    void desordenar() {
        int size = cartas.size();
        for(int i=0; i<size; i++)
            swap(cartas[i], cartas[rand()%size]);
    }
public:
    Cartas() {
        string simbolos="CDET";
        for(char simbolo: simbolos) {
            for(int i=1; i<=13; i++)
                cartas.push_back(Carta(i,simbolo));
        }
    }
    void operator>>(int veces) {
        for(int i=0; i<veces; i++)
            this->desordenar();
    }
};

int operator<<(ostream& os, const Cartas& C) {
    Carta c1 = C.cartas[0];
    Carta c2 = C.cartas[1];
    Carta c3 = C.cartas[2];

    // Los tres numeros son iguales
    cout << "Puntos: ";
    if (c1.numero == c2.numero and c2.numero == c3.numero)
        return 2;

    // Los tres simbolos son iguales
    if (c1.simbolo == c2.simbolo and c2.simbolo == c3.simbolo)
        return 1;
    if (c1.numero == c2.numero)
        return 1;
    else {
        if (c1.numero == c3.numero)
            return 1;
        else {
            if (c2.numero == c3.numero)
                return 1;
        }
    }
}
int main() {
    /*
    * Ejercicio 1
    // Crear personajes (nombre, raza, vida, ataque)
    Pj orco("Orgrim", "Orco", 100, 20);
    Pj humano("Humano","Humano", 80, 18);
    Pj elfo("Elfo", "Elfo", 70, 30);
    // Ataque de orco a humano
    orco >> humano;
    // Recuperar vida de elfo
    elfo + 10;
    cout << humano << orco << elfo;
    */
    /*
     * Ejercicio 2
    Complejo complejo1(1,2);
    Complejo complejo2(3,4);
    Complejo complejo3;
    cin >> complejo3;
    Complejo complejo4 = (complejo1+complejo2);
    cout << "complejo1 = " << complejo1 << endl;
    cout << "complejo2 = " << complejo2 << endl;
    cout << "complejo3 = " << complejo3 << endl;
    cout << "complejo4 = " << complejo4 << endl;
    ++complejo1;
    cout << "complejo1 = " << complejo1 << endl;
    */
    srand(time(NULL));
    Cartas cartas;

    int barajar;
    cout << "Barajar? (> 1): ";
    cin >> barajar;

    if (barajar > 1){
        cartas >> barajar;
        cout << cartas;
    }

    return 0;
}