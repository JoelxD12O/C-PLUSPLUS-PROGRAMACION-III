#include <iostream>
using namespace std;

class Matriz2D {
private:
    int fila, column;
    //int* apunta a una fila(una lista de enteros)
    //int** apunta a varias filas lo que permite represantar una matriz dinamica
    int **ptr;
public:
    Matriz2D(int f,int  c):fila(f),column(c) {
        ptr = new int*[fila];
        for(int i=0; i<fila; i++){
            ptr[i] = new int[column];
            for(int j=0; j<column; j++)
                ptr[i][j] = rand()%10;
        }
    }
    Matriz2D():Matriz2D(3,3){};
    Matriz2D(int f): Matriz2D(f,f){};

    void print() {
        for(int i=0; i<fila; i++) {
            for(int j=0; j<column; j++) {
                cout << ptr[i][j] << " ";
            }
            cout << endl;
        }
    }
    ~Matriz2D() {
        for (int i=0; i<fila; i++)
            delete [] ptr[i];//libera cada fila de la matriz
        delete [] ptr;//libera la lista de punteros que apuntaban a las filas
    }

};

int main() {
    Matriz2D m1(4,6);
    Matriz2D m2(4);
    Matriz2D m3;

    m1.print();
    cout << endl;
    m2.print();
    cout << endl;
    m3.print();
}