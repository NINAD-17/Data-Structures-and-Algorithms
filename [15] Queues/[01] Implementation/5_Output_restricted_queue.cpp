#include <iostream>
using namespace std;

// OUTPUT RESTRICTED QUEUE
// conditions:
//      1. you can able to insert elements from both sides (front and rear)
//      2. removal of element is possible only from front

class OutputRestrictedQueue {
    // note: we're using logic of circular queue and not normal queue because of efficient memory use
    public: 
        int *arr;
        int qFront;
        int qRear;
        int size;

        // constructor
        OutputRestrictedQueue(int size) {
            this -> size = size;
            arr = new int[size];
            qFront = -1;
            qRear = -1;
        }

        // behaviour
        void enqueue_front(int data) {
            if((qRear + 1) % size == qFront) {
                cout << "queue is full" << endl;
                return;
            }

            if(qFront == -1) {
                qFront = qRear = 0;
            } 
            // else if(qFront == 0) {
            //     qFront = size - 1;
            // } else {
            //     qFront--;
            // }
            else // use this formula instead of above if else
                qFront = ((qFront - 1) + size) % size;

            arr[qFront] = data;
        }

        void enqueue_rear(int data) {
            if((qFront == 0 && qRear == size - 1) || (qRear == qFront - 1)) {
                // (qRear + 1) % size == qFront use this condition instead
                cout << "queue is full" << endl;
                return ;
            }

            if(qFront == -1) {
                qFront = qRear = 0;
            } else {
                qRear = (qRear + 1) % size;
            }

            arr[qRear] = data;
        }

        void dequeue() {
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
};

void printQueue(OutputRestrictedQueue &q) {
    if(q.qFront == -1) {
        cout << "queue is empty" << endl;
        return;
    }

    int i = q.qFront; // it will start from current front point and not 0 after that it will print elements inserted by equeue_rear()
    do {
        cout << q.arr[i] << " ";
        i = (i + 1) % q.size;
    } while(i != (q.qRear + 1) % q.size || i == q.qRear);
    cout << endl;
}


int main() {

    OutputRestrictedQueue q(6);

    q.enqueue_front(1);
    q.enqueue_front(2);
    q.enqueue_rear(3);
    q.enqueue_rear(4);
    q.enqueue_front(5);
    q.enqueue_rear(6);

    printQueue(q);

    return 0;
}