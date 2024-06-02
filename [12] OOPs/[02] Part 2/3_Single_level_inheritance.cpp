#include <iostream>
using namespace std;

// Single Level
// Animal -> Dog

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

int main() {

    Dog yeontan;
    cout << "Yeontan's age: " << yeontan.age << " 😱" << endl;
    yeontan.speak();

    return 0;
}