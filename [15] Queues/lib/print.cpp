#include <iostream>
#include <queue>
using namespace std;

void printQueue(queue<int> q) {
    cout << "\nqueue: (front) ";
    
    int size = q.size();
    for(int i = 0; i < size; i++) {// i < q.qrear because the rear is always pointing towards last element's next place
        cout << q.front() << " -> ";
        q.pop();
    }
    cout << "(rear)" << endl;
}