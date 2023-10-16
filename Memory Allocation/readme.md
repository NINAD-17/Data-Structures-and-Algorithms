# Memory Allocation

## Reference Variable
- Same memory but can have different names.
- Create
```
int i = 5;
int &j = i; // Reference variable j is created
```
In this example, the memory block where `5` contain for that block 2 names are mapped `i` and `j` in symbol table.

- **Why we need Reference Variable?**
    - In functions, whenever we pass values from argument they *pass by value*. In *pass by value* it always create copy of that value in function. So changes made in that function for that value doesn't change in original value but it only change in that copied value which is limited to that function.
    - To directly change value (which pass to function) after function execution we need to use reference variable.
    Example:
    ```
    void passByReference(int &n) {
        n++; // Change directly in main function's 'a' variable.
    }
    ```
    Here variable `n` is passed by reference means it's a variable which is pointing to same memory location which is in the main function.
    Means, if `passByReference(a);` is a call then `n` and `a` are two names of that same memory location.

### Pass by value VS Pass by Reference
- In *pass by ref.* no new memory is created. But in *pass by value* a copy is created.
- In *pass by ref* memory is same but name is different.

### Using reference variable as return in output
**Note: It's a bad practice** reason given below.
```
int& update(int n) {
    int a = 10;
    int &ans = a; // Storing value of a i.e 10 in ans variable.
    return ans; // returning ans variable as a reference.
}
```
Here, `ans` variable is returning as a reference means, when in main function variable `a` in which output value is going to be store it's now second name of `ans` variable.

- Here is a big mistake is that, lifespan of local variable is limited to the function only. After that they will not be able to accessible. So when `update()` function's block gets over and memory gets cleared, there is nothing remaining to pass. So it's very dangerous. 