//
// Created by joel on 1/04/2025.
//
#include <iostream>
using namespace std;

class Complejo{
  double real, imaginario;
  friend ostream& operator<<(ostream& os, const Complejo& c);
  friend istream& operator>>(istream& is, Complejo& c);
  public:
    Complejo():real(0), imaginario(0){};
    Complejo(double r, double i):real(r), imaginario(i){};
    Complejo operator+(const Complejo& comp){//esto hara sumar
      Complejo c(real+comp.real, imaginario+comp.imaginario);
      return c;
    }

    void operator++(){
      this->real += 1;
      this->imaginario += 1;

    }
};
//esto es en caso nosotros querramos digitar reeal e imaginario
    istream& operator>>(istream& is, Complejo& comp){
      cout<<"Ingrese real: ";
      cin>>comp.real;
      cout<<"Ingrese imaginario: ";
      cin>>comp.imaginario;
      return is;
    };
    ostream& operator<<(ostream& os, const Complejo& comp){
      os<<"Real: "<<comp.real<<" + "<<comp.imaginario<<"i"<<endl;
      return os;
    }



int main(){
  cout<<"-------test1-------"<<endl;//aca se sumara 1 complejo 1. real y imag
  Complejo complejo1(1,2);
  cout<<"complejo1: "<<complejo1<<endl;
  ++complejo1;
  cout<<"le sumamos 1 con el operator ++"<<endl;
  cout<<"complejo1: "<<complejo1<<endl;
  cout<<endl;
  cout<<"-------test2------"<<endl;//aca sumaremos dos clases, gracias al operador+
  Complejo complejo2(1,2);
  Complejo complejo3(3,4);
  Complejo complejo4=(complejo3+complejo2);
  cout<<"complejo4: "<<complejo4<<endl;
  cout<<endl;
  cout<<"-------test3------"<<endl;
  Complejo complejo5;
  cin>>complejo5;
  cout<<"complejo5: "<<complejo5<<endl;
  cout<<"-------test4------"<<endl;
  Complejo complejo6;
  cin>>complejo6;
  Complejo complejo7;
  cin>>complejo7;
  Complejo complejo8=complejo6+complejo7;
  cout<<"complejo8: "<<complejo8<<endl;

}