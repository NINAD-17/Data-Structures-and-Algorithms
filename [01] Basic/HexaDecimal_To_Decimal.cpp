#include <iostream>
#include <typeinfo>
#include <math.h>
#include <algorithm>
using namespace std;

int convertItToNum(char ch) {
    int num[6] = {10, 11, 12, 13, 14, 15};
    return num[ch - 65];
}

int hexaDecToDecimal(string num) {
    int ans = 0, i = 0;

    while(num.length() != 0) {
        int lastNumInt;
        char lastNum = num[num.length() - 1];

        if(lastNum >= 'A')
            lastNumInt = convertItToNum(int(lastNum));
        else
            lastNumInt = lastNum - '0';

        ans += pow(16, i++) * lastNumInt;
        num.pop_back();
    }

    return ans;
}

int main() {
    string num;

    cout << "Enter a number: ";
    cin >> num;

    cout << "HexaDecimal Number " << num << " to Decimal: " << hexaDecToDecimal(num) << endl;
    return 0;
}