#include <iostream>
using namespace std;

// Hybrid inheritance
// A -> B
// A -> C
// D -> C

class A {
    public:
        void func1() {
            cout << "Inside function 1" << endl;
        }
};

class B: public A {
    public:
        void func2() {
            cout << "Inside function 2" << endl;
        }
};

class D {
    public:
        void func3() {
            cout << "Inside function 3" << endl;
        }
};

class C: public A, public D {
    public:
        void func4() {
            cout << "Inside function 4" << endl;
        }
};

int main() {
    
    A objA;
    objA.func1();

    B objB;
    objB.func1();
    objB.func2();

    C objC;
    objC.func1();
    objC.func3();
    objC.func4();

    D objD;
    objD.func3();
    
    return 0;
}