#include <iostream>
#include <vector>
using namespace std;

/*
struct Equipo {
    int* puntos;
    int PJ,PG,PE,PP;
    int Posicion;
    Equipo(int pj, int pg, int pe, int pp) {
        puntos = new int[pj];
        PG = pg;
        this->PJ = pj;
        this->PE = pe;
        this->PP = pp;
        for(int i = 0; i < PG; i++)
            puntos[i] = 3;
        for(int i = PG; i < PG+PE; i++)
            puntos[i] = 1;
        for(int i = PG+PE; i < PJ; i++)
            puntos[i] = 0;
    }
    // Constructor de Copia
    Equipo(const Equipo& otro):PJ(otro.PJ),PG(otro.PG),PE(otro.PE),PP(otro.PP) {
        cout << "Creando una copia!" << endl;
        puntos = otro.puntos;
    }
    Equipo(Equipo&& otro):PJ(otro.PJ),PG(otro.PG),PE(otro.PE),PP(otro.PP) {
        cout << "Llamando al constructor de movimiento!" << endl;
        puntos = otro.puntos;
        otro.PJ = 0;
        otro.PE = 0;
        otro.PP = 0;
        otro.PG = 0;
        otro.puntos = nullptr;
    }
    int calcular_puntos() {
        return PG * 3 + PE * 1;
    }
    void fechas() {
        for(int i = 0; i < PJ; i++)
            cout << puntos[i] << " ";
        cout << endl;
    }
};

int f(int x, int&& y) {
    return x + y;
}
*/

struct Dados {
    int ndados = 0;
    int* ptr = nullptr;
    Dados(int N): ndados(N), ptr(new int[N]) {
        cout << "Constructor con N=" << N << endl;
    }
    Dados(const Dados& otro) {
        cout << "Constructo de copia" << endl;
        ndados = otro.ndados;
        ptr = otro.ptr;
    }
    Dados(Dados&& otro) {
        cout << "Constructor de movimiento" << endl;
        ndados = otro.ndados;
        ptr = otro.ptr;
        otro.ndados = 0;
        otro.ptr = nullptr;
    }
    Dados& operator=(Dados&& otro) {
        delete ptr;
        ndados = otro.ndados;
        ptr = otro.ptr;
        otro.ndados = 0;
        otro.ptr = nullptr;
        return *this;
    }
    double promedio() {
        if (ndados == 0) {
            //cout << "El objeto no tiene informacion" << endl;
            return 0;
        }
        double r = 0.;
        for (int i = 0; i < ndados; i++)
            r += ptr[i];
        return r / ndados;
    }
    void lanzar() {
        for(int i=0; i<ndados; i++)
            ptr[i] = rand() % 6 + 1;
        if (promedio() > 3)
            cout << "El jugador gana con ";
        else
            cout << "El jugador pierde con ";
        cout << promedio() << endl;
    }
};

struct Foo {
    int* _num;
    Foo(int x): _num(new int(x)) {
        cout << "Clase Foo: Constructor -> " << x << endl;
    }
    Foo(const Foo& otro): _num(otro._num) {
        cout << "Clase Foo: Constructor Copia -> " << *_num << endl;
    }
    Foo(Foo&& otro): _num(otro._num) {
        otro._num = nullptr;
        cout << "Clase Foo: Constructor Movimiento -> " << *_num << endl;
    }
    ~Foo() {
        if (_num != nullptr)
            cout << "Clase Foo: Destructor -> " << *_num << endl;
        else
            cout << "Clase Foo: Destructor -> nullptr" << endl;
    }
};
void test1(){
    Foo f1(3);
}
void test2(){
    Foo f1(3);
    Foo f2(f1);
}
void test3(){
    vector<Foo> v;
    v.push_back(Foo(4));
}
void test4(){
    Foo f1(3);
    Foo f2(move(f1));
}

int main() {
    /*
    Equipo e1(10,7,2,1);
    cout << "Puntos: " << e1.calcular_puntos() << endl;
    e1.fechas();

    Equipo e2(e1); // Equipo e2(e1); Llamando al constructor de Copia
    e2.fechas();

    Equipo e3(move(e1)); // Llamando al constructor de movimiento
    e3.fechas();
    //Equipo* ptr2 = new Equipo(10,7,2,1);
    //cout << "Puntos: " << ptr2->calcular_puntos() << endl;

    int a = 2;
    int b = 3;
    cout << f(a,3) << endl;
    */
    srand(time(NULL));
    /*
     * Ejercicio 2
    int N;
    cout << "Ingrese la candidad de dados: ";
    cin >> N;
    Dados d1(N);
    d1.lanzar();
    cout << "d1.promedio(): " << d1.promedio() << endl;
    Dados d2(d1);
    cout << "d2.promedio(): " << d2.promedio() << endl;

    Dados d3(move(d1));
    cout << "d3.promedio(): " << d3.promedio() << endl;
    cout << "d1.promedio(): " << d1.promedio() << endl;


    Dados d4(5);
    d4.lanzar();
    cout << "d4.promedio(): " << d4.promedio() << endl;
    Dados d5(5);
    d5.lanzar();
    cout << "d5.promedio(): " << d5.promedio() << endl;
    d4 =move(d5);
    cout << "d4.promedio(): " << d4.promedio() << endl;
    */

    test4();
    return 0;
}
