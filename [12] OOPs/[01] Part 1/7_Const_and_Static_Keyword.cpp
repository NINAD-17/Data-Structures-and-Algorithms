#include <iostream>
using namespace std;

class Hero {
    public: 
        int health;
        int power;
        static int timeToComplete;

        // Normal constructor
        Hero() {
            cout << "Normal constructor called!" << endl;
        }

        // Initialization list in constructor
        Hero(int health, int power) : health(health), power(power) {
            cout << "Constructor initialized health: " << health << ", power: " << power << endl;
        }

        void setHealth(int health) {
            this -> health = health;
        }

        static int random() {
            // cout << this -> health << endl; // Error: as it can't have access to non-static members.
            cout << timeToComplete << endl; // It can only access static members only.
        }

        int getHealth() {
            (this -> health)++;
            return this -> health;
        }

        void setPower(int power) {
            this -> power = power;
        }

        int getPower() const {
            // (this -> power)++; // Error: As you've defined a const member function
            return this -> power;
        }
};

// 1. Initialize the static data member
int Hero::timeToComplete = 5;
int main() {

    int num = 100;

    // --- Constant Keyword
    const int num1 = 10;
    // num1++; // Error: you can't update value of constants after declaration. And it should be declare/define at the time of initialization only.

    const int* num2 = &num1; // pointer points to a constant value
    
    int* const num3 = &num; // constant pointer points to an int
    const int* const num4 = &num1; // constant pointer points to an constant int.

    Hero captain;
    captain.setHealth(100);
    cout << "Health of captain: " << captain.getHealth() << endl; 

    // --- Initialization list in constructors
    Hero spiderman(100, 90);

    // --- Constant object creation
    const Hero thor(10, 99); // Can only be defined at initialization of object
    // thor.setHealth(100); // Error: Modification not allowed


    // --- Static Keyword
    cout << "Time to complete of hero: " << Hero::timeToComplete << endl;
    cout << "Time to complete for thor: " << thor.timeToComplete << endl; // Not Recommende: as static members belongs to class and not object.
    thor.timeToComplete = 8;
    cout << "Time to complete for thor: " << thor.timeToComplete << endl; 
    cout << "Time to complete of hero: " << Hero::timeToComplete << endl; 

    // --- Static Functions
    Hero::random();

    return 0;
}