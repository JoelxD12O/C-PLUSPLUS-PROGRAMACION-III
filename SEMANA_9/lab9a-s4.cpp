#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

mutex m;

void f(int& s) {
    int suma_parcial = 0;
    for(int i=0; i < 10000000; i++) {
        suma_parcial++;
    }
    m.lock();
    s = s + suma_parcial;
    m.unlock();
}

void sumar(const vector<int>& vec, int& suma) {
    for(int i=0; i < vec.size(); i++)
        suma += vec[i];
}
void sumarParalelo(const vector<int>& vec, int& suma, int inicio, int fin) {
    int suma_parcial = 0;
    for(int i=inicio; i < fin; i++)
        suma_parcial += vec[i];

    m.lock();
    suma += suma_parcial;
    m.unlock();
}
void compra(int& caja) {
    for(int i=0; i < 1000000; i++) {
        cout << "Comprando..." << endl;
        this_thread::sleep_for(chrono::milliseconds(rand()%1000));
        int monto = rand()%100 + 1;
        cout << "Cobrando..." << endl;
        this_thread::sleep_for(chrono::milliseconds(rand()%1000));
        m.lock();
        caja += monto;
        m.unlock();
    }
}

void venta_tickets(vector<int>& tickets) {
    while (tickets.size() > 0) {
        int num_tickets = rand()%4+1;
        this_thread::sleep_for(chrono::milliseconds(rand()%100));
        m.lock();
        if (num_tickets > tickets.size())
            num_tickets = tickets.size();
        for(int i=0; i < num_tickets; i++)
            tickets.pop_back();
        m.unlock();
    }
    cout << "Entradas agotadas!" << endl;
}
int main() {
    vector<int> vec(1000000);
    generate(vec.begin(), vec.end(), [i=1]()mutable {return i++;});
    random_shuffle(vec.begin(), vec.end());

    vector<thread> threads;
    for(int i=0; i < 10; i++) {
        threads.push_back(thread(venta_tickets, ref(vec)));
    }
    for(int i=0; i < 10; i++) {
        threads[i].join();
    }
    /*
     * Ejercicio 2
    vector<thread> vthread;
    int caja = 1000;
    for(int i=0; i < 4; i++)
        vthread.emplace_back(thread(compra, ref(caja)));

    for(int i=0; i < 4; i++)
        vthread[i].join();

    cout << "Caja : S/." << caja << endl;
    */
    /*
     * Ejercicio 1
    chrono::high_resolution_clock::time_point begin, end;

    vector<int> vec(10000000);
    generate(vec.begin(), vec.end(), [](){return rand()%10;});
    int suma = 0;
    sumar(vec, suma);
    cout << "Suma: " << suma << endl;
    suma = 0;

    begin = chrono::high_resolution_clock::now();
    int num_hilos = 8;
    vector<thread> threads;
    int N = vec.size();
    for(int i=0; i < num_hilos; i++)
        threads.emplace_back(thread(sumarParalelo, vec, ref(suma), i*N/num_hilos, (i+1)*N/num_hilos));

    for(int i=0; i < num_hilos; i++)
        threads[i].join();
    end = chrono::high_resolution_clock::now();
    cout << "Suma: " << suma << endl;

    double tiempo = chrono::duration_cast<chrono::milliseconds>(end - begin).count();
    cout << "T = " << tiempo << "ms." << endl;
    */
    /*
    int s = 0;
    thread t1(f, ref(s));
    thread t2(f, ref(s));
    t1.join();
    t2.join();

    cout << "s = "<< s << endl;
    */
    return 0;
}
