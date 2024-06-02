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

## Behind the scenes of Object Initialization
- Default Constructor
    - It first invokes a constructor.
    - When `Hero ironman;` executes then it calls the `ironman.Hero()`. It's created by default. It's called **default constructor**.
    - You can also able to write it explicitly.

- Parameterized Constructor
```
        Hero(int health) {
            health = health;
        }
```
In this code, health (temp health/parameter variable) is giving it's value again to it (concept -> variable scoping - health is parameter variable and not actual variable defined in constructor)

- **this keyword**: It stores the address of current object. It's a pointer that's why you can access it by (*this).__ or this -> __
- by using `this -> health = health`, it solves that confusion and assigns the ironman's health value equals to health value get from parameter.

- When you make any constructor explicitly then deafault constructor will not work, it's gone. So after creating parameterized constructor, you're trying to access default constructor it will not work.

- **Copy constructor**: 
- A copy constructor is a special constructor that creates a new object as a copy of an existing object.
- Whenever you write a class then automatically it also makes a copy constructor.
- So that you can able to use `Hero hulk(spiderman)`. It will copy all the object member's values into hulk.

- Infinite loop in copy constructor: If you define your own copy constructor as
```
Hero(Hero temp) {

}

Hero hulk(spiderman);
```

In this case spiderman is passed by value to the temp. Therefore temp is making copy of spiderman object and to make copy it calls (temp calls) the copy constructor, and it gets stuck in infinite loop.

- When you create Hero hulk(spiderman);, the following happens:
spiderman is passed by value to the copy constructor (i.e., temp is a copy of spiderman).
- Inside the copy constructor, the compiler attempts to create a copy of temp (which is itself a copy of spiderman).
This process repeats indefinitely, leading to an infinite loop.
- Fixing the Issue:
To avoid the infinite loop, you should pass the object by reference (const reference, ideally) instead of by value:
```
Hero(const Hero& temp) {
    // Implementation
}
```

- By passing by reference, you avoid making unnecessary copies and prevent the infinite recursion.

Passing by reference (const reference) allows you to work with the original object directly without creating additional copies.

- Infinite loop stack for copy constructor:
Initial Call:
Hero hulk(spiderman):
spiderman is passed by value to the copy constructor.
Inside the copy constructor, a new object (let’s call it temp1) is created as a copy of spiderman.
First Iteration:
temp1(spiderman):
Now, temp1 (which is a copy of spiderman) is passed to the copy constructor.
Inside the copy constructor, another new object (let’s call it temp2) is created as a copy of temp1.
Second Iteration:
temp2(temp1):
The process continues:
temp2 (which is a copy of temp1) is passed to the copy constructor.
Inside the copy constructor, yet another new object (let’s call it temp3) is created as a copy of temp2.
Third Iteration:
temp3(temp2):
And again:
temp3 (which is a copy of temp2) is passed to the copy constructor.
Inside the copy constructor, a new object (let’s call it temp4) is created as a copy of temp3.
... Infinite ....

- After writing own copy constructor, default copy constructor gets dead.


- Deep copy and Shallow copy:
- Shallow copy: It's done by default. In this it uses same memory location for each object's object member.
- Deep copy: In this instead of using same memory location it uses different. 
- See the example in `5_Shallow_and_Deep_copy.cpp`.