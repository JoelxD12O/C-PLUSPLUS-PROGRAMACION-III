#include <iostream>
#include <cmath>
using namespace std;


class VectorND {
    friend void print(VectorND& v);
    friend class Matriz2D;
private:
    int size;
    int *ptr;

public:
    VectorND(): size(3) {
        ptr = new int[size];//creamos un vector de 3 elementos
        for (int i=0; i<size; i++)
            ptr[i] = 0;
    }//por defecto

    //ahora cuando tiene un parametro el valor de size
    VectorND(int N): size(N) {
        ptr = new int[size];
        for (int i=0; i<size; i++)
            ptr[i] = rand() % 11-5;//esto hara que sea de -5 a 5
    }
    //esto es el modulo
    double modulo() {
        double result = 0;
        for (int i=0; i<size; i++)
            result += ptr[i] * ptr[i];
        return sqrt(result);
    }
    //destructor para liberar memoria dinamicamente
    ~VectorND() {
        delete[] ptr;
    }

};
//ahora fuera de la clase vamos a crear una funcion para imprimir
void print(VectorND & v) {
    cout<<"(";
    for (int i=0; i<v.size-1; i++)//imprime los elementos del vector separados por comas
        cout<<v.ptr[i]<<", ";//ingresa a la clase vector y itera
    cout<<v.ptr[v.size-1]<<")"<<endl;//solo imprime el ultimo elemento
}


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

    //aca agregaremos el constructor que nos piden

    Matriz2D(const VectorND& vector, int k): fila(vector.size), column(k) {
        ptr = new int*[fila];
        for(int i=0; i<fila; i++) {
            ptr[i] = new int[column];
            for(int j=0; j<column; j++) {
                ptr[i][j] = vector.ptr[i];
            }
        }
    }

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
    cout << endl;

    VectorND v1(3);
    print(v1);
    cout << endl;
    Matriz2D h1(v1,9);
    h1.print();
}