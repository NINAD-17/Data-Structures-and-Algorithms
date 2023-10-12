# Pointers

## Mapping of Variable Name and Address
- A **Symbol Table** is a crucial data structure created and maintained by the compiler to keep track of the semantics of variables. It stores information about the scope and binding information about names, instances of various entities such as variable and function names, classes, objects, etc.
- For example, `int num = 5;` Here, `num` is mapped to the address of a memory location where `5` is stored.  `num ----> address`
- `cout << num << endl;` In this case, it first finds the address mapped to the `num` variable and then prints the content from that address (here it is `5`).

- The **Address of Operator (&)** can be used to find the address of any variable mapped to it.
- It provides the address in Hexadecimal format.
- For example: `cout << "Address of num: " << &num << endl;`

- **Pointers (*)** are used to store addresses in a variable.
- Example: `int *ptr = &num;`
- *Note: Do not create pointers without initializing them.* If you do so, it will point to an unknown memory location (which is a BAD PRACTICE).
For example: `int *ptr;`
- Instead, if you don't know where to point, initialize that pointer with zero.
For example: `int *ptr = 0;` After that, if you want to point it to a location then use `ptr` only. Don't give `*` before it. For example: `ptr = &var_name;`
- `int *ptr` means that `ptr` is a pointer to the `int` data type.

- The **De-reference Operator (*)** means that whenever you access *var_name then it will give you content stored in that address (which is stored in pointer variable).
For example: `cout << *ptr << endl;` means it will give you output `5` if `int num = 5;`.

- For any data types, a pointer will always store the address of a memory location, therefore its size will always be `8 bytes`. 

- **Copying a Pointer into Another Pointer**:
```
int *e = &num;
int *f = e;
```

- **If You Increment an Address Then**:
    - For example: `int *ptr = &num;`
    - If you did `ptr = ptr + 1;` and assume the address of `ptr` as `101`;
    - Then it will become `105`, meaning it will move to the next integer (the size of an integer is 4 bytes therefore `101 + 4 = 105`)