#include <iostream>
#include "../External Classes/1_intro.cpp"
using namespace std;

// Class defined in same file
// class Hero {
//     // Properties
//     public:
//         // int health;
//         char level;
// };

int main() {

    // Creation of object
    Hero ironman;

    // Updating values of object members
    // ironman.health = 100;
    ironman.level = 'A';

    cout << "Size of hero: " << sizeof(ironman) << endl;
    // cout << "Health of ironman: " << ironman.health << endl;
    cout << "Level of ironman: " << ironman.level << endl;


    return 0;
}