# Memory Allocation in C++

Memory allocation in C++ can be categorized into two types: Stack Memory Allocation (Static Allocation) and Heap Memory Allocation (Dynamic Memory Allocation).

## Stack Memory Allocation (Static Allocation)

Stack memory allocation is based on compile time. Variables such as `int i = 5`, `int arr[50]`, `char ch` are examples of stack memory allocation. 

Declaring an array with a variable size, such as `int arr[n]`, is considered a bad practice. This is because the size of the array, `n`, is determined at runtime, but the compiler needs to know the size of the array at compile time. Therefore, it's recommended to use fixed values when declaring an array, for example, `int arr[100000];`.

The reason behind this is that when a program starts, it comes with a certain amount of memory which is divided into two types: stack memory and heap memory. Stack memory is smaller compared to heap memory and is determined at compile time. If you need a large size array but haven't specified how much before compile time, the compiler allocates less memory than what you want. So when you put `n = value which is greater than stack memory` then the program will crash.

To create variable size arrays, use **HEAP**.

## Heap Memory Allocation (Dynamic Memory Allocation)

Heap memory allocation is based on runtime. To use heap memory, use the `new` keyword.

For instance, to allocate memory for a character, use `new char;`. This will allocate the required memory for one `char` and return the address of that memory location. We can't give a name to this memory like we do in stack allocation (`int num;` where `num` is the name of that memory). In heap allocation, it only returns an address. We need a pointer to store that address so we can access that memory location using the pointer's name. For example: `char *ch = new char;`.<br><br>
<img width=300 src="/Memory Allocation/Dynamic Memory Allocation/image.png" alt="Dynamic memory allocation Example" />

To create an array of size `5` in heap, use `int *arr = new int[5];`. The total memory required would be `5 * (int_size = 4)` i.e., `20 bytes` for the array and `8 bytes` for the pointer, totaling to `28 bytes`.


## Delete Keyword
- In static allocation, memory automatically release.
- In dynamic allocation, manually release require.
- To release memory use `delete` keyword.
- Example: `delete num;`, `delete []arr`
- Example: `Memory Allocation\Dynamic Memory Allocation\Example_using_while_loop.cpp`


## More information about Static, Stack and Heap Memory
1.  Static Memory (Data Segment):

    -   Static memory (also known as the data segment) is used for global and static variables.
    -   It includes:
        -   Global variables (with static storage duration).
        -   Static local variables (inside functions).
        -   Constants (e.g., string literals).
    -   The size of static memory is determined at compile time.
    -   It is typically small compared to heap memory.
    -   The exact size depends on the program's global and static variables.
2.  Stack Memory:

    -   Stack memory is used for function call frames (local variables, function parameters, return addresses).
    -   Each function call creates a new stack frame.
    -   The stack size is usually limited (e.g., a few megabytes).
    -   The compiler doesn't calculate stack usage; it's the programmer's responsibility.
    -   Stack memory is managed automatically during function calls and returns.
3.  Heap Memory:

    -   Heap memory (also known as dynamic memory) is used for dynamically allocated objects.
    -   It includes memory allocated using `new` (in C++) or `malloc` (in C).
    -   The heap size is not fixed; it grows as needed.
    -   The operating system manages heap memory.
    -   The lifetime of heap-allocated memory extends until explicitly freed (using `delete` or `free`) or until program termination.
    -   Heap memory is accessible from the entire program.
4.  Operating System and Physical Memory:

    -   The operating system manages physical memory (RAM).
    -   When a program runs, the OS allocates memory for its code, data, and stack.
    -   The heap memory is allocated from the available physical memory.
    -   The total available memory depends on the system's RAM.
5.  Summary:

    -   Static memory is fixed at compile time.
    -   Stack memory is limited and managed automatically.
    -   Heap memory is dynamic and can grow as needed.
    -   The total memory available depends on the system's physical RAM.

In summary, heap memory is not fixed; it can grow as needed from the available physical memory.
