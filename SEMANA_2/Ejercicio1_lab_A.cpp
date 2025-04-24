//
// Created by joel on 1/04/2025.
//
#include <iostream>
using namespace std;

class Pj {
  friend  ostream& operator<<(ostream& os, const Pj& pj);
private:
  string nombre;
  string raza;
  int vida;
  double ataque;
public:
  Pj(string nombre, string raza, int vida, double ataque)
       : nombre(nombre), raza(raza), vida(vida), ataque(ataque) {} // Constructor con lista de inicialización

  void operator>>(Pj& pj_derecha) {
    //(*this): operando de la izq
    //pj derecha: operando de la derecha
    pj_derecha.vida -=this->ataque;
    //orco ataca a humano
  }

  void operator+(int plus) {
    this->vida += plus;

  }
};

  ostream& operator<<(ostream& os, const Pj& pj) {
    os<<"Nombre: "<<pj.nombre<<endl;
    os<<"Raza: "<<pj.raza<<endl;
    os<<"Vida: "<<pj.vida<<endl;
    os<<"Ataque: "<<pj.ataque<<endl;
    return os;

  }

int main() {
  Pj Orco("Orgrim","orco",100,20);
  Pj Humano("Humano","Humano",80,18);
  Pj elfo("Orgrim","Elfo",100,20);

//cout<<Humano<<endl;


    Orco>>Humano;
    cout<<elfo<<endl;
    elfo + 10;
    cout<<Humano<<endl;
    cout<<elfo<<endl;

}
