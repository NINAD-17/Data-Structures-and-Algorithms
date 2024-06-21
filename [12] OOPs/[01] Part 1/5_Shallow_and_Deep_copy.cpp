#include <iostream>
#include <string.h>
using namespace std;

class Hero {
    // Properties
    private:
        int health;
    
    public:
        char *name;
        char level;

        // Constructor
        Hero() {
            cout << "Simple constructor called! (formerly default)" << endl;
            cout << "Address of this: " << this << endl;
            name = new char[100]; // We're allocating heap memory when object is initialized.
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

            // Making of new character array
            char *newCharArr = new char[strlen(otherHero.name) + 1]; // + 1 for null character.
            strcpy(newCharArr, otherHero.name);
            this -> name = newCharArr; // We've assigned an address of newCharArr to the pointer *name
        }

        void print() {
            cout << "--> Name: " << name << ", ";
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

        void setName(char name[]) {
            strcpy(this -> name, name);
        }
};

int main() {

    Hero captain;
    char name[20] = "Captain America";
    captain.setName(name);
    captain.setHealth(100);
    captain.setLevel('A');
    captain.print();

    // 1. For Shallow Copy -
    // comment the copy constructor written by you. So that code will use default copy constructor

    // 2. For Deep Copy -
    // Default copy constructor does the shallow copying

    Hero unknownHero(captain);
    unknownHero.print();

    strcpy(name, "Captain Cool");
    captain.setName(name);
    // As the name is a pointer, both hero objects are accessing same memory location for name.
    // Therefore, after updating captain's name it also updated unknownhero's name.

    cout << endl;
    captain.print();
    unknownHero.print();


    // ** Copy Assignment Operator **
    captain = unknownHero; // It's same as captain.health = unknownHero.health and so on...
    captain.print(); // in this captain is now updated with unknownhero


    return 0;
}