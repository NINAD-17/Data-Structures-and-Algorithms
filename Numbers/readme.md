## Digital Root Formula
The digital root of a positive integer is the single-digit value obtained by an iterative process of summing digits, on each iteration using the result from the previous iteration to compute a digit sum. The process continues until a single-digit number is reached.

Example: the digital root of `65,536` is `7`, because `6 + 5 + 5 + 3 + 6 = 25` and `2 + 5 = 7`

**Formula:** The digital root of `n` is equal to the remainder when `n` is divided by `9`
- `dr(n) = 1 + ((n - 1) % 9)`

This formula gives us the digital root of n directly, without having to perform any iterative digit summing

```
dr(65,536) = 1 + ((65,536 - 1) % 9)
           = 1 + (65,535 % 9)
           = 1 + (7)
           = 8
```

## GCD (greatest common divisor)
It's used to find largest positive integer that divides both numbers without a remainder.
For example, the GCD of 8 and 12 is 4, because 4 is the largest positive integer that divides both 8 and 12 without a remainder.

- To find GCD we use **Euclidean algorithm**. It's an efficient way to find GCD.

Using Recursion,
```
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
```

Without using Recursion,
```
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
```


## Armstrong Number
An Armstrong number is a number that is equal to the sum of its own digits each raised to the power of the number of digits.
Ex. `153` is an Armstrong number.
    `1*1*1 + 5*5*5 + 3*3*3 = 153`


## Perfect Number
A number is a perfect number if is equal to sum of its proper divisors, that is, sum of its positive divisors excluding the number itself.

Example:
```
Input: n = 6
Output: true
Divisors of 6 are 1, 2 and 3. Sum of 
divisors is 6.
```