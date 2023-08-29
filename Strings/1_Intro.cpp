#include <iostream>
using namespace std;

int main() {
    char name[10];

    // take input
    cout << "Enter your name: ";
    cin >> name;

    // Add Null char in between 
    name[2] = '\0'; // Because of this output will be print only 1st two characters only.

    // print output
    cout << "Your name is " << name << endl;

    return 0;
}