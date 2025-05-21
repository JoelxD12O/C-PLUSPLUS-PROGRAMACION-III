#include <iostream>
#include <thread>
using namespace std;




mutex m;


void f(int& s) {
    int suma_parcial=0;
    for (int i = 0; i < 10000; i++) {suma_parcial++;}
        m.lock();//esto crea la caja
        s=s+suma_parcial;
        m.unlock();//salida
    }


int main() {
    int s=0 ;
    thread t1(f,ref(s));
    thread t2(f,ref(s));
    t1.join();
    t2.join();
    cout << "El valor final de s es: " << s << endl;
}