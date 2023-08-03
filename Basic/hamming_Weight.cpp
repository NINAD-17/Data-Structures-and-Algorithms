#include <iostream>
using namespace std;

/***** Hamming Weight or Number of 1 Bits in given number *****/
//   110
// & 001
// -----
//   000
// When you specify (n & 1) then it take as 0 as prefix then 1 -> Ex. 001

// Time Complexity: O(1)
// Since n is a 32-bit unsigned integer, the while loop runs for at most 32 iterations, regardless of the value of n. Therefore, the overall time complexity of the hammingWeight function is O(1).
// since n is a 32-bit unsigned integer, it has at most 32 bits in its binary representation, regardless of its value. This means that the maximum number of iterations of the while loop is 32, which is a constant value that does not depend on the size of the input.

// Explaination:
// In time complexity analysis, we use big-O notation to describe how the number of operations 
// performed by an algorithm grows as the size of the input increases. Since the maximum number 
// of iterations of the while loop is a constant value (32), the time complexity of the hammingWeight 
// function is O(1), which means that its running time does not depend on the size of the input.

// If you had used an int variable instead of a uint32_t variable to represent n, the time complexity
// of the function would still be O(1), because an int variable also has a fixed size (usually 32 bits)
// that does not depend on its value. However, if you had used a variable-length integer type such as a BigInteger,
// then the time complexity of the function would be different, because the number of bits in its binary representation
// would depend on its value.

int hammingWeight(uint32_t n) {
        int count = 0;

        while(n != 0) {
            int digit = n & 1;
            if(digit == 1) count++;
            n = n >> 1;
        }  

        return count;
    }

int main() {

    int num;

    cout << "Enter a Number: ";
    cin >> num;

    cout << "No. of '1' bits in given number is " << hammingWeight(num) << endl;

    return 0;
}