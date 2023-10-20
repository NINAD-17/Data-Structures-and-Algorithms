#include <iostream>
using namespace std;

// Object-like Macros
#define PI 3.14

// Chain Macros
#define INSTAGRAM FOLLOWERS
#define FOLLOWERS 78

// Multi-line Macros
#define ELEMENTS 1, \
                 2, \
                 3

// Funtion-like Macros
#define AREA_Of_REC(l, b) (l * b)
#define MIN(num1, num2) ((a < b) ? a : b)

int main() {

    int rad = 5;

    // Area of circle
    double area = PI * rad * rad;

    // Area of rectangle
    double recArea = AREA_Of_REC(5, 6);

    cout << "Area of circle is " << area << endl;
    cout << "Area of rectangle is " << recArea << endl;
    cout << "The official BTS Instagram account (@bts.bighitofficial) has " << INSTAGRAM << " million followers." << endl;

    int arr[3] = { ELEMENTS };
    cout << "Array elements are ";
    for(int i = 0; i < 3; i++)
        cout << arr[i] << " ";
    cout << endl;

    int a = 18;
    int b = 76;
    cout << "Minimum value between " << a << " and " << b << " is: " << MIN(a, b) << endl;

    return 0;
}