#include <iostream>
#include <thread>
#include <fstream>

using namespace std;

struct Pixel {
    int r,g,b;
    Pixel(int _r,int _g, int _b) : r(_r), g(_g), b(_b) {}
    Pixel() : r(0), g(0), b(0) {}
};
void convertir(Pixel** imagen, int** result) {
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            result[i][j] = (imagen[i][j].r + imagen[i][j].g + imagen[i][j].b) / 3;
        }
    }
}
void convertirParalelo(Pixel** imagen, int** result, int inicio, int fin) {
    for(int i = inicio; i < fin; i++) {
        for(int j = 0; j < 100; j++) {
            result[i][j] = (imagen[i][j].r + imagen[i][j].g + imagen[i][j].b) / 3;
        }
    }
}

void contador_palabras(string ruta, int& cont) {
    ifstream file(ruta);
    string linea;
    getline(file, linea);
    for (char c: linea) {
        if (c == ' ')
            cont++;
    }
    cont++;
}

void descargar(string ruta) {
    clog << "Descargando...";
    this_thread::sleep_for(chrono::seconds(rand()%3+3));
    clog << "OK" << endl;
    ofstream file("descarga.txt");
    file << "Descarga completa!" << endl;
    file.close();
}

void sensorT() {
    int lectura;
    int i=0;
    ofstream file("sensorT.txt");
    while(i<100) {
        lectura = rand()%21+15;
        this_thread::sleep_for(chrono::seconds(2));
        file << "i: " << i << "\t:"<< lectura << endl;
    }
}
int main() {
    thread t1(sensorT);
    t1.detach();
    while(true) {
        this_thread::sleep_for(chrono::seconds(3));
        cout << "-------------------\n";
        ifstream file("sensorT.txt");
        string linea;
        while(getline(file, linea)) {
            cout << linea << endl;
        }
    }
    /*
    thread t1(descargar,"www.utec.com.pe/notas");
    thread t2(descargar,"www.utec.com.pe/fotos");
    thread t3(descargar,"www.utec.com.pe/video");
    t1.detach(),t2.detach(),t3.detach();

    cout << "Viendo calendario...\n";
    this_thread::sleep_for(chrono::seconds(10));
    cout << "OK" << endl;
    */
    /*
    this_thread::sleep_for(chrono::seconds(1));
    int c1=0,c2=0,c3=0;
    thread t1(contador_palabras, "archivo1.txt", ref(c1));
    thread t2(contador_palabras, "archivo2.txt", ref(c2));
    thread t3(contador_palabras, "archivo3.txt", ref(c3));
    t1.join();
    t2.join();
    t3.join();
    cout << "c1: "<< c1 << ", c2: " << c2 << ", c3: " << c3 << endl;
    */
    /*
    Pixel** imagen = new Pixel*[100];
    int** result = new int*[100];
    for (int i = 0; i < 100; i++) {
        imagen[i] = new Pixel[100];
        result[i] = new int[100];
        for (int j = 0; j < 100; j++)
            imagen[i][j] = Pixel(rand()%256,rand()%256,rand()%256);
    }

    thread t1(convertirParalelo, imagen, result,0,50);
    thread t2(convertirParalelo, imagen, result,50,100);
    t1.join();
    t2.join();
    int im=rand()%100,jm=rand()%100;
    cout << "imagen["<<im<<"]["<<jm<<"]: (" << imagen[im][jm].r <<","<<imagen[im][jm].g <<","<<imagen[im][jm].b << ")" << endl;
    cout << "result["<<im<<"]["<<jm<<"]: " << result[im][jm] << endl;
    for (int i = 0; i < 100; i++)
        delete imagen[i];
    delete imagen;
    */
    return 0;
}
