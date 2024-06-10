#include <iostream>
using namespace std;

// DOUBLY ENDED QUEUE IMPLEMENTATION USING ARRAY

// some information -
// with doubly ended queue, you can able to implement both stack and queue.
// it's basically used in CPU scheduling, process scheduling

// conditions:
//      1. push_rear: insert element from rear
//      2. push_front: insert element from front
//      3. pop_rear: remove element from rear
//      4. pop_front: remove element from front

class Deque {
    public: 
        int *arr;
        int size;
        int front;
        int rear;

        // constructor
        Deque(int size) {
            this -> size = size;
            arr = new int[size];
            front = -1;
            rear = -1;
        }

        // operations 
        // 1. push_rear
        void push_rear(int data) {
            // is the queue full?
            if(front == (rear + 1) % size) {
                cout << "deque is full, try again after removing some elements" << endl;
                return;
            }

            if(rear == -1) {
                front = rear = 0;
            } else if(rear == size - 1) {
                rear = 0;
            } else {
                rear++;
            }

            arr[rear] = data;
        }

        void push_front(int data) {
            // is the queue is full?
            if(front == (rear + 1) % size) {
                cout << "deque is full, try again after removing some elements" << endl;
                return ;
            }

            if(front == -1) {
                front = rear = 0;
            } else if(front == 0) {
                front = size - 1;
            } else {
                front--;
            }

            arr[front] = data;
        }

        void pop_rear() {
            if(front == -1) {
                cout << "deque is empty" << endl;
                return ;
            }

            arr[rear] = -1;

            if(rear == front) {
                rear = front = -1;
            } else if(rear == 0) {
                rear = size - 1;
            } else {
                rear--;
            }
        }

        void pop_front() {
            if(front == -1) {
                cout << "deque is empty" << endl;
                return ;
            }

            arr[front] = -1;

            if(front == rear) {
                front = rear = -1;
            } else if(front == size - 1) {
                front = 0;
            } else {
                front++;
            }
        }

        int getFront() {
            if(front == -1) {
                cout << "deque is empty, front: -1" << endl;
                return -1;
            }
            else 
                return arr[front];
        }

        int getrear() {
            if(rear == -1) {
                cout << "deque is empty, rear: -1" << endl;
                return -1;
            }
            else 
                return arr[rear];
        }

        bool isEmpty() {
            if(front == -1)
                return true;
            else 
                return false;
        }
};

void printDeque(Deque &dq) {
    if(dq.front == -1) {
        cout << "deque is empty\n" << endl;
        return;
    }

    cout << "printing deque: ";

    int i = dq.front;

    do {
        cout << dq.arr[i] << " ";
        i = (i + 1) % dq.size;
    } while(i != ((dq.rear + 1) % dq.size));

    cout << endl << endl;
}

int main() {

    Deque dq(6);

    dq.push_rear(2);
    dq.push_rear(5);
    dq.push_front(1);
    dq.push_front(3);
    dq.push_front(4);
    dq.push_front(6);
    dq.push_front(1);
    dq.push_front(2);

    cout << "front: " << dq.getFront() << endl;
    cout << "rear: " << dq.getrear() << endl;
    printDeque(dq);

    dq.pop_rear();
    cout << "front: " << dq.getFront() << endl;
    cout << "rear: " << dq.getrear() << endl;
    printDeque(dq);

    dq.pop_rear();
    cout << "front: " << dq.getFront() << endl;
    cout << "rear: " << dq.getrear() << endl;
    printDeque(dq);

    dq.pop_front();
    cout << "front: " << dq.getFront() << endl;
    cout << "rear: " << dq.getrear() << endl;
    printDeque(dq);

    dq.pop_front();
    cout << "front: " << dq.getFront() << endl;
    cout << "rear: " << dq.getrear() << endl;
    printDeque(dq);

    dq.pop_rear();
    cout << "front: " << dq.getFront() << endl;
    cout << "rear: " << dq.getrear() << endl;
    printDeque(dq);

    dq.pop_rear();
    cout << "front: " << dq.getFront() << endl;
    cout << "rear: " << dq.getrear() << endl;
    printDeque(dq);

    return 0;
}