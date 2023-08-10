# Arrays

An array is a collection of items of same data type stored at contiguous memory locations.

## Why?
To store multiple values in one variable.
Example: 
```
10000 values ---> 10000 variables
10000 values ---> 1 variable
```

## Declaring Arrays

`int arr[10];`
Here 'arr' is the name of array as well as it's locates address of 1st element of array.

If you declared array without initializing it then it will contain garbage values.
`int arr[10];`

- Arrays are contiguous memory locations.
- Indexing start with 0. `arr[0]` is the first location.
  ```
  arr[1] ==> 100 + 4 * 1    // Here 1 is the 2nd memory location and assume 100 as memory location. 4 is the size of int
  ```
- `int arr[10000] = {0}` Here all array elements is initialized with 0.
  `int arr[10000] = {1}` But here this will not work. It only works for 0.

- **Note: Bad Practice**
Always initialize array with some value not by input value
Why? -----> See Pointer topic for detailed explaination.
```
int size;
cin >> size;

int arr[size]; // 💀⚠️
```

## Scopes in Array

- When an array is passed as a parameter to a function, it is not passed as a full copy of the array. Instead, the base address of the array is passed as a pointer, for example: `void updateArr(int *arr, int size)`.
- This means that any changes made to the elements of the array within the function will modify the original array.
- As a result, it is important to be cautious when modifying array elements within a function, as these changes will persist even after the function returns.