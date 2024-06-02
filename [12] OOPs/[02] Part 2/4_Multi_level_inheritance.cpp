#include <iostream>
using namespace std;

// Multi-level
// Animal -> Dog -> German shepherd

class Animal {

    public: 
        int age;
        int weight;

        void speak() {
            cout << "Speaking" << endl;
        }
};

class Dog: public Animal {

};

class germanShepherd: public Dog {

};

int main() {
    germanShepherd g;
    g.speak();
    
    return 0;
}