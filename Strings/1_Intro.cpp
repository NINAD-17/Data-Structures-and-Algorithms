#include <iostream>
using namespace std;

int main() {

    /***************** Character Arrays ********************/
    char name[10];

    // take input
    cout << "Enter your name: ";
    cin >> name;

    // Add Null char in between 
    name[2] = '\0'; // Because of this output will be print only 1st two characters only.

    // print output
    cout << "Your name is " << name << endl;



    /************ String **************/
    string s; 

    cout << "Enter a string: ";
    cin >> s;

    cout << "Your string is " << s << endl;
    cout << "Lenght of your string is " << s.length() << endl;



    /*************** Difference between string and character array ******************/
    string str = "HELLO";

    return 0;
}