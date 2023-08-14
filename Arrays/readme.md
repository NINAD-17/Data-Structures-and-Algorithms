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


## Problems

- **Find Duplicates in an Array**:
1. **XOR method**: 
  - This method is only works if the array contains elements from 1 to n and there is exactly one duplicate element. If these conditions are not met, this approach will not work.
  - Time Complexity is O(N) and Space complexity is O(1)
  - **Explaination**:  The idea is to XOR all the elements in the array and then XOR the result with all numbers from 1 to n. Since XOR is both commutative and associative, the order in which we perform the XORs does not matter. Also, since a XOR a = 0 for any number a, all the elements in the array except for the duplicate element will cancel out. The final result will be the duplicate element.

2. **Unordered Map**:
  - The unordered_map::count() is a builtin method in C++ which is used to count the number of elements present in an unordered_map with a given key.
  - Note: As unordered_map does not allow to store elements with duplicate keys, so the count() function basically checks if there exists an element in the unordered_map with a given key or not.
  - This function returns 1 if there exists a value in the map with the given key, otherwise it returns 0.
  - Refer this artical on <a href="https://www.geeksforgeeks.org/unordered_map-count-in-c/">GeekForGeeks -> Unordered_Map</a>

- **Binary Search**:
Don't use **`(st + en) / 2`** to find middle element.
Explaination:
  - Maximum value of int is `2<sup>31</sup>-1`
  - If `st = 2<sup>31</sup>-1` and `en = 2<sup>31</sup>-1`, then addition of `st` and `en` is not in range of `int`.
  - Therefore, use **`st + (en - st) / 2`**
