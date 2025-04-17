//
// Created by joel on 27/03/2025.
//
#include <iostream>
using namespace std;

struct Dados{
  int ndados=0;
  int* ptr=nullptr;//no apunta a nda porque al inicio no sabesmos cuantos dados habra
  Dados(int N): ndados(N),ptr(new int[N]){
    cout<<"Constructor con N: "<<N<<endl;
  }
  //creamos el constructor copia
  Dados(const Dados& otro){//& es para copia
    cout<<"constructor copia: "<<endl;
    ndados=otro.ndados;
    //ptr=otro.ptr;

    // ✅ Se reserva nueva memoria para evitar que ambos objetos apunten al mismo lugar
    ptr = new int[ndados];

    // ✅ Se copian los valores manualmente
    for (int i = 0; i < ndados; i++) {
      ptr[i] = otro.ptr[i];
    }
  }
  //creamos un constructor de movimiento
  Dados(Dados&& otro){//el && es para movimiento
    cout<<"constructor de movimiento "<<endl;
    ndados=otro.ndados;
    ptr = otro.ptr;
    otro.ndados=0;
    otro.ptr=nullptr;
  }
//?????
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

int main(){
  srand(time(0));//esto hara que cambie los numeros de rand en cada run

  int N;
  cout << "Ingrese la candidad de dados: ";
  cin >> N;
  Dados d1(N);
  d1.lanzar();
  cout << "d1.promedio(): " << d1.promedio() << endl;
  //aca creamos una copia
  cout<<endl;
  Dados d2(d1);
  cout << "d2.promedio(): " << d2.promedio() << endl;
  cout<<endl;
  //aca creamos un movimiento
  Dados d3(move(d1));//movemos de d1 a d3;es decir d1 no tendria nada, y el puntero estaria apuntando a nada nullptr
  cout << "d3.promedio(): " << d3.promedio() << endl;
  cout << "d1.promedio(): " << d1.promedio() << endl;

  cout<<"----otra forma de hacer el movimiento------"<<endl;
  //otra forma de hacer el movimiento
  Dados d4(5);
  d4.lanzar();
  cout << "d4.promedio(): " << d4.promedio() << endl;
  Dados d5(5);
  d5.lanzar();
  cout << "d5.promedio(): " << d5.promedio() << endl;
  d4 =move(d5);
  cout << "d4.promedio(): " << d4.promedio() << endl;
}
