## Using namespace std?
- In C++, there are many namespaces.
- using namespace std is a statement that tells the compiler to use the std namespace.
- Namespaces are used to organize code into logical groups and prevent name collisions.
- The std namespace contains the identifiers of the C++ standard library, such as cout, cin, string, vector, map, etc.
- To use an identifier from the standard library, you need to specify that it belongs to the std namespace using the scope resolution operator `::`.
- Adding using namespace std at the top of your source code means you won’t have to type the std:: prefix constantly.
- However, using this statement can lead to name collisions if you’re using multiple libraries.


## Data Types & Variables
- **Int**: 4 bytes
- **Char**: 1 byte
- **bool**: 1 byte
- **float**: 8 byte
- **double**: 8 byte


## TypeCasting in CPP
Type casting in C++ refers to the process of converting a value of one data type to another data type1. This can be useful in situations where we need to change the type of a variable to perform a certain operation or pass it to a function that requires a different data type.

- **Implicit Type Conversion**: is automatically performed by the compiler when a value is copied to a compatible type.
Ex. `int a = 'a'`
Here we're copying ASCII value of char 'a' to into a.

- **Explicit Type Conversion:**: The user can typecast the result to make it of a particular data type


**Why Integers can store max value of (2<sup>32</sup> - 1)?**
- Integer can store 4 bytes -> 32 bits, means max value is `2<sup>32</sup> - 1` and min value is 0.
- Char can store 1 byte -> 8 bit, means max value is `2<sup>8</sup> - 1` and min value is 0.
- Since each bit can have two possible values (0 or 1), a 32-bit integer can represent a total of `2<sup>32</sup>` distinct values.
- However, one of these values is used to represent the number 0, leaving `2<sup>32</sup> - 1` positive values.
- For a signed 32-bit integer, the range is from `-2<sup>32</sup> to 2<sup>32</sup> - 1, or -2147483648 to 2147483647`.
- for an unsigned 32-bit integer, the range is from `0 to 2<sup>32</sup> - 1`, or `0 to 4294967295`
- If we combine the ranges of signed and unsigned 32-bit integers, we get a range from `-2147483648 to 4294967295`


In given example, When you assign an integer value to a char variable, the value is implicitly converted to a char by taking the value modulo 256 (since a char is 1 byte and can represent values from 0 to 255). In this case, 123456 modulo 256 is 64, which is the ASCII value of the character '@'. That’s why you get '@' as the output.