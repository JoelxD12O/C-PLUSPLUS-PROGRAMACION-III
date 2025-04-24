#include <iostream>

using namespace std;

struct Equipo {
    int *puntos;//aca esta en el heap, porque sera un array dinamico
    int PG, PJ, PE, PP;
    int Posicion;

    // Constructor
    Equipo(int pj, int pg, int pe, int pp) {
        puntos = new int[pj]; // para crear todos los partidos jugados, en un array dinamico
        PG = pg;
        this->PE = pe;// `this->PG` hace referencia al atributo de la clase
        this->PP = pp;
        this->PJ = pj;

        for (int i = 0; i < PG; i++) {
            puntos[i] = 3; // en todos esos partidos tuvo 3 puntos
        }
        for (int i = PG; i < PG + PE; i++) {
            puntos[i] = 1;
        }
        for (int i = PG + PE; i < PJ; i++) {
            puntos[i] = 0;
        }

        // Es el puntero hacia la instancia del objeto, en lugar del punto
        cout << "this: " << this << endl;
    }

    // Constructor de copia
    Equipo(const Equipo& otro) : PJ(otro.PJ), PG(otro.PG), PE(otro.PE), PP(otro.PP) {
        cout << "Creando una copia!" << endl;

        puntos = new int[PJ]; // Crear nueva memoria para evitar aliasing,crea otro arry para los puntos
        for (int i = 0; i < PJ; i++) {
            puntos[i] = otro.puntos[i]; // Copiar valores
        }
    }

    // Constructor de movimiento
    Equipo(Equipo&& otro) noexcept : PJ(otro.PJ), PG(otro.PG), PE(otro.PE), PP(otro.PP), puntos(otro.puntos) {
        cout << "Creando un movimiento!" << endl;

        otro.PJ = 0;
        otro.PG = 0;
        otro.PE = 0;
        otro.PP = 0;
        otro.puntos = nullptr; // Se limpia el puntero del objeto original
    }

    // Destructor
    ~Equipo() {
        delete[] puntos; // Liberar memoria dinámica
    }

    int calcular_puntos() {
        return PG * 3 + PE * 1;
    }
//aca literalmente lo imprime con un espacio
    void fechas() {
        for (int i = 0; i < PJ; i++) {
            cout << puntos[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Equipo e1(10, 7, 2, 1);
    cout << "&e1 = " << &e1 << endl; // la dirección del objeto
    cout << "Puntos: " << e1.calcular_puntos() << endl;
    cout<<endl;

    /////
    Equipo* ptr2 = new Equipo(10, 7, 2, 1);//crea un calse en el heap
    cout << "PUNTOS: " << ptr2->calcular_puntos() << endl;
    cout<<endl;
    delete ptr2; // Liberar memoria

    //////
    ///
    Equipo m1(10, 7, 2, 1);
    cout << "Puntos: " << m1.calcular_puntos() << endl;
    m1.fechas();
    cout<<endl;

    Equipo e2 = e1; // Llamando al constructor de copia
    e2.fechas();
    cout<<endl;

    Equipo e3 = move(e1); // Llamando al constructor de movimiento
    e3.fechas();

    cout<<endl;
    return 0;
}
/* R VALUE(&) VALOR: 7,X+1
 * L VALUE(&&) VALOR : X,Y */
