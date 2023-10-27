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
    - Here 2<sup>4</sup> is a big problem whose solution is depend on small problem 2<sup>3</sup> of same type.
    - So we can write it as, 2<sup>n</sup> = 2 * 2<sup>n - 1</sup>
    - We can also write it as in a form of function, f(n) = 2 * f(n - 1) it's called recursive relation.
- Base case: Remember, every recursive function should have a base case that stops the recursion, and one or more recursive cases that move towards the base case. Without a base case, a recursive function would call itself indefinitely, leading to an infinite loop and potentially causing a stack overflow error.

- 3 components in recursion - base case, recursive relation, processing
- If recursive relation is in the end then it's called **Tail recursion**.
- If recursive relation is comes before processing is called **Head recursion**.
- **Stack Overflow:** Recursion uses an in-built stack that storesrecursive calls. Hence, the number of recursive calls must be as small as possible to avoid memory-overflow. If the number of recursion calls exceeded the maximum permissible amount, therecursion depth* will be exceeded. This condition is called stack overflow.

- Remember: Just solve one case and the rest will happen automatically. 
"बस एक केस सोल्व करो बाकी सब अपने आप हो जाएगा." - <a href="https://youtu.be/zg8Y1oE4qYQ?si=WLbLKLG8v2wZ9MYw&t=251">Love Babber</a>
- In `reach_home.cpp` example after `src == dest` then function stack is going to empty by `reach_home(10, 10)` will be removed from stack first then `reach_home(9, 10)` ..... `reach_home(1, 10)` like that.

- `Sum_of_array_elements.cpp` recursive tree
    <img src="/Recursion/sum of array elements.jpg" width=300 />


## Why we must have to add `return` keyword before recursive call?
- it’s important to note that while your code may work as expected in this specific case, it’s generally considered good practice to explicitly return a value in all code paths for a function that is expected to return a value. This helps prevent potential bugs and makes the code easier to understand.
- Ex. `/array_is_sorted_or_not.cpp` in this code we don't need that `return` keyword. It will always terminate before coming back from base case. 
- However, if you were to modify your function in the future or use a similar pattern in a different function, forgetting to return a value could lead to unexpected behavior. Therefore, it’s generally **recommended to always explicitly return a value when a function is expected to do so**. This makes your code more robust and easier to maintain and understand. It’s all about writing clean and maintainable code. 


