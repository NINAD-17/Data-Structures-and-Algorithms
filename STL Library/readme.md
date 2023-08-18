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


4. **Pairs**
    - To use the pair class from the C++ Standard Template Library (STL), you need to include the `<utility>` header file in your code.