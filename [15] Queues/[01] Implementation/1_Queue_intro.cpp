#include <iostream>
#include <queue>
using namespace std;

int main() {
    // create a queue
    queue<int> q;

    // push
    q.push(11);

    // front 
    cout << "front of queue is " << q.front() << endl;

    q.push(15);
    q.push(19);

    // size
    cout << "size of queue is " << q.size() << endl;

    // pop
    q.pop();
    cout << "size of queue is " << q.size() << endl;
    cout << "front of queue is " << q.front() << endl;

    // is empty?
    if(q.empty())
        cout << "queue is empty" << endl;
    else 
        cout << "queue isn't empty" << endl;

    return 0;
}