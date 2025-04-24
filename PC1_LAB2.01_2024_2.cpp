#include <iostream>
using namespace std;

class Personaje {
public:
    string nombre;
    int salud, ataque, defensa, mana, precision_velocida;

    Personaje(string name, int sa, int ataq, int def, int ma, int prec)
        : nombre(name), salud(sa), ataque(ataq), defensa(def), mana(ma), precision_velocida(prec) {}

    virtual void atacar(Personaje& otro) = 0;
    virtual void defenderse(Personaje& otro) = 0;
    virtual void usarHabilidad(Personaje& otro) = 0;
    virtual void Precision(Personaje& otro) = 0;
    virtual ~Personaje() {}

    string getNombre() { return nombre; }
    int getSalud() { return salud; }
    int getAtaque() { return ataque; }
    int getDefensa() { return defensa; }
    int getMana() { return mana; }
    int getPrecision() { return precision_velocida; }

    friend ostream& operator<<(ostream& os, const Personaje& p) {
        os << "---------------------------\n";
        os << "nombre: " << p.nombre << endl;
        os << "salud: " << p.salud << endl;
        os << "ataque: " << p.ataque << endl;
        os << "defensa: " << p.defensa << endl;
        os << "mana: " << p.mana << endl;
        os << "precision: " << p.precision_velocida << endl;
        return os;
    }
};

class Guerrero : public Personaje {
public:
    Guerrero(string name, int sa, int ataq, int def, int ma, int prec)
        : Personaje(name, sa, ataq, def, ma, prec) {}

    void atacar(Personaje& otro) override {
        cout << "El guerrero " << getNombre() << " ataca a " << otro.getNombre() << endl;
        cout << " + " << getAtaque() << " puntos de dano" << endl;
        otro.salud -= getAtaque();  // Se resta vida al otro personaje
        if (otro.salud < 0) otro.salud = 0;
    }

    void usarHabilidad(Personaje& otro) override {
        cout << getNombre() << " usa una habilidad de guerrero!" << endl;
    }

    void Precision(Personaje& otro) override {
        cout << "Precision de " << getNombre() << ": " << getPrecision() << endl;
    }

    void defenderse(Personaje& otro) override {
        cout << getNombre() << " se defiende contra " << otro.getNombre() << endl;
    }
};

class Mago : public Personaje {
public:
    Mago(string name, int sa, int ataq, int def, int ma, int prec)
        : Personaje(name, sa, ataq, def, ma, prec) {}

    void atacar(Personaje& otro) override {
        cout << "El mago " << getNombre() << " lanza un hechizo a " << otro.getNombre() << endl;
        cout << " + " << getAtaque() << " puntos de dano" << endl;
        otro.salud -= getAtaque();  // Se resta vida al otro personaje
        if (otro.salud < 0) otro.salud = 0;
    }

    void usarHabilidad(Personaje& otro) override {
        cout << getNombre() << " usa una habilidad magica!" << endl;
    }

    void Precision(Personaje& otro) override {
        cout << "Precision de " << getNombre() << ": " << getPrecision() << endl;
    }

    void defenderse(Personaje& otro) override {
        cout << getNombre() << " se defiende magicamente contra " << otro.getNombre() << endl;
    }
};

class Arquero : public Personaje {
public:
    Arquero(string name, int sa, int ataq, int def, int ma, int prec)
        : Personaje(name, sa, ataq, def, ma, prec) {}

    void atacar(Personaje& otro) override {
        cout << "El arquero " << getNombre() << " dispara una flecha a " << otro.getNombre() << endl;
        cout << " + " << getAtaque() << " puntos de dano" << endl;
        otro.salud -= getAtaque();  // Se resta vida al otro personaje
        if (otro.salud < 0) otro.salud = 0;
    }

    void usarHabilidad(Personaje& otro) override {
        cout << getNombre() << " usa una habilidad de arquero!" << endl;
    }

    void Precision(Personaje& otro) override {
        cout << "Precision de " << getNombre() << ": " << getPrecision() << endl;
    }

    void defenderse(Personaje& otro) override {
        cout << getNombre() << " se defiende de las flechas de " << otro.getNombre() << endl;
    }
};

int main() {
    Personaje* personaje;
    Guerrero guerrero("Thor", 100, 20, 10, 5, 15); // salud = 100, ataque = 20
    Mago mago("Merlin", 50, 15, 8, 30, 12); // salud = 50, ataque = 15
    cout << mago << endl;
    guerrero.atacar(mago);
    cout << mago << endl;
    cout << guerrero << endl;
    mago.atacar(guerrero);
    cout << guerrero << endl;

    return 0;
}
