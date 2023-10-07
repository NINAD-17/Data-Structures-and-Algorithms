## Maths for DSA

## **Sieve of Eratosthenes**
- The Sieve of Eratosthenes is an ancient algorithm used to find all prime numbers up to any given limit
- in `/count_primes.cpp`(brute force approach) code we're calculating each number from `2` to `num` to determine is it prime or not. So time complexity is `O(n^n)`.

- *Sieve of Eratostehnes approach for count_primes problem*
    1. Mark each number as a prime number
    2. Mark non-prime to the numbers which are in table of current selected number except selected number.

**Explaination by Striver:**
If a problem provides a  10<sup>6</sup> number of testcases and each number is very close to or equal to a 10<sup>6</sup>.
Then the worst-case scenario becomes, 
```
O(T*sqrt(n)) = O(10^6, sqrt(10^6))
             = 10^6 * 10^3
             = equivalent to 10^9 operations
```
If we assumed 10^8 as 1 second/ 2 second at max then this is going to take 10 seconds and it will give you TLE(time limit exceeded) error. Therefore we've to use Sieve of Erastothenes algorithm.

**Note:** If you define `int` array in main function or any other function then maximum limit is `10^6` and for `bool` it's `10^7`.
But if you define `int` array globally then it's max limit is `10^7` and for `bool` it's `10^8`


**Sieve of Eratosthenes** VS **Segmented Sieve**
**Sieve of Eratosthenes**:
- This algorithm creates a list of all integers from 2 to `n`.
- It iteratively marks the multiples of each number starting from 2.
- The numbers that are not marked in the end are the primes.
- The time complexity is **O(n log log n)**.
- The space complexity is **O(n)**, which can be a problem for large `n` as it may not fit in memory.
- when n is large, the Simple Sieve faces the following issues.
    - An array of size Θ(n) may not fit in memory
    - The simple Sieve is not cached friendly even for slightly bigger n. The algorithm traverses the array without locality of reference

## **Segmented Sieve**:
- This algorithm overcomes the space complexity issue of the Sieve of Eratosthenes.
- If we've input `n` very large (say 10<sup>9</sup> or higher) then normal sieve will try to create an array of size `n + 1`. And many programming language environment may not allow to create this big size of array. It's very inefficient, consuming too much memory.
- It divides the range `[0..n-1]` into different segments and computes primes in all segments one by one.
- It first uses the Sieve of Eratosthenes to find primes smaller than or equal to `√(n)`.
- For every segment, it creates an array `mark[high-low+1]` and marks multiples of primes in this range.
- The time complexity remains **O(n log log n)**.
- The space complexity reduces to **O(√n)**, making it more efficient for large `n`.

So, while both algorithms are used for finding prime numbers, the Segmented Sieve is more efficient when dealing with large numbers due to its lower space complexity.


## Euclid's Algortithm
1. **GCD/ HCF:**
- It's a one factor which is maximum and can divide both the numbers perfectly and give remainder 0. The GCD of two numbers is the largest number that divides both of them without leaving a remainder.
Example:
<img src="/Maths For DSA/image.png" width=300 alt="GCD/HCF" />

- Formula: `gcd(a, b) = gcd(a - b, b) => gcd(a % b, b)`
- Learn more about Euclid's Algorithm at: <a href="https://www.codingninjas.com/studio/library/gcd-euclidean-algorithm">codingninjas.com</a>
