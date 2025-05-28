#include <iostream>

struct Red {
    static int archivo;
    int id;
};
using namespace std;

int Red::archivo = 3;
int main() {
    Red usr1;
    Red usr2;

    cout<<usr1.archivo<<endl;
    cout<<usr2.archivo<<endl;
    usr1.archivo = 7;
    cout<<usr1.archivo<<endl;
    cout<<usr2.archivo<<endl;


    return 0;
}
