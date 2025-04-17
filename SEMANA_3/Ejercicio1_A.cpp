#include <iostream>
using namespace std;

// forma 1
class Item {
    friend class Pj;
    string nombre;
    int punto; // los puntos que dara
public:
    Item(string name, int punt) : nombre(name), punto(punt) {};
};

// forma 2
class Arma { // cuando es protected
    friend class Pj;
protected:
    string Ataque;
    int punto;
public:
    Arma() {}
    Arma(string name, int punt) : Ataque(name), punto(punt) {};
};

class Hacha : public Arma {
public:
    Hacha() {
        Ataque = "Hacha";
        punto = 10;
    }
};

class Pj {
    friend ostream& operator<<(ostream& os, const Pj& pj);
protected:
    string nombre;
    string raza;
    int vida;
    int ataque;

public:
    Pj(string name, string raz, int vid, int atac) : nombre(name), raza(raz), vida(vid), ataque(atac) {};

    void curar(const Item& item) {
        cout << "Curando a " << nombre << " con " << item.nombre;
        cout << " + " << item.punto << " puntos" << endl;
        vida += item.punto; // Se añade vida con los puntos del item
    }

    void Atacar(const Arma& armita, Pj& pj) { // Lo que atacaré, la arma que quiero, y a dónde
        pj.vida -= armita.punto + this->ataque;
        cout << nombre << " ataca a " << pj.nombre << " con " << armita.Ataque << " y hace " << armita.punto + this->ataque << " de daño." << endl;
    }
};

class Carne : public Item {
public:
    Carne() : Item("Carne", 10) {};
};

class Agua : public Item {
public:
    Agua() : Item("Agua", 5) {}; // El constructor debe inicializar los valores correctos
};

class Magia : public Item {
public:
    Magia() : Item("Magia", 15) {}; // El constructor debe inicializar los valores correctos
};

ostream& operator<<(ostream& os, const Pj& pj) {
    os << "--------------------------------------------" << endl;
    os << "Nombre : " << pj.nombre << endl;
    os << "Raza : " << pj.raza << endl;
    os << "Vida : " << pj.vida << endl;
    os << "Ataque : " << pj.ataque << endl;
    return os; // Se debe retornar el flujo os
}

int main() {
    Pj pj1("Orgrim", "Orco", 100, 20); // Se cura con Carne
    Pj pj2("Legolas", "Elfo", 60, 35); // Se cura con Magia
    Pj pj3("Aragorn", "Humano", 80, 25); // Se cura con Agua
    Item Item1("Carne", 10);
    Carne carne;

    // Se curan los jugadores
    pj1.curar(Item1);
    pj1.curar(carne);

    // Ataques
    Hacha hacha;
    pj1.Atacar(hacha, pj2); // Orgrim ataca a Legolas con hacha

    // Mostrar la información del jugador
    cout << pj1;
    cout << pj2;

    return 0;
}
