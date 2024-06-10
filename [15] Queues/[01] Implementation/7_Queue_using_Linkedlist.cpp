#include <iostream>
#include "../../[13] Linked List/lib/singly_linkedlist.cpp"
using namespace std;

// QUEUE IMPLEMENTATION USING LINKED LIST

class Queue {
    public:
        Node* qFront;
        Node* qRear;
        int totalNodeCnt;
        int size;

        // constructor
        Queue(int size) {
            this -> size = size;
            qFront = NULL;
            qRear = NULL;
            totalNodeCnt = 0;
        }

        // Operations
        // 1. enqueue
        void enqueue(int data) {
            if(totalNodeCnt == size) {
                cout << "queue is full" << endl;
                return ;
            }

            insertAtTail(qFront, qRear, data);
            totalNodeCnt++;
        }

        void dequeue() {
            if(qFront == NULL) {
                cout << "queue is empty" << endl;
                return;
            }

            deleteNode(qFront, qRear, 1);
            totalNodeCnt--;
        }

        int front() {
            if(qFront == NULL) {
                cout << "error: can't show front element, queue is empty" << endl;
                return -1;
            }

            return qFront -> data;
        }

        bool isEmpty() {
            if(qFront == NULL)
                return true;
            else 
                return false;
        }
};

int main() {
    Queue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    printLL(q.qFront);

    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(6);

    cout << "front element: " << q.front() << endl;
    printLL(q.qFront);

    q.dequeue();
    cout << "front element: " << q.front() << endl;
    printLL(q.qFront);

    q.dequeue();
    cout << "front element: " << q.front() << endl;
    printLL(q.qFront);

    q.dequeue();
    cout << "front element: " << q.front() << endl;
    printLL(q.qFront);

    q.dequeue();
    cout << "front element: " << q.front() << endl;
    printLL(q.qFront);

    q.dequeue();
    cout << "front element: " << q.front() << endl;
    printLL(q.qFront);
}