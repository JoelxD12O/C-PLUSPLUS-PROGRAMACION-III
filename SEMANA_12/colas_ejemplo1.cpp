#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    q.push(7);
    q.push(3);
    q.push(2);
    q.push(5);

    // Primera inspección
    cout << "front: " << q.front() << endl;
    cout << "back:  " << q.back()  << endl;

    // Sacar un elemento y volver a inspeccionar
    q.pop();
    cout << "front: " << q.front() << endl;
    cout << "back:  " << q.back()  << endl;

    // Insertar otro 7 y una última inspección
    q.push(7);
    cout << "front: " << q.front() << endl;
    cout << "back:  " << q.back()  << endl;

    // Copiar la cola y vaciarla imprimiendo todos sus elementos
    queue<int> q2 = q;
    cout << "----------------\n";
    while (!q2.empty()) {
        cout << q2.front() << endl;
        q2.pop();
    }

    return 0;
}
