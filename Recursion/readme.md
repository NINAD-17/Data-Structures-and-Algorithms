# Recursion

Recursion is a powerful concept in computer science and programming. It is a method where a function calls itself directly or indirectly until a certain condition, known as the base case, is met. This technique is particularly useful when the solution to a complex problem depends on the solution to smaller instances of the same problem.

## Understanding Recursion with an Example
Consider the following simple example of a recursive function in C++:

```
cpp
void solve(int n) {
    if (n == 0) return; // base case
    // some code here...
    solve(n - 1); // recursive call
}
```
In this code, solve is a recursive function that calls itself with a smaller value of n until n becomes zero.

## Key Components of Recursion
There are three key components in recursion:

**Base Case:** This is the condition that stops the recursion. Every recursive function should have a base case to prevent it from calling itself indefinitely, leading to an infinite loop and potentially causing a stack overflow error.

**Recursive Relation:** This is the relationship that breaks down the problem into smaller instances of the same problem. For example, consider the problem of calculating 2<sup>n</sup>. We can express this as 2<sup>n</sup> = 2 * 2<sup>n - 1</sup>. In this case, f(n) = 2 * f(n - 1) is the recursive relation.

**Processing:** This refers to any computations or operations that the function performs.

## Types of Recursion
Depending on where the recursive relation appears in the function, recursion can be classified into two types:
- **Tail Recursion**: If the recursive relation is at the end of the function.
- **Head Recursion**: If the recursive relation comes before any processing in the function.


## Stack Overflow in Recursion
Recursion uses an in-built stack to store recursive calls. Hence, it’s important to limit the number of recursive calls to avoid memory overflow. If the number of recursion calls exceeds the maximum permissible amount, it will exceed the recursion depth, leading to a condition called stack overflow.

## Importance of Return Statement in Recursive Functions
While your code may work as expected without explicitly returning a value in all code paths for a function that is expected to return a value, it’s generally considered good practice to do so. This helps prevent potential bugs and makes your code easier to understand and maintain.

For instance, consider an example where we check if an array is sorted or not using recursion. In this case, we don’t need to use the return keyword because the function will always terminate before coming back from the base case.
Ex. `/array_is_sorted_or_not.cpp`

However, if you were to modify your function in the future or use a similar pattern in a different function, forgetting to return a value could lead to unexpected behavior. Therefore, it’s generally recommended to always explicitly return a value when a function is expected to do so. This makes your code more robust and easier to maintain and understand.

- **Remember: Just solve one case and the rest will happen automatically.** 
"बस एक केस सोल्व करो बाकी सब अपने आप हो जाएगा." - <a href="https://youtu.be/zg8Y1oE4qYQ?si=WLbLKLG8v2wZ9MYw&t=251">Love Babber</a>
- In `reach_home.cpp` example after `src == dest` then function stack is going to empty by `reach_home(10, 10)` will be removed from stack first then `reach_home(9, 10)` ..... `reach_home(1, 10)` like that.

- `Sum_of_array_elements.cpp` recursive tree <br>
    <img src="/Recursion/sum of array elements.jpg" width=300 />


## Why Shouldn’t We Use Recursion for Linear and Binary Search?
- Both recursive and iterative versions of linear search have a time complexity of O(n). However, in terms of space complexity, the recursive version uses O(n) space due to the call stack, while the iterative version uses O(1) space. Therefore, from a space complexity standpoint, the iterative approach is more optimal.
- Also, recursion involves function call overheads and can lead to stack overflow for large inputs. So, in general, for a problem like linear search where a simple iterative solution exists, it’s usually more efficient to use the iterative approach. But remember that recursion can be very useful and elegant for problems where the solution involves solving smaller instances of the same problem.
- Same explanation for binary search

