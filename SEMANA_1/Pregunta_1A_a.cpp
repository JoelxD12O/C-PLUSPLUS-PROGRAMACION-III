#include <iostream>
#include <cmath>
using namespace std;

class VectorND {
    friend void print(VectorND& v);
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
int main() {
VectorND v1;
    VectorND v2(4);
    v1.modulo();
    v2.modulo();

    print(v1);
    print(v2);

}