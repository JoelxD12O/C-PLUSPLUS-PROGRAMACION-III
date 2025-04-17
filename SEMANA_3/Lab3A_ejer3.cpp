//
// Created by joel on 10/04/2025.
//
#include <iostream>
using namespace std;
template<typename T>
struct Par {
    T x1,x2;
    Par(T _x1, T _x2) : x1(_x1), x2(_x2) {}
    T suma(){return x1+x2;}
    T resta(){return x1-x2;}
    T producto(){return x1*x2;}
    T division(){
        if(x2!=0)
            return x1/x2;
        else
            return 0;
    }

};


template<typename T>
ostream& operator<<(ostream& os, const Par<T>& p) {
    os << "( x1: " << p.x1 << " x2:  " << p.x2<<")";
    return os;
}
int main() {
    Par p1(5.3,9.3);
    cout<<"suma:"<<p1.suma()<<endl;
    cout<<"resta:"<<p1.resta()<<endl;
    cout<<"producto:"<<p1.producto()<<endl;
    cout<<"division:"<<p1.division()<<endl;
    cout<<p1<<endl;
    return 0;
}