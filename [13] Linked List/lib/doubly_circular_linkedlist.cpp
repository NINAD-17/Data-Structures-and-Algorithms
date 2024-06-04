#include <iostream>
using namespace std;

class Node {
    public: 
        int data;
        Node* next;
        Node* prev;

        // constructor
        Node(int data) {
            this -> data = data;
            this -> next = NULL;
            this -> prev = NULL;
        }

        // destructor
};

void createLL(Node* &tail, int data) {
    // allocate memory in heap for new node
    Node* newNode = new Node(data);
    newNode -> next = newNode;
    newNode -> prev = newNode;
    tail = newNode;
    cout << "new linkedlist created!" << endl;
}

void insertNode(Node* &tail, int element, int data) {
    // empty linked list
    if(tail == NULL) {
        createLL(tail, data);
        return;
    }

    // non-empty linked list
    Node* tempNode = tail -> next;
    while(tempNode -> data != element) {
        if(tempNode == tail) {
            break;
        }
        tempNode = tempNode -> next;
    }

    if(tempNode -> data != element && tempNode == tail) {
        cout << "element not found in linked list :(" << endl;
        return;
    }

    Node* newNode = new Node(data);
    if(tempNode -> data == element && tempNode == tail) 
        tail = newNode;

    newNode -> next = tempNode -> next;
    tempNode -> next -> prev = newNode;
    tempNode -> next = newNode;
    newNode -> prev = tempNode;
}

void deleteNode(Node* &tail, int nodeToDelete) {
    // if linked list isn't exist
    if(tail == NULL) {
        cout << "linked list isn't exist!" << endl;
        return;
    }

    // only one node exist
    if(tail -> next == tail && tail -> data == nodeToDelete) {
        tail -> next = NULL;
        tail -> prev = NULL;
        delete tail;
        tail = NULL;
        return;
    }

    // more than one node exist
    Node* prevNode = tail;
    Node* currNode = tail -> next;

    while(currNode -> data != nodeToDelete) {
        if(currNode == tail)
            break;
        prevNode = currNode;
        currNode = currNode -> next;
    }

    if(currNode -> data != nodeToDelete && currNode == tail) {
        cout << "--- please enter a valid node to delete ---" << endl;
        return;
    }

    if(currNode == tail) 
        tail = currNode -> next;
    
    prevNode -> next = currNode -> next;
    currNode -> next -> prev = prevNode;
    currNode -> next = NULL;
    currNode -> prev = NULL;
    delete currNode;
}

void printLL(Node* &tail) {
    Node* temp = tail;

    if(tail == NULL) {
        cout << "linked list is empty or not exist :(" << endl;
        cout << "tail node: " << tail << endl << endl;
        return;
    }

    cout << "\nprinting LL: ";
    do {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    } while (temp != tail);

    cout << "NULL" << endl;
    cout << "tail: " << tail->data << endl;
}