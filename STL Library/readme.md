# CPP STL Library

### Containers
- 1. Sequence Container
    - Array, Vector, Deque, List ...
- 2. Container Adaptors
    - Stack, Queue, Priority Queue ...
- 3. Associative Containers
    - Set, Map, Multimap ...
- 4. Unordered Associative
    - Unordered Set, Unordered Map, Unordered Multiset ...


### Implementation

1. **Array**
    - First include `<array>` liabrary.
    - Normal Array ==> `int basic[3] = {4, 5, 6};`
    - STL Array ==> `array<int, 4> arr = {1, 2, 3, 4};`
    - As both are same(static arrays) we're not using STL Array.

2. **Vector**
    - It's a dynamic array. Like array, it's also store data in contiguous memory locations. 
    - When vector gets full, vector will double its size (one vector is fully filled then new vector will be created that will be double its size and then old will be copied to new one and the old one will be deleted)
    - 'Shrink to fit' operation is used to decrease the size.

3. **Double Ended Queue**
    - It means you can apply push and pop, insertion and deletion at the begining and end.
    - Data isn't stored in contiguous memeory location, instead it has multiple fixed static arrays and tracking takes place that your data is stored in which array. (Complex implementation)
    - It's dynamic, so size can increase.

4. **List**
    - By the use of Double Linked List, 'List' STL has been made.
    - We can't able to access an element directly, we need to travel to reach there.

5. **Iterators**
    - An iterator is an object that can be used to traverse a container, such as a list or vector, and access its elements. Iterators are a major feature of the Standard Template Library (STL) in C++, and they provide a way to abstract the process of accessing elements in a container, regardless of the underlying data structure.
    - `Name.begin()` points at 1st position.
    - `Name.end()` points at last + 1 position.

    - Difference between `i+1` and `i++`
    In vector it++ == it+1 cause contiguous, hence next position is same, but
    For non-contiguous (maps, sets) if you use it+1 it gives you compilation error cause next location isn’t always vectors location.

6. **Pairs**
    - To use the pair class from the C++ Standard Template Library (STL), you need to include the `<utility>` header file in your code.

7. **Stack**
    - Last in First out

8. **Queue**
    - First in First out

9. **Priority Queue** 
    -  It is a type of container adapter, specifically designed such that the **first element of the queue is either the greatest or the smallest** of all elements in the queue, depending on the ordering used
    - Priority queues are implemented using a heap data structure, and use an array or vector as an internal structure

10. **Set**
    - `set` is a type of associative container in which each element has to be unique because the value of the element identifies it.
    - The values are stored in a specific sorted order i.e. either ascending or descending.
    - By default, the std::set is sorted in ascending order. However, we have the option to change the sorting order by using the following syntax: `std::set <data_type, greater<data_type>> set_name;`
    - `set` is slower than `unordered set`. In unordered set elements are not in sorted order.
    - std::map and std::set use bidirectional iterators, which do not support the it+1 operation. Attempting to use it+1 with a bidirectional iterator will result in a compilation error.
        Example:
        ```
        s.erase(s.begin() + 2); // It will not work

        s.erase(next(s.begin(), 2)); // Instead use this method
        ```
    - `s.count(5)` this method checks that if 5 is present or not.
    - `s.find(5)` if element is exist then it will return iterator of that element.

11. **Map**
