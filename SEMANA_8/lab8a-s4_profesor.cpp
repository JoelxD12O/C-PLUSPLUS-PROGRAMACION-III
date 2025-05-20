#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
using namespace std;

template<typename T>
void f(T a, T& b) {
    cout << "Iniciando hilo 't1'\n";
    this_thread::sleep_for(chrono::seconds(4));
    b = b + a;
    cout << "Finalizando hilo 't1'\n";
}
// Lanza un hilo (t0)

void sumar(const vector<int>& v1, const vector<int>& v2, vector<int>& v3, int inicio, int fin) {
    for(int i=inicio; i<fin; i++) {
        v3[i] = v1[i] + v2[i];
    }
}
void validar(const vector<int>& v) {
    for(int i=0; i<v.size(); i++) {
        if (v[i] != 3)
            cout << "Error! " << endl;
    }
}
void dot(const vector<int>& v1, const vector<int>& v2, int& suma) {
    for(int i=0; i<v1.size(); i++) {
        suma += v1[i] * v2[i];
    }
}
void dot_par(const vector<int>& v1, const vector<int>& v2, int& suma, int inicio, int fin) {
    for(int i=inicio; i<fin; i++) {
        suma += v1[i] * v2[i];
    }
}

void sumM(int** M1, int** M2, int** M3, int m, int n) {
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            M3[i][j] = M1[i][j] + M2[i][j];
        }
    }
}
void sumMPar(int** M1, int** M2, int** M3, int filas, int n, int inicio) {
    for(int i=inicio; i<inicio+filas; i++) {
        for(int j=0; j<n; j++)
            M3[i][j] = M1[i][j] + M2[i][j];
    }
}
int main() {
    // sumar dos matrices A y B de dimensiones mxn
    int m=1000, n=2000; // m:filas, n:columnas
    int** A = new int*[m];
    int** B = new int*[m];
    int** C = new int*[m];
    for(int i=0; i<m; i++) {
        A[i] = new int[n];
        B[i] = new int[n];
        C[i] = new int[n];
        for (int j=0; j<n; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }

    int n_hilos = thread::hardware_concurrency();
    cout << "#hilos = " << n_hilos << endl;
    n_hilos = 10;
    cout << "#hilos utilizados = " << n_hilos << endl;
    vector<thread> hilos;

    for(int i=0; i<n_hilos; i++)
        hilos.push_back(thread(sumMPar, A, B, C, m/n_hilos, n, i*(m/n_hilos)));
    for(int i=0; i<n_hilos; i++)
        hilos[i].join();

    /*
    chrono::time_point<chrono::system_clock> inicio, fin;
    inicio = chrono::system_clock::now();
    int N = 1000000;
    vector<int> A(N,1);
    vector<int> B(N,2);
    int n_hilos = 8;
    vector<int> sumas(n_hilos,0);
    vector<thread> hilos;

    for(int i=0; i<n_hilos; i++) {
        hilos.push_back(thread(dot_par, A, B, ref(sumas[i]), i*N/n_hilos, (i+1)*N/n_hilos));
    }
    for(int i=0; i<n_hilos; i++) {
        hilos[i].join();
    }
    int suma=0;
    for(int i=0; i<n_hilos; i++)
        suma += sumas[i];
    //dot(A,B,suma);

    cout << "<A.B> = " << suma << endl;
    fin = chrono::system_clock::now();
    double duracion = chrono::duration_cast<chrono::duration<double, milli>>(fin-inicio).count();
    cout << duracion << "ms"<< endl;
    */
    /*
    vector<int> C(1000000);



    thread t1(sumar,A, B, ref(C), 0, A.size()/2);
    thread t2(sumar,A, B, ref(C), A.size()/2, A.size());

    t1.join();
    t2.join();
    */


    for(int i=0; i<m; i++) {
        delete [] A[i];
        delete [] B[i];
        delete [] C[i];
    }
    delete [] A;
    delete [] B;
    delete [] C;
    //validar(C);
    /*
    int b=1;
    cout << "Iniciando hilo 't0'" << endl;
    thread t1(f<int>, 3, ref(b));



    t1.join();
    cout << "b = " << b << endl;
    cout << "Finalizando hilo 't0'" << endl;
    */
    return 0;
}
