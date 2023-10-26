# Recursion

Recursion is a powerful concept in computer science and programming, where a function calls itself directly or indirectly until a certain condition is met. This technique is particularly useful when the solution to a complex problem depends on the solution to smaller instances of the same problem.

Here's a simple example of a recursive function in C++:

```
cpp
void solve(int n) {
    if (n == 0) return; // base case
    // some code here...
    solve(n - 1); // recursive call
}
```
In the above code, solve is a recursive function that calls itself with a smaller value of n until n becomes zero.

- When solution of big and complex problem depends on small problem of same type, then we use recursion.
- Example: 
    - 2<sup>4</sup> = 2 * 2 * 2 * 2 = 2 * 2<sup>3</sup>
    - Here 2<sup>4</sup> is a big problem whose solution is depend on small problem 2<sup>3</ - sup> of same type.
    - So we can write it as, 2<sup>n</sup> = 2 * 2<sup>n - 1</sup>
    - We can also write it as in a form of function, f(n) = 2 * f(n - 1) it's called recursive relation.
- Base case: Remember, every recursive function should have a base case that stops the recursion, and one or more recursive cases that move towards the base case. Without a base case, a recursive function would call itself indefinitely, leading to an infinite loop and potentially causing a stack overflow error.

- 3 components in recursion - base case, recursive relation, processing
- If recursive relation is in the end then it's called **Tail recursion**.
- If recursive relation is comes before processing is called **Head recursion**.

- Remember: Just solve one case and the rest will happen automatically. 
"बस एक केस सोल्व करो बाकी सब अपने आप हो जाएगा." - <a href="https://youtu.be/zg8Y1oE4qYQ?si=WLbLKLG8v2wZ9MYw&t=251">Love Babber</a>
- In `reach_home.cpp` example after `src == dest` then function stack is going to empty by `reach_home(10, 10)` will be removed from stack first then `reach_home(9, 10)` ..... `reach_home(1, 10)` like that.