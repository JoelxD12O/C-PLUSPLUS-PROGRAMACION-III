//
// Created by joel on 8/04/2025.
//
#include <iostream>
using namespace std;

class Forma {
  friend ostream& operator<<(ostream& os, const Forma& f);

  protected:
    double area= 0;
public:
  virtual void calcularArea()=0;

};
class Cuadrado : public Forma {
private:
  double lado;
  public:
  Cuadrado(double l) : lado(l) {

  }
  void calcularArea() override {
    area = lado * lado;
  }
};

ostream& operator<<(ostream& os, const Forma& f){
  os<< f.area;
  return os;
};






//windows + L (suspender)
int main() {
  Forma* forma;
  forma = new Cuadrado(5);
  forma->calcularArea();
cout<< *forma<<endl;
}