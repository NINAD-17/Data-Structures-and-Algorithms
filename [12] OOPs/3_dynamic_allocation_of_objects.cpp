#include <iostream>
using namespace std;

class Hero {
    // Properties
    private:
        int health;
    
    public:
        char level;

        void print() {
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

    // Static allocation
    Hero ironman;
    ironman.setHealth(100);
    ironman.setLevel('A');
    cout << "Health of ironman is " << ironman.getHealth() << endl;
    cout << "Level of ironman is " << ironman.level << endl;

    // Dynamic allocation
    Hero *thor = new Hero;
    thor->setHealth(95);
    thor->level = 'B'; // Here, I've not used setLevel() because if you notice, level has public access modifier.

    cout << "Health of thor is " << (*thor).getHealth() << endl;
    cout << "Level of thor is " << (*thor).level << endl; // Here, thor contains address. That's why if we want to access level of thor then we need to 1st dereference it by adding parenthesis and * operator.

    // Alternative to access dynamically allocated objects
    cout << "Health of thor is " << thor -> getHealth() << endl;
    cout << "Health of thor is " << thor -> level << endl;

    return 0;
}