#include <iostream>
#include <istream>
#include <cstring>
#include <algorithm>
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
    string str = "ab\0cd\0";
    char str2[10] = "ab\0cd\0";

    cout << "String: " << str << "\tChar Array: " << str2 << endl;


    /************************* String Operations *****************************/
    string fname = "Taehyung";
    string lname = "Kim";

    lname.append(" " + fname);
    cout << "Lname: " << lname << endl;

    cout << "char at pos 4: " << lname.at(4) << endl;

    if(lname.empty())
        cout << "last name is empty." << endl;
    else 
        cout << "last name is " << lname << endl;

    // find -> returns index of first letter
    cout << "find kim: " << lname.find("Tae") << endl;

    // insert
    fname.insert(3, "-");
    cout << "First name: " << fname << endl;

    // Size/ length:
    cout << "Size: " << fname.size() << endl;
    cout << "Length: " << fname.length() << endl;

    string num = "17";
    cout << stoi(num) + 1 << endl; // stoi() converts string to int

    int numStr = 17;
    cout << to_string(numStr) + "1" << endl; // To convert int to string

    // Upper lower case
    transform(fname.begin(), fname.end(), fname.begin(), ::toupper); // from algorithm file
    cout << "Uppercase fname: " << fname << endl;


    // getline(cin, str, '...') know more about delimeter char from readme.md file
    cout << "------Getline--------" << endl;
    string getStr;
    getline(cin, getStr, ','); // It only reads input till ,
    cout << getStr << endl;

    return 0;
}