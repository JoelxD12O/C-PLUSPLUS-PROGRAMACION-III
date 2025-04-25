

//sin variadic templates
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// Template para imprimir cualquier personaje
template <typename T>
void imprimirStats(T* personaje) {
    cout << *personaje;  // Usamos el operador << sobrecargado
}

// Clase base Personaje
class Personaje {
protected:
    string nombre;
    string bando;
    string clase;
    int experiencia = 0;
    int ataque = 0, defensa = 0, hechizo = 0, mana = 0, vida = 1000;
public:
    Personaje(string nom, string b, string c) : nombre(nom), bando(b), clase(c) {}
    virtual void usarHabilidadRacial() = 0;

    // Sobrecarga del operador <<
    friend ostream& operator<<(ostream& os, const Personaje& p) {
        os << "Nombre: " << p.nombre << " | Bando: " << p.bando << " | Clase: " << p.clase
           << " | Experiencia: " << p.experiencia << " | Ataque: " << p.ataque << " | Defensa: " << p.defensa
           << " | Hechizo: " << p.hechizo << " | Mana: " << p.mana << " | Vida: " << p.vida << endl;
        return os;
    }

    void explorar() {
        cout << nombre << " explora el mundo... +100 XP\n";
        experiencia += 100;
    }
    void completarMision() {
        cout << nombre << " completa una mision... +150 XP\n";
        experiencia += 150;
    }
    string getNombre() const { return nombre; }
};

// Clases derivadas
class Guerrero : public Personaje {
public:
    Guerrero(string nom, string b) : Personaje(nom, b, "Guerrero") {
        ataque = 120;
        defensa = 90;
    }
    void usarHabilidadRacial() override {
        cout << nombre << " usa su habilidad racial de ataque por 3s!\n";
        ataque += 20;
    }
};

class Mago : public Personaje {
public:
    Mago(string nom, string b) : Personaje(nom, b, "Mago") {
        hechizo = 130;
        defensa = 50;
        mana = 200;
    }
    void usarHabilidadRacial() override {
        cout << nombre << " usa su habilidad de regeneracion de mana!\n";
        mana += 50;
    }
};

// Template de clase Jugador
template <typename T>
class Jugador {
    string nombre;
    vector<T*> personajes;
public:
    Jugador(string nom) : nombre(nom) {}

    void crearPersonaje(string nom, string raza, string bando, string clase) {
        if (clase == "Guerrero") {
            personajes.push_back(new Guerrero(nom, bando));
        } else if (clase == "Mago") {
            personajes.push_back(new Mago(nom, bando));
        }
        cout << "Creado: " << nom << " (" << clase << ", " << bando << ")\n";
    }

    void mostrarPersonajes() {
        cout << "\nPersonajes de " << nombre << ":\n";
        for (auto& p : personajes)
            cout << "- " << p->getNombre() << "\n";
    }

    void explorarTodos() {
        for (auto& p : personajes) {
            p->explorar();
        }
    }

    void completarMisionesTodos() {
        for (auto& p : personajes) {
            p->completarMision();
        }
    }

    void mostrarTodosStats() {
        for (auto& p : personajes) {
            cout << *p; // Usamos el operador << sobrecargado
        }
    }

    vector<T*>& getPersonajes() {
        return personajes;
    }

    ~Jugador() {
        for (auto p : personajes) delete p;
    }
};

// Clase PNJ
class PNJ {
    string nombre;
public:
    PNJ(string nom) : nombre(nom) {}
    void asignarMision(Personaje* p) {
        cout << "\n" << nombre << " asigna una mision a " << p->getNombre() << "\n";
        p->completarMision();
    }
};

int main() {
    Jugador<Personaje> jugador("Gabriel");
    jugador.crearPersonaje("Thrall", "Orco", "Horda", "Guerrero");
    jugador.crearPersonaje("Jaina", "Humana", "Alianza", "Mago");
    jugador.crearPersonaje("luis", "vampiro", "Alianza", "Mago");


    jugador.mostrarPersonajes();

    cout << "\n--- Explorando con todos los personajes ---\n";
    jugador.explorarTodos();

    cout << "\n--- Completando misiones con todos los personajes ---\n";
    jugador.completarMisionesTodos();

    PNJ npc("Drek'Thar");
    for (auto& p : jugador.getPersonajes()) {
        npc.asignarMision(p);
    }

    cout << "\n--- Estado final de todos los personajes ---\n";
    jugador.mostrarTodosStats(); // Aquí se utiliza el operador <<

    return 0;
}
