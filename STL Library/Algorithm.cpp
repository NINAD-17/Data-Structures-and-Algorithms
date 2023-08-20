#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h> // For accumulate function
using namespace std;

void printVect(vector<int> v) {
    for(int value: v) 
        cout << value << " ";
    cout << endl;
}

int main() {

    vector<int> v;

    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);

    cout << "Finding 6: " << binary_search(v.begin(), v.end(), 6) << endl;
    cout << "Finding 8: " << binary_search(v.begin(), v.end(), 8) << endl;

    int a = 6, b = 8;
    cout << "Max: " << max(a, b) << "\nMin: " << min(a, b) << endl;

    swap(a, b);
    cout << "a: " << a << "\nb: " << b << endl; 

    string s = "abcd";
    reverse(s.begin(), s.end());
    cout << "Reversed String: " << s << endl;

    cout << "Before rotate: ";
    printVect(v);
    
    rotate(v.begin(), v.begin() + 1, v.end());
    cout << "After rotate: ";
    printVect(v);

    sort(v.begin(), v.end());
    cout << "Sorted Vector: ";
    printVect(v);


    // Find min and max 
    int min = *min_element(v.begin(), v.end()); // here we're using * because this function returns ptr and to get value from that ptr we need to use *
    int max = *max_element(v.begin(), v.end());
    cout << "Minimum: " << min << "\nMaximum: " << max << endl;

    // Sum
    int sum = accumulate(v.begin(), v.end(), 0); // Last value is from which num you want to start to add sum (initial sum)
    cout << "Sum: " << sum << endl;

    // Count of any element from arr/vect
    v.push_back(6);
    int ct = count(v.begin(), v.end(), 6);
    cout << "Count of 6: " << ct << endl;



    // Lambda Function -------------------------------------------------------
    // Ex. If you want to add 2 in an integer
    // [](int x){return x + 2;} is the function
    // (2) is for call
    cout << "Lamda Function -> sum: " << [](int x, int y){return x + y;}(2, 3) << endl;

    // To reuse this function, assign it to a variable
    auto sumL = [](int x, int y){return x + y;};
    cout << "Lamda Function -> sum function: " << sumL(2, 6) << endl;


    // all_of, none_of, any_of --------------------------------------------------
    // 1. all_of: it returns true, whether a condition is satisfied on each element of arr or not
    vector<int> v_l = {2, -3, 5};
    cout << "All Of: " << all_of(v_l.begin(), v_l.end(), [](int x){return x > 0;}) << endl;


    // 2. any_of
    cout << "any Of: " << any_of(v_l.begin(), v_l.end(), [](int x){return x > 0;}) << endl;

    // 3. none_of
    cout << "none Of: " << none_of(v_l.begin(), v_l.end(), [](int x){return x > 0;}) << endl;



    return 0;
}
