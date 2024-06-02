#include <iostream>
using namespace std;


class Hero {
    // Properties
    private:
        int health = 5;
    
    public:
        char level = 'A';

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

    // Creation of object
    Hero ironman;

    cout << "Health of ironman is " << ironman.getHealth() << endl;

    // Accessing object members
    ironman.setHealth(100);
    ironman.level = 'A';

    cout << "Size of hero: " << sizeof(ironman) << endl;
    cout << "Health of ironman: " << ironman.getHealth() << endl;
    cout << "Level of ironman: " << ironman.level << endl;


    return 0;
}