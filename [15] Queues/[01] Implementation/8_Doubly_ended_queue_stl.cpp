#include <iostream>
#include <queue>
using namespace std;

// DOUBLY ENDED QUEUE (STL)

// some information -
// with doubly ended queue, you can able to implement both stack and queue.
// it's basically used in CPU scheduling, process scheduling

// conditions:
//      1. push_back: insert element from rear
//      2. push_front: insert element from front
//      3. pop_back: remove element from rear
//      4. pop_front: remove element from front

int main() {

    // STL
    deque<int> d;

    d.push_front(12);
    d.push_back(13);

    cout << d.front() << endl;
    cout << d.back() << endl;

    d.pop_front();

    cout << d.front() << endl;
    cout << d.back() << endl;

    d.pop_back();

    if(d.empty()) {
        cout << "queue is empty" << endl;
    } else {
        cout << "queue is not empty" << endl;
    }

    return 0;
}