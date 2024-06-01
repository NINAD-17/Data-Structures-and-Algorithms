# OOPs

## Object
It's a programming technique in which things work around object.
Object is an entity, which has two things, 
    1. State or property
    2. Behaviour

We use real world objects to bring our program close to the real world. It increases readability of our program, manageability and extensibility.

## What is class?
Ex - `Hero Ninad;` here we made `Ninad` variable/object by using data type `Hero`

In object-oriented programming (OOP), a class is a blueprint or template for creating objects. It defines the properties (data members) and behaviors (member functions) that the objects of that class will have. **Think of a class as a user-defined data type**.

An object is an instance of a class. When you create an object, you’re essentially creating a variable of that class type. Objects allow you to work with the data and methods defined within the class. In your example, Ninad would be an object of the Hero class.

A variable is a named storage location in memory that holds a value. In the context of OOP, when you create an object, you’re also creating a variable of that class type. So, **`Ninad` is both an object and a variable**.

### Size of Object
If you check the size of object then it will be total of all the properties. 
When object is created from an empty class (no properties are defined), then it's size will be 1. Because by default system gives 1 byte to the object.

### Padding and Alignment
 The actual size of the class may not always match the sum of the sizes of its individual data members due to padding and alignment considerations.

- Theoretical Size
    - `int health` (4 bytes on most systems)
    - `char level` (1 byte)
    
    - The theoretical size of the class would be `4 + 1 = 5` bytes.

- Greedy Alignment
    - Greedy alignment refers to a technique used by the compiler to minimize padding.
    - The compiler orders the data members in decreasing order of size (largest to smallest).
    - In the `Hero` class:
        - `int health` (4 bytes) is larger than `char level` (1 byte).
    So, the compiler places health first, followed by level.
        - The total size becomes 4 (health) + 4 (padding) + 1 (level) = 9 bytes.
    - However, due to greedy alignment, the compiler rounds up the size to the nearest multiple of the largest alignment requirement (which is 4 bytes in this case).
    Hence, the final size of the Hero class is 8 bytes.

- Static Members and Member Functions
    - Static data members and member functions do not contribute to the size of the class or objects.
    - They have only one instance shared among all objects, and member functions are executable code without a size like data members.

- Size of Derived Class
    - When you create a derived class, it inherits the data members from the base class.
    - The size of the derived class includes both the base class data members and any additional data members introduced in the derived class.

Therefore, **size of a class depends on the data members, their alignment requirements, and the compiler’s padding strategy**.

- Summarized explaination of padding and alignment
As the theretical size is 5, it's not aligned with most largest object member's data type size. It's necessary to do that for optimization purposes. So it uses 3 out of 4 bytes (from alignment of int) and makes size equal to 8 bytes. 
**It's not memory waste**.

### External Class
You can able to define class in external file. To do this make a cpp file and write the class in it. In original file where you want to add that class, simply include that file path in `"..."` this.

## Accessing data members
You can able to access data members by using `.` (dot) operator.
Ex - see in file `1_intro.cpp`

## Access Modifiers
It defines accessibility of data members and methods of the class. It tells where its scope lies.
There're 3 access modifiers:
- Public: You can access data members anywhere (inside and outside of the class)
- Private (by default): Only accessible in class (not outside)
- Protected

### Getters and setters
To access private data members outside of the class we use getters and setters. These are functions defined in the class by which we can access private data members.