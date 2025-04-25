#include <iostream>
#include <vector>
using namespace std;

class Item {
public:
  virtual void mostrar() const = 0;
  virtual void usar() const = 0;
  virtual ~Item() {}
};

template<typename T, typename U>
class Arma : public Item {
private:
  T nombre;
  U daño;
public:
  Arma(T name, U dañ) : nombre(name), daño(dañ) {}

  void mostrar() const override {
    cout << "arma: " << nombre << endl;
    cout <<"danoo: "<<daño << endl;
  }

  void usar() const override {
    cout << "usando la arma: " << nombre << endl;
  }

  T getNombre() const {
    return nombre;
  }

  Arma operator+(const Arma& otro_arma) {
    cout << nombre << "-" << otro_arma.nombre << endl;
    return Arma(nombre + "-" + otro_arma.nombre, daño + otro_arma.daño);
  }
};

template<typename T, typename U>
class Pocion : public Item {
private:
  T tipo;
  U potencia;
public:
  Pocion(T tip, U pote) : tipo(tip), potencia(pote) {}

  void mostrar() const override {
    cout << "Pocion: " << tipo << endl;
    cout << "Potencia: " << potencia << endl;
  }

  void usar() const override {
    cout << "Usando la pocion: " << tipo << endl;
  }

  Pocion operator+(const Pocion& otro_pocion) {
    return Pocion(tipo + "-" + otro_pocion.tipo, potencia + otro_pocion.potencia);
  }

  void combinar(Pocion& otro_pocioon) {
    if (tipo == otro_pocioon.tipo)
      potencia += otro_pocioon.potencia;
    else cout << "No es posible la mezcla" << endl;
  }
};




template<typename... TiposItems>
class Inventario {
  vector<Item*> items;
  int capacidad;

public:
  Inventario(int cap = 10) : capacidad(cap) {}

  ~Inventario() {
    for (auto item : items) {
      delete item;
    }
  }

  template<typename... Args>
  void añadirItems(Args*... nuevosItems) {
    (añadirItem(nuevosItems), ...);
  }

  void añadirItem(Item* item) {
    if (items.size() < capacidad) {
      items.push_back(item);
      cout << "aniadimoss: ";
      item->mostrar();
      cout << endl;}

    else {
      cout << "Inventario colapsadoooo" << endl;
      delete item;
    }
  }

  void usar(int index) {
    if (index >= 0 && index < items.size()) {
      items[index]->usar();
    } else {
      cout << "indice fuera de rango" << endl;
    }
  }

  void eliminar(int index) {
    if (index >= 0 && index < items.size()) {
      delete items[index];
      items.erase(items.begin() + index);
    } else {
      cout << "indice fuera de rango" << endl;
    }
  }

  void reemplazar(int index, Item* item) {
    if (index >= 0 && index < items.size()) {
      delete items[index];
      items[index] = item;
    } else {
      cout << "indice fuera de rango" << endl;
      delete item;
    }
  }

  void mostrar() const {
    cout << "\n=== INVENTARIO ===" << endl;
    cout << "Capacidad: " << items.size() << "/" << capacidad << endl;
    for (int i = 0; i < items.size(); ++i) {
      cout << i + 1 << ". ";
      items[i]->mostrar();
      cout << endl;
    }
  }
};

int main() {
  cout << "---test1----" << endl;
  Arma<string, int> espada("Espada de acero", 20);
  Arma<string, int> arco("Arco largo", 15);

  Arma<string, int> nuevaArma = espada + arco;

  nuevaArma.mostrar();

  cout << "--test2---" << endl;
  Pocion<string, int> veneno("campeon", 50);
  Pocion<string, int> veneno3("campeon", 50);
  Pocion<string, int> veneno2("mayonesas_tia_veneno", 100);
  Pocion<string, int> veneno4("mayonesas_tia_veneno", 100);

  veneno.mostrar();
  veneno.combinar(veneno3);
  veneno.mostrar();

  cout << "---test3---" << endl;
  veneno.combinar(veneno2);

  cout<<"==============="<<endl;
  cout << "---inventario test---" << endl;
  Inventario<Item> inv;
  inv.añadirItems(new Arma<string, int>("Espada", 30), new Pocion<string, int>("cura", 20));
  inv.mostrar();

  inv.usar(0);
  inv.usar(1);

  cout<<"remplazamoos item"<<endl;
  inv.reemplazar(1, new Arma<string, int>("Martillo", 40));
  inv.mostrar();

  cout<<"eliminamos item"<<endl;
  inv.eliminar(0);
  inv.mostrar();

  return 0;
}
