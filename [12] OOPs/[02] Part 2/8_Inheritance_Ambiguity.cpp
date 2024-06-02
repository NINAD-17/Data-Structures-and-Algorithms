#include <iostream>
using namespace std;

// Inheritance Ambiguity means if one class is inheritate from 2 parents and both 
// parents have a function with same name then there will be a confusion while calling those functions.
// So we use scope resolution operator.

class A {
    public:
        void func() {
            cout << "Inside function 1" << endl;
        }
};

class B {
    public:
        void func() {
            cout << "Inside function 2" << endl;
        }
};

class C: public A, public B {
    public: 
        void func3() {
            cout << "Inside function 3" << endl;
        }
};


int main() {
    
    C objectC;

    // objectC.func(); // Ambiguous // As it don't know which function to call
    objectC.A::func(); // Calling func from A class
    objectC.B::func(); // Calling func from B class
    
    return 0;
}