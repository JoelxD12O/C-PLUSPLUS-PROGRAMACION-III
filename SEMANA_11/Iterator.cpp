//
// Created by user on 5/06/2025.
//
// El patrón de diseño Iterator permite recorrer los elementos de una colección sin tener que
// conocer los detalles internos de cómo está implementada la colección (por ejemplo, su tipo o estructura).
// Este patrón facilita la iteración sobre los elementos de manera ordenada y uniforme.

// Aplicaciones comunes del patrón Iterator:
// 1. **Reproductor de música**: Un reproductor puede tener una lista de reproducción, y el iterador permite
//    recorrer las canciones y reproducirlas en orden sin necesidad de conocer los detalles de cómo está estructurada la lista.
//    El iterador permite avanzar canción por canción y realizar operaciones como avanzar o retroceder en la lista.
//
// 2. **Base de datos**: En consultas a bases de datos, el patrón Iterator facilita recorrer los resultados de la consulta.
//    Usando un iterador, podemos recorrer los registros de la base de datos sin necesidad de cargar todos los registros a la vez en memoria.
//    Esto es especialmente útil cuando se trabajan con grandes volúmenes de datos y se busca eficiencia.

// Implementación del patrón Iterator:
// 1. **Definir una interfaz común para el iterador**:
//    La interfaz debe incluir métodos clave que permitan recorrer la colección:
//      - `siguiente()`: Mueve al siguiente elemento de la colección.
//      - `esFinal()`: Verifica si se ha llegado al final de la colección.
//      - `obtenerElemento()`: Obtiene el elemento actual de la colección.
//
// 2. **Implementar el iterador específico para cada tipo de colección**:
//    Dependiendo del tipo de colección (por ejemplo, una lista, un vector o una base de datos), se debe implementar un iterador que
//    cumpla con la interfaz común definida anteriormente. Cada iterador deberá manejar la lógica específica de cómo recorrer ese tipo de colección.
//
// 3. **Metodo para obtener un iterador desde la colección**:
//    La colección debe proporcionar un método que devuelva una instancia del iterador adecuado para esa colección.
//    Este metodo permite a los usuarios acceder al iterador sin necesidad de conocer detalles sobre cómo se implementa la colección.

// Resumen:
// El patrón Iterator separa la lógica de iteración de la colección real, facilitando el acceso a los elementos de una colección sin tener que
// lidiar con los detalles internos, lo que proporciona una forma más flexible y reutilizable de trabajar con diferentes colecciones.

//EJERCICIO1
#include <vector>
#include <iostream>
#include "windows.h"
using namespace std;

struct Cancion {
    string titulo, autor;
    Cancion( string t,  string a) : titulo(t), autor(a) {}


};

ostream& operator<<(ostream& os, const Cancion& cancion) {
    os << cancion.titulo << " by " << cancion.autor;
    return os;
}
class Itarator {
public:
    virtual void next()=0;
    virtual bool isEnd()=0;
    virtual Cancion get()=0;
};


class IteradorAdelante: public Itarator {
private:
    vector<Cancion> db;
    int indice;
public:
    IteradorAdelante(vector<Cancion> db) : db(db), indice(0) {};
    virtual void next() override{
        indice++;
    };
    virtual bool isEnd() override {
    return indice >= db.size();
    };
    virtual Cancion get() override {
    return db[indice];
    };
};
class IteradorAdelanteInv: public Itarator {
private:
    vector<Cancion> db;
    int indice;
public:
    IteradorAdelanteInv(vector<Cancion> db) : db(db), indice(db.size()-1) {};
    virtual void next() override {
            if (indice >= 0) {
                indice--;
            } else {
                cout << "No hay más canciones." << endl;
            }
        }
    virtual bool isEnd() override {
        return indice < 0;
    };
    virtual Cancion get() override {
        return db[indice];
    }
};

class ListaDeCanciones {
    private:
    vector<Cancion> canciones;
public:
    void insertar(Cancion c) {
        canciones.push_back(c);
    }
    Itarator* inicio() {
        return new IteradorAdelante(canciones);
    }
    Itarator* inicioInv() {
        return new IteradorAdelanteInv(canciones);
    }


};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    ListaDeCanciones playlist;
    playlist.insertar(Cancion("Song 1", "Artist 1"));
    playlist.insertar(Cancion("Song 2", "Artist 2"));
    playlist.insertar(Cancion("Song 3", "Artist 3"));

    Itarator* it=playlist.inicio();
    while (!it->isEnd()) {
     cout<<" " << it->get()<<endl;
        it->next();
    }

    // Usando el iterador hacia atrás para recorrer las canciones del álbum

    Itarator* it2 = playlist.inicioInv();
    while (!it2->isEnd()) {
        cout << it2->get() << endl;
        it2->next();
    }

    cout << "Iteración hacia atras completa.\n" << endl;


    return 0;
}