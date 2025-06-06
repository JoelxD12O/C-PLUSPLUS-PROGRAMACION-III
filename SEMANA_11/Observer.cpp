//
// Created by user on 5/06/2025.
//

#include <iostream>
#include <vector>
using namespace std;

class Observer {
public:
    virtual void notificar(string historia, string usuario) = 0;
};
class Seguidor: public Observer {
private:
    string nombre;
public:
    Seguidor(string n): nombre(n) {}
    void notificar(string historia, string usuario) {
        cout << "-> " << nombre << " - historia recibida de " << usuario << ": " <<
        historia << endl;
    }
};
class Usuario { // Clase observada concreta (Usuario)
private:
    string nombre;
    vector<Observer*> observadores;
public:
    Usuario(const string& nombre) : nombre(nombre) {}
    string getNombre() const { return nombre;}
    void agregarObservador(Observer* observador)
    { observadores.push_back(observador);}
    void notificarSeguidores(const string& historia) {
        for(auto obs: observadores) {
            obs->notificar(historia, nombre);
        }
    }
};
int main() {
    // Crear usuarios y seguidores
    Usuario usuario("Usuario1");
    Seguidor seguidor1("Seguidor1");
    Seguidor seguidor2("Seguidor2");

    // Agregar seguidores al usuario
    usuario.agregarObservador(&seguidor1);
    usuario.agregarObservador(&seguidor2);

    // Publicar una nueva historia
    string nuevaHistoria = "Hoy estoy de viaje!";
    usuario.notificarSeguidores(nuevaHistoria);
}
