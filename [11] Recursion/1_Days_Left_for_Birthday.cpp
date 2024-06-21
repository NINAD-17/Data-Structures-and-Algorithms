#include <iostream> 
using namespace std;

void birthdayTimer(int n) {
    // Base Case
    if(n == 0) {
        cout << "Happy Birthday!" << endl;
        return ;
    }

    if(n == 1)
        cout << n << " day left for Birthday!" << endl;
    else
        cout << n << " days left for Birthday!" << endl;

    birthdayTimer(n - 1);
}

int main() {
    int daysLeftForBirthday = 9;

    birthdayTimer(daysLeftForBirthday);

    return 0;
}