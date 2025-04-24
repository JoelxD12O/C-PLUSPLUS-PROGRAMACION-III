#include <iostream>
#include <cmath>
using namespace std;

class VectorND {
    friend void print(const VectorND& v);
    friend class Matriz2D;
private:
    int size;
    int* ptr;
public:
    VectorND(): size(3) {
        ptr = new int[size];
        for(int i=0; i<size; i++)
            ptr[i] = 0;
    }
    VectorND(int N): size(N) {
        ptr = new int[size];
        for(int i=0; i<size; i++)
            ptr[i] = rand() % 11 - 5;
    }
    double modulo() {
        double r = 0;
        for(int i=0; i<size; i++)
            r += ptr[i] * ptr[i];
        return sqrt(r);
    }
    ~VectorND() {
        delete [] ptr;
    }
};

void print(const VectorND& v) {
    cout << '(';
    for(int i=0; i<v.size-1; i++)
        cout << v.ptr[i] << ',';
    cout << v.ptr[v.size-1]<< ')'<< endl;
}

class Matriz2D {
private:
    int filas, colum;
    int** ptr;
public:
    Matriz2D(const VectorND& vector, int k): filas(vector.size), colum(k) {
        ptr = new int*[filas];
        for(int i=0; i<filas; i++) {
            ptr[i] = new int[colum];
            for(int j=0; j<colum; j++) {
                ptr[i][j] = vector.ptr[i];
            }
        }
    }
    Matriz2D(): Matriz2D(3,3){}
    Matriz2D(int f): Matriz2D(f,f){}
    Matriz2D(int f, int c): filas(f), colum(c) {
        ptr = new int*[filas];
        for(int i=0; i<filas; i++) {
            ptr[i] = new int[colum];
            for(int j=0; j<colum; j++)
                ptr[i][j] = rand() % 10;
        }
    }
    void print() {
        for(int i=0; i<filas; i++) {
            for(int j=0; j<colum; j++)
                cout << ptr[i][j] << ' ';
            cout << endl;
        }
    }
    ~Matriz2D() {
        for(int i=0; i<filas; i++)
            delete [] ptr[i];
        delete [] ptr;
    }
};
int main() {
    /*
     * Ejercicio 1
    VectorND v1(4);
    cout << v1.modulo() << endl;
    print(v1);

    VectorND v2; // (0 0 0)
    print(v2);
    */
    /*
     * Ejercicio 2
    Matriz2D m1(4,7);   // [4x7]
    Matriz2D m2(5);     // [5x5]
    Matriz2D m3;        // [3x3]

    m1.print();
    m2.print();
    m3.print();
    */
    VectorND v1(3);
    print(v1);
    Matriz2D m1(v1, 7);
    m1.print();
    return 0;
}
