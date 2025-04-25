#include <iostream>
using namespace std;

template<typename T>  // Template para la clase base
class Personaje {
public:
    string nombre;
    T salud, ataque, defensa, mana, precision_velocida;

    Personaje(string name, T sa, T ataq, T def, T ma, T prec)
        : nombre(name), salud(sa), ataque(ataq), defensa(def), mana(ma), precision_velocida(prec) {}

    virtual void atacar(Personaje<T>& otro) = 0;
    virtual void defenderse(Personaje<T>& otro) = 0;
    virtual void usarHabilidad(Personaje<T>& otro) = 0;
    virtual void Precision(Personaje<T>& otro) = 0;
    virtual ~Personaje() {}

    string getNombre() { return nombre; }
    T getSalud() { return salud; }
    T getAtaque() { return ataque; }
    T getDefensa() { return defensa; }
    T getMana() { return mana; }
    T getPrecision() { return precision_velocida; }

    friend ostream& operator<<(ostream& os, const Personaje<T>& p) {
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

template<typename T>  // Guerrero ahora es un template
class Guerrero : public Personaje<T> {
public:
    Guerrero(string name, T sa, T ataq, T def, T ma, T prec)
        : Personaje<T>(name, sa, ataq, def, ma, prec) {}

    void atacar(Personaje<T>& otro) override {
        cout << "El guerrero " << this->getNombre() << " ataca a " << otro.getNombre() << endl;
        cout << " + " << this->getAtaque() << " puntos de dano" << endl;
        otro.salud -= this->getAtaque();  // Se resta vida al otro personaje
        if (otro.salud < 0) otro.salud = 0;
    }

    void usarHabilidad(Personaje<T>& otro) override {
        cout << this->getNombre() << " usa una habilidad de guerrero!" << endl;
    }

    void Precision(Personaje<T>& otro) override {
        cout << "Precision de " << this->getNombre() << ": " << this->getPrecision() << endl;
    }

    void defenderse(Personaje<T>& otro) override {
        cout << this->getNombre() << " se defiende contra " << otro.getNombre() << endl;
    }
};

template<typename T>  // Mago ahora es un template
class Mago : public Personaje<T> {
public:
    Mago(string name, T sa, T ataq, T def, T ma, T prec)
        : Personaje<T>(name, sa, ataq, def, ma, prec) {}

    void atacar(Personaje<T>& otro) override {
        cout << "El mago " << this->getNombre() << " lanza un hechizo a " << otro.getNombre() << endl;
        cout << " + " << this->getAtaque() << " puntos de dano" << endl;
        otro.salud -= this->getAtaque();  // Se resta vida al otro personaje
        if (otro.salud < 0) otro.salud = 0;
    }

    void usarHabilidad(Personaje<T>& otro) override {
        cout << this->getNombre() << " usa una habilidad magica!" << endl;
    }

    void Precision(Personaje<T>& otro) override {
        cout << "Precision de " << this->getNombre() << ": " << this->getPrecision() << endl;
    }

    void defenderse(Personaje<T>& otro) override {
        cout << this->getNombre() << " se defiende magicamente contra " << otro.getNombre() << endl;
    }
};

template<typename T>  // Arquero ahora es un template
class Arquero : public Personaje<T> {
public:
    Arquero(string name, T sa, T ataq, T def, T ma, T prec)
        : Personaje<T>(name, sa, ataq, def, ma, prec) {}

    void atacar(Personaje<T>& otro) override {
        cout << "El arquero " << this->getNombre() << " dispara una flecha a " << otro.getNombre() << endl;
        cout << " + " << this->getAtaque() << " puntos de dano" << endl;
        otro.salud -= this->getAtaque();  // Se resta vida al otro personaje
        if (otro.salud < 0) otro.salud = 0;
    }

    void usarHabilidad(Personaje<T>& otro) override {
        cout << this->getNombre() << " usa una habilidad de arquero!" << endl;
    }

    void Precision(Personaje<T>& otro) override {
        cout << "Precision de " << this->getNombre() << ": " << this->getPrecision() << endl;
    }

    void defenderse(Personaje<T>& otro) override {
        cout << this->getNombre() << " se defiende de las flechas de " << otro.getNombre() << endl;
    }
};

int main() {
    // Usando tipo int
    Guerrero<int> guerrero("Thor", 100, 20, 10, 5, 15);
    Mago<int> mago("Merlin", 50, 15, 8, 30, 12);

    cout << mago << endl;
    guerrero.atacar(mago);
    cout << mago << endl;
    cout << guerrero << endl;
    mago.atacar(guerrero);
    cout << guerrero << endl;

    return 0;
}
