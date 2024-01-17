## Using namespace std?
- In C++, there are many namespaces.
- using namespace std is a statement that tells the compiler to use the std namespace.
- Namespaces are used to organize code into logical groups and prevent name collisions.
- The std namespace contains the identifiers of the C++ standard library, such as cout, cin, string, vector, map, etc.
- To use an identifier from the standard library, you need to specify that it belongs to the std namespace using the scope resolution operator `::`.
- Adding using namespace std at the top of your source code means you won’t have to type the `std::` prefix constantly.
- However, using this statement can lead to name collisions if you’re using multiple libraries.
- **Identifiers**: Identifier is a name used to identify a variable or function. However, in C++, identifiers are not just limited to variables and functions. They can also refer to other entities such as objects, classes, structures, and more.
- In the context of `std::cout`, `std::cin`, and `std::endl`:
    - `std::cout` and `std::cin` are objects of the `ostream` and `istream` classes respectively. They are used for output and input operations.
    - `std::endl` is a function that inserts a new line character and flushes the output buffer.
- When we say `using namespace std`, we’re telling the compiler to look into the std namespace if it doesn’t find an identifier in the current scope. This allows us to use cout, cin, endl, and other identifiers from the std namespace directly, without prefixing them with `std::`.


## return 0;
- In C++, the `return 0;` statement at the end of the main function is optional. If you don’t explicitly return a value, the compiler automatically adds a `return 0;` statement. 
- The return value of the main function is considered the "**Exit Status**" of the application. On most operating systems, returning 0 is a success status, indicating that the program worked fine. However, you can also return other values to indicate different exit statuses. 
- For example, you can `return -1` or any other non-zero value to indicate that an error occurred during the execution of your program. So, while it’s not strictly necessary to include a `return 0;` statement at the end of your main function, it’s good practice to do so to explicitly indicate that your program executed successfully


## Data Types and Variables
- **Int**: 4 bytes
- **Char**: 1 byte
- **bool**: 1 byte
- **float**: 8 byte
- **double**: 8 byte


## TypeCasting in CPP
Type casting in C++ refers to the process of converting a value of one data type to another data type. This can be useful in situations where we need to change the type of a variable to perform a certain operation or pass it to a function that requires a different data type.

- **Implicit Type Conversion**: is automatically performed by the compiler when a value is copied to a compatible type.
Ex. `int a = 'a'`
Here we're copying ASCII value of char 'a' to into a.

- **Explicit Type Conversion:**: The user can typecast the result to make it of a particular data type


**Why Integers can store max value of (2<sup>32</sup> - 1)?**
- Integer can store 4 bytes -> 32 bits, means max value is 2<sup>32</sup> - 1 and min value is 0.
- Char can store 1 byte -> 8 bit, means max value is 2<sup>8</sup> - 1 and min value is 0.
- Since each bit can have two possible values (0 or 1), a 32-bit integer can represent a total of 2<sup>32</sup> distinct values.
- However, one of these values is used to represent the number 0, leaving 2<sup>32</sup> - 1 positive values.
- For a signed 32-bit integer, the range is from -2<sup>32</sup> to 2<sup>32</sup> - 1, or -2147483648 to 2147483647.
- for an unsigned 32-bit integer, the range is from 0 to 2<sup>32</sup> - 1, or 0 to 4294967295
- If we combine the ranges of signed and unsigned 32-bit integers, we get a range from -2147483648 to 4294967295
- Default int can store both positive and negetive values. But if you want only positive numbers to be store then use `unsigned int`


In given example, When you assign an integer value to a char variable, the value is implicitly converted to a char by taking the value modulo 256 (since a char is 1 byte and can represent values from 0 to 255). In this case, 123456 modulo 256 is 64, which is the ASCII value of the character '@'. That’s why you get '@' as the output.


## Operators
- int/int = int
- float/int = float
- double/int = double


## cin
- `cin` not reads '_'(space), '\t'(tab), '\n'(enter)
- To get these as input use `cin.get()`
- It returns ASCII value of that character


## Bitwise Operator: NOT
**To print negetive number we use 2's compliment**
**Value of Not(~) of 2 is -3**

- Here 1st we took 1's compliment of integer 2.
- 000....0010 ----> 1's compliment ----> 111....1101
- 111....1101 is the value of ~num. So, this is an answer of our question.
- But we want it in decimal number. So, now we've to convert it in decimal number.

- In answer 111....1101, 1st bit is 1 which is showing that number is negetive
- **To display negetive number we've to take its 2's compliment.**
- For 2's compliment, we take 1's compliment and then add 1 to it.
- And finally we give -ve sign to that output number.

- 2's compliment process...
- To print this negetive number, you've to take 2's compliment of that value(111...- 1101)
- We're ignoring 1st bit, because it's showing that the number is negetive.
- Now take 1's compliment of remaining bits --> (00....0010) remember that we ignored- 1st bit.
- Now add 1 to this value --> 00....0010 + 1 = 00....0011
- 00....0011 So by (bin to decimal) value is 3
- So answer is -ve 3 (-3)