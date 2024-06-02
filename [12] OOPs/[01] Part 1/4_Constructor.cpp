#include <iostream>
#include <string.h>
using namespace std;

class Hero {
    // Properties
    private:
        int health;
    
    public:
        char level;

        // Constructor
        Hero() {
            cout << "Simple constructor called! (formerly default)" << endl;
            cout << "Address of this: " << this << endl;
        }

        // Parameterized constructor
        Hero(int health, char level) {
            this -> health = health;
            this -> level = level;
        }

        // Writing own copy constructor
        Hero(Hero &otherHero) {
            cout << "My copy constructor called!" << endl;
            // Remember that references (&) allow direct access to the members of an object, just like regular objects. You don’t need to use the arrow operator with references.
            this -> health = otherHero.health;
            this -> level = otherHero.level;
        }

        void print() {
            cout << "Health: " << health << ", ";
            cout << "Level: " << level << endl;
        }

        int getHealth() {
            return health;
        }

        int getLevel() {
            return level;
        }

        void setHealth(int h) {
            health = h;
        }

        void setLevel(char ch) {
            level = ch;
        }
};

int main() {

    // object created statically
    Hero ironman;
    cout << "Address of ironman is " << &ironman << endl;
    ironman.print();

    // objec created dynamically
    Hero *thor = new Hero(55, 'A'); // parametarized constructor
    cout << "Address of ironman is " << thor << endl;
    thor -> print();

    // copy constructor
    Hero spiderman(87, 'A');
    
    // hulk.level = spiderman.level;
    // hulk.health = spiderman.health;
    // We can do copy mentioned as above by using below line.
    Hero hulk(spiderman);
    cout << "Printing hulk: " << endl;
    spiderman.print();
    hulk.print();
    
    return 0;
}