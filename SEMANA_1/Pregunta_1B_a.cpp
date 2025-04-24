//
// Created by joel on 28/03/2025.
//
//TAREA EL PROFE LO DEJO

#include <iostream>
using namespace std;

class Personaje {
private:
    int nombre,nivel,vida;
    int *pts;


public:
    Personaje(int nombre, int nivel, int vida) {
        pts=new int[nivel];//aca almacenaremos los puntos y esta en el heap
        this->nombre=nombre;
        this->nivel=nivel;
        this->vida=vida;//this es para no sobreescribir las variables locales
        //en caso tengan otro nombre en el constructor no es necesario poner "this"

        for (int i=0;i<nivel;i++) {
            pts[i]=rand()%11;
        }
        cout<<"Personaje creado! nombre: "<<nombre<<" nivel: "<<nivel<<" vida: "<<vida<<endl;

    }
    //constructor copia
    Personaje(const Personaje &otro) {
        this->nombre=otro.nombre;
        this->nivel=otro.nivel;
        this->vida=otro.vida;
        pts=new int[nivel];
        for (int i=0;i<nivel;i++) {
            pts[i]=otro.pts[i];
        }
        cout<<"Personaje copia! nombre: "<<nombre<<" nivel: "<<nivel<<" vida: "<<vida<<endl;
    }
    //constructor movimiento
    Personaje(Personaje &&otro): nombre(otro.nombre),nivel(otro.nivel),vida(otro.vida),pts(otro.pts){
        otro.nivel=0;
        otro.vida=0;
        otro.pts=nullptr;
    cout<<"Personaje movimiento nombre: "<<nombre<<" nivel: "<<nivel<<" vida: "<<vida<<endl;

    }
    ~Personaje() {
        if (pts!=nullptr) {
            cout << "Personaje eliminado! Nombre: " << nombre << endl;
        }
    }

    void Mostrarpuntos() {
        cout<<"puntos ganados por nivel"<<endl;
        if (nivel!=0)
            for (int i=0;i<nivel;i++) {
                cout<<pts[i]<<" ";
            }
        else
            cout<<"no tiene niveles"<<endl;
        cout<<endl;
    }
};
    void test1() {
        srand(time(NULL));
        Personaje p1(1,5,100);
        p1.Mostrarpuntos();

        Personaje p2(p1);
        p2.Mostrarpuntos();
    }
    void test2() {
        srand(time(NULL));
        Personaje p1(2,3,100);
        Personaje p2(move(p1));
        p2.Mostrarpuntos();
        cout<<endl;
        p1.Mostrarpuntos();

    }

int main() {
        cout<<"=======TEST 1======="<<endl;
        test1();
        cout<<endl;
        cout<<"=======TEST 2======="<<endl;
        test2();
        cout<<endl;
        return 0;
    }


