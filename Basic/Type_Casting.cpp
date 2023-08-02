#include <iostream>
using namespace std;

int main() {
    // Type Cast in CPP
    int a = 'a';
    cout << "Value of a using type casting: " << a << endl;

    char b = 98;
    cout << "Value of b using type casting: " << b << endl;

    char c = 123456;
    cout << "Value of c: " << c << endl; // Read Detailed explaination in readme.md file -> Type Casting

    int modulo = 123456 % 256;
    char d = modulo;
    cout << "12345 % 256 = " << modulo << endl;
    cout << "Character with value " << modulo << " in ASCII table: " << d << endl;

    unsigned int num = 112;
    cout << num << endl;

    // unsigned int negetiveNum = -112; // Wrong
    // cout << num << endl;
}

