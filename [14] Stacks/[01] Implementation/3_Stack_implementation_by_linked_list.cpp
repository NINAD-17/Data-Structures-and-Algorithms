#include <iostream>
#include "../../[13] Linked List/lib/singly_linkedlist.cpp"
using namespace std;

// STACK IMPLEMENTATION BY USING LINKED LIST

class Stack {
    public: 
        Node* head; // to keep track of head of linked list
        Node* tail; // to keep track of tail of linked list
        int top; // to track top. although we can also find top because of head node, we're using top to keep track of availibilty of size for new elements and to stop at size
        int size; // for stack size

        // constructor
        Stack(int size) {
            this -> size = size;
            top = 0;
            head = NULL;
            tail = NULL;
        }

        // operations
        void push(int data) {
            // is size available?
            if(size - top >= 1) {
                insertAtHead(head, tail, data);
                top++; // doen't matter whether you put this above insertHead or below because element is always at the head means top
            } else {
                cout << "oops! stack overflow" << endl;
            }
        }

        void pop() {
            // check if stack is empty or not
            if(top >= 1) {
                deleteNode(head, tail, 1);
                top--;
            } else {
                cout << "oops! stack underflow" << endl;
            }
        }

        int peak() {
            if(top == 0) {
                cout << "stack is empty" << endl;
                return -1;
            } else {
                return head -> data;
            }
        }

        bool isEmpty() {
            if(top == 0)
                return true;
            else
                return false;
        }
};

void printStack(Stack st) {
    Node* head = st.head;
    if(head == NULL) {
        cout << "stack is empty" << endl;
        return;
    }

    cout << "printing stack: (top) ";
    Node* tempNode = head;
    while(tempNode != NULL) {
        cout << tempNode -> data << " -> ";
        tempNode = tempNode -> next;
    } 
    cout << "(bottom)" << endl << endl;
}

int main() {

    Node* head = NULL;
    Node* tail = NULL;
    
    Stack st(5);

    st.pop(); // stack underflow

    st.push(10);
    cout << "top of stack: " << st.peak() << endl;

    st.push(20);
    cout << "top of stack: " << st.peak() << endl;

    st.push(30);
    cout << "top of stack: " << st.peak() << endl;

    st.push(40);
    cout << "top of stack: " << st.peak() << endl;

    st.push(50);
    cout << "top of stack: " << st.peak() << endl;

    st.push(60); // stack overflow
    cout << "top of stack: " << st.peak() << endl;

    st.pop();
    cout << "top of stack: " << st.peak() << endl;

    printStack(st);

    return 0;
}