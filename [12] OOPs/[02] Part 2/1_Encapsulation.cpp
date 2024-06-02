#include <iostream>
using namespace std; 

class Student {

    // By default private, so don't need to explicitly write 'private:'
    private:
        string name;
        int age;
        int height;
    
    public:
        int getAge() {
            return this -> age;
        }

};

int main() {

    Student s1;
    // s1.age; // Not accessible
    cout << s1.getAge() << endl; // Accessible by getter (read only)

    return 0;
}