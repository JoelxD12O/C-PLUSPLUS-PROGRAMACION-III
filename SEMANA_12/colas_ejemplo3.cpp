#include <chrono>
#include <iostream>
#include <queue>
#include <string>
#include <ctime>
#include <thread>
#include <vector>
using namespace std;

// Representa a un cliente con DNI y nombre
struct Cliente {
    int dni;
    string nombre;

    Cliente(int _dni = 0, const string& _nombre = "")
        : dni(_dni), nombre(_nombre) {}
};

struct Cajero {
    int id;
    bool disponible;
    Cajero(int _id) : id(_id), disponible(true) {}

    void operator()(Cliente cliente) {
        disponible = false;
        cout << "Cajero: " << id << " atendiendo cliente: " << cliente.nombre << endl;
        this_thread::sleep_for(chrono::seconds(1)); // Simula atención
        disponible = true;
    }
};

class Sistema {
private:
    queue<Cliente> clientes;
    vector<Cajero> cajeros = {Cajero(1), Cajero(2), Cajero(3)};
public:
    void sacarTicket(const Cliente& cliente) {
        clientes.push(cliente);
    }

    void lista_de_espera() {
        queue<Cliente> tmp = clientes;
        int i = 1;
        cout << "Lista de espera\n";
        cout << "----------------\n";
        while (!tmp.empty()) {
            Cliente c = tmp.front();
            cout << i << ": " << c.nombre << " (DNI: " << c.dni << ")\n";
            tmp.pop();
            ++i;
        }
        if (i == 1) {
            cout << "(vacía)\n";
        }
        cout << endl;
    }

    void atender_cliente() {
        while (!clientes.empty()) {
            bool atendido = false;
            for (auto& cajero : cajeros) {
                if (cajero.disponible) {
                    Cliente c = clientes.front();
                    cajero(c);
                    clientes.pop();
                    cout << "Cliente atendido: " << c.nombre << endl;
                    atendido = true;
                    break;
                }
            }
            if (!atendido) {
                this_thread::sleep_for(chrono::milliseconds(100));
            }
        }
    }
};

int random_dni() {
    return rand() % 90000000 + 10000000;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    Sistema sistema;

    sistema.sacarTicket(Cliente(random_dni(), "Jose"));
    sistema.sacarTicket(Cliente(random_dni(), "Jonas"));
    sistema.sacarTicket(Cliente(random_dni(), "Maria"));
    sistema.sacarTicket(Cliente(random_dni(), "Flor"));
    sistema.sacarTicket(Cliente(random_dni(), "Fernanda"));

    sistema.lista_de_espera();
    sistema.atender_cliente();

    return 0;
}