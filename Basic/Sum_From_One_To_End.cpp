#include <iostream>
using namespace std;

int main() {
    int num, ans = 0;
    cout << "Enter a number: " << endl;
    cin >> num;

    for(int i = 1; i <= num; i++) {
        int prevAns = ans;
        ans += i;
        cout << "i: " << i << "\t ans: " << ans << "\t --->\t" << i << " + " << prevAns << " = " << i + prevAns << "\n";
    }

    cout << "Total sum is " << ans << endl;
    return 0;
}