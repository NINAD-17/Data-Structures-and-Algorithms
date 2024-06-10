#include <iostream>
using namespace std;

// INPUT RESTRICTED QUEUE IMPLEMENTATION USING ARRAY
// conditions:
//      1. insertion of elements can be done on rear side only
//      2. removal of element is possible on both side (front and rear)

class InputRestrictedQueue {
    // note: we're using logic of circular queue and not normal queue because of efficient memory use
    public: 
        int *arr;
        int size;
        int qFront;
        int qRear;

        // constructor
        InputRestrictedQueue(int size) {
            this -> size = size;
            arr = new int[size];
            qFront = -1;
            qRear = -1;
        }

        // behaviour
        void enqueue(int data) {
            // check if the queue is full or not
            if((qRear + 1) % size == qFront) {
                // if the above output is equal to front then queue is full
                cout << "queue is full" << endl;
                return ;
            }

            // insert element
            if(qFront == -1) {
                qFront = 0;
                qRear = 0;
            } else if(qFront != 0 && qRear == size - 1) {
                qRear = 0;
            } else {
                qRear++;
            }

            arr[qRear] = data;
        }

        // we can dequeue from both sides - front and rear
        void dequeue_front() {
            // check if the queue is empty or not
            if(qFront == -1) {
                cout << "queue is empty" << endl;
                return;
            }

            arr[qFront] = -1;

            if(qFront == qRear) {
                qRear = qFront = -1;
            } else if(qFront == size - 1) {
                qFront = 0;
            } else {
                qFront++;
            }
        }

        void dequeue_rear() {
            // check if queue is empty or not
            if(qRear == -1) {
                cout << "queue is empty" << endl;
                return ;
            }

            arr[qRear] = -1;

            if(qFront == qRear) {
                qFront = qRear = -1;
            } else if(qRear == 0) {
                qRear = size - 1;
            } else {
                qRear--;
            }
        }
};

void printQueue(InputRestrictedQueue &q) {
    if(q.qFront == -1) {
        cout << "queue is empty" << endl;
        return;
    }

    cout << "\nqueue: (front) ";
    for(int i = q.qFront; i <= q.qRear; i++) // i < q.qrear because the rear is always pointing towards last element's next place
        cout << q.arr[i] << " -> ";
    cout << "(rear)" << endl;
}

int main() {

    InputRestrictedQueue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);

    printQueue(q);

    q.dequeue_front();
    printQueue(q);

    q.dequeue_rear();
    printQueue(q);

    q.dequeue_front();
    printQueue(q);

    q.dequeue_rear();
    printQueue(q);

    q.dequeue_rear();
    printQueue(q);

    return 0;
}