
#include <iostream>
#include <vector>
#include <forward_list>

using namespace std;

// Función que muestra elementos y direcciones de memoria de un vector

void ver_direcciones(const vector<int>& v) {
    cout << "---\n";
    for (int i = 0; i < v.size(); i++) {
        cout << "v[" << i << "] = " << v[i] << ", direccion = " << &v[i] << endl;
    }
}


template<typename T>
void print(T it_begin, T it_end) {
    //It begin
    for (auto it=it_begin; it_begin != it_end; ++it_begin) {// 3 espacios, la variable iterativa y su valor inicial, cuando va
        //romperse el bucle, incremento
        cout << *it_begin <<' ' ;
    }
}
int main() {
    /*vector<int> v = {91, 32, 17, 21, 18, 20, 89, 11, 24, 10};


    v.push_back(1);  // Corregido: eliminado "x:" que era un error
    ver_direcciones(v);

    // Ejemplo adicional con insert (ya que el original estaba incompleto)
    v.insert(v.begin() + 3, 99);  // Inserta 99 en la posición 3
    ver_direcciones(v);
*/
    // Ejemplo con forward_list (lista enlazada simple)
    forward_list<int> lista = {91, 32, 17, 21, 18, 20, 89, 11, 24, 10};

    print(lista.begin(), lista.end());

    lista.push_front(1);  // Añade 1 al inicio
    print(lista.begin(), lista.end());

    auto it = lista.begin();
    it = next(it);// Avanza al segundo nodo
    lista.insert_after(it, 9);  // Inserta 9 después del segundo nodo
    print(lista.begin(), lista.end());
    lista.remove_if([](int x){return x%2==1;});// Elimina todos los impares
    print(lista.begin(), lista.end());
    return 0;
}



