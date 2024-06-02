#include <iostream>
using namespace std;

class Human {
    public: 
        int height;
        int weight;
        int age;

        int getAge() {
            return this -> age;
        }

        void setWeight(int weight) {
            this -> weight = weight;
        }
};

class Male: public Human {
    public:
        string colour;

        void sleep() {
            cout << "Male is sleeping 😴" << endl;
        }
};

int main() {

    Male object1;

    cout << object1.age << endl; // public - public // accessible
    cout << object1.colour << endl;
    object1.setWeight(50);
    cout << object1.weight << endl;
    object1.sleep();

    return 0;
}