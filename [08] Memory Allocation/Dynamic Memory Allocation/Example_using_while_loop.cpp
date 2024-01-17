#include <iostream>
using namespace std;

int main() {

    // Case 1: Infinite loop with static memory allocation
    while(true) {
        int i = 5;
    }
    // In above case, in each instant of time it will only take memory of 1 int. Because at every iteration local memory gets released and again allocate in next iteration.
    // So only 4 byte(int size) Memory is allocate and delete each time.


    // Case 2: Infinite loop with dynamic memory allocation in c++
    while(true) {
        int *ptr = new int;
    }
    // In above example, pointer ptr is allocated in stack memory and memory is allocate in heap. So at each iteration stack memory gets released as above example but heap's 
    // memory will not. In each iteration it will add 4 bytes (size of int). In C++, memory which allocate in heap not gets released. So, in this example after memory gets full of your system then program will crash.
    
     

}