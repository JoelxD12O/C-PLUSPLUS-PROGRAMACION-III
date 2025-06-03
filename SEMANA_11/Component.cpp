//
// Created by user on 3/06/2025.
//
/*
 Patrón de Diseño: Composite

 Permite tratar objetos individuales y grupos de objetos de forma uniforme,
 organizándolos en una estructura jerárquica tipo árbol.

 Ventajas:
 - Facilita el manejo de estructuras complejas (como árboles).
 - No se necesita distinguir entre un objeto simple o una colección.
 - Mejora la flexibilidad y escalabilidad del código.

 Elementos principales:
 - Componente (Component): Interfaz común para hojas y compuestos.
 - Hoja (Leaf): Objeto individual sin hijos.
 - Compuesto (Composite): Objeto que puede contener otros componentes.

 Ejemplo típico: sistema de archivos, donde carpetas pueden contener archivos
 y otras carpetas, tratándolos a todos con una misma interfaz.
*/

#include <iostream> // Para entrada y salida estándar
#include <vector>   // Para usar el contenedor vector
#include <memory>   // Para usar punteros inteligentes
using namespace std;

// Definir la interfaz común para todos los componentes
class Componente {
public:
 virtual void mostrar() const = 0; // Método puro para mostrar información
 virtual ~Componente() = default;  // Destructor virtual por seguridad
};

// Clase hoja: representa un elemento individual sin hijos
class Elemento : public Componente {
private:
 string nombre; // Nombre del elemento
public:
 explicit Elemento(const std::string& nombre):nombre(nombre) {} // Constructor
 void mostrar() const override {
  cout << "- " << nombre << endl; // Muestra el nombre del elemento
 }
};

// Clase compuesta: puede contener otros componentes (hijos)
class Grupo : public Componente {
private:
 string nombre; // Nombre del grupo
 vector<shared_ptr<Componente>> elementos; // Hijos del grupo
public:
 explicit Grupo(const string& nombre) : nombre(nombre) {} // Constructor
 void agregar(shared_ptr<Componente> elemento) {
  elementos.push_back(elemento); // Agrega un componente al grupo
 }
 void mostrar() const override {
  cout << "Grupo: " << nombre << endl; // Muestra el nombre del grupo
  for (const auto& elemento : elementos) {
   cout<<"  "; elemento->mostrar(); // Muestra cada hijo (puede ser grupo o elemento)
  }
 }
};

int main() {
 // Ejemplo 1: Como está ahora
 cout << "====== Ejemplo 1 ======" << endl;
 shared_ptr<Elemento> item1 = make_shared<Elemento>("Archivo A");
 auto item2 = make_shared<Elemento>("Archivo B");
 auto carpeta = make_shared<Grupo>("Carpeta Principal");
 carpeta->agregar(item1);
 carpeta->agregar(item2);
 auto subCarpeta = make_shared<Grupo>("Subcarpeta");
 auto item3 = make_shared<Elemento>("Archivo C");
 subCarpeta->agregar(item3);
 carpeta->agregar(subCarpeta);
 carpeta->mostrar();

 // Ejemplo 2: Se crea una carpeta y se agrega dentro de la primera carpeta
 cout << "\n====== Ejemplo 2 ======" << endl;
 auto carpeta2 = make_shared<Grupo>("Carpeta 2");
 auto item4 = make_shared<Elemento>("Archivo D");
 carpeta2->agregar(item4);
 carpeta->agregar(carpeta2);
 carpeta->mostrar();

 // Ejemplo 3: Se agregan dos carpetas dentro de la principal
 cout << "\n====== Ejemplo 3 ======" << endl;
 auto carpeta3 = make_shared<Grupo>("Carpeta 3");
 auto carpeta4 = make_shared<Grupo>("Carpeta 4");
 auto item5 = make_shared<Elemento>("Archivo E");
 auto item6 = make_shared<Elemento>("Archivo F");
 carpeta3->agregar(item5);
 carpeta4->agregar(item6);
 auto carpetaPrincipal2 = make_shared<Grupo>("Carpeta Principal 2");
 carpetaPrincipal2->agregar(carpeta3);
 carpetaPrincipal2->agregar(carpeta4);
 carpetaPrincipal2->mostrar();

 return 0;
}

