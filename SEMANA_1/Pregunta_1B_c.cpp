//
// Created by joel on 27/03/2025.
//

#include <iostream>
#include <vector>

using namespace std;

class Foo {
    private:
    int* _num;
    public:
    Foo(int x) {
        _num=new int(x);//creamos un entero en el heap
        cout<<"Clase Foo: Constructor-> "<<x<<endl;
    }
    //copia
    Foo(const Foo& otro){
      _num=new int(*otro._num);//crea una coia
      cout<<"Clase Foo: Constructor Copia-> "<<*_num<<endl;
    }
    //movimiento
    Foo(Foo&& otro): _num(otro._num){
      otro._num=nullptr;
      cout<<"Clase Foo: Move Constructor-> "<<*_num<<endl;

    }
    ~Foo() {
      if(_num!=nullptr)
        cout<<"Clase Foo: Destructor-> "<<*_num<<endl;
      else
        cout<<"Clase Foo: Destructor-> "<<"nullptr"<<endl;
    }
};
    void test1(){
    Foo f1(3);
}
void test2(){
    Foo f1(3);
    Foo f2(f1);
}
void test3(){
    vector<Foo> v;
    v.push_back(Foo(4));
}
void test4(){
    Foo f1(3);
    Foo f2(move(f1));//f1 se elimina es como un ctrl + x
}


int main() {
    cout << "===== Test 1 =====" << endl;
    test1();

    cout << "\n===== Test 2 =====" << endl;
    test2();

    cout << "\n===== Test 3 =====" << endl;
    test3();

    cout << "\n===== Test 4 =====" << endl;
    test4();

    return 0;
}