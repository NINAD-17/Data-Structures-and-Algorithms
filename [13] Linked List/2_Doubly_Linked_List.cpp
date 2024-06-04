#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* prev;
        Node* next;

        // constructor
        Node(int data) {
            this -> data = data;
            this -> prev = NULL;
            this -> next = NULL;
        }

        // destructor
        ~Node() {
            int data = this -> data;
            if(this -> next != NULL) {
                delete next;
                this -> next = NULL;
            }
            cout << "memory freed for node with data " << data << endl;
        }
};

void createLL(Node* &head, Node* &tail, int data) {
    // allocate memory in heap
    Node* newNode = new Node(data);
    head = newNode;
    tail = newNode;
    cout << "--- new linked list created ---" << endl;
}

void insertAtHead(Node* &head, Node* &tail, int data) {
    // if head and tail is null means linked list isn't exist
    if(head == NULL) {
        createLL(head, tail, data);
        return ;
    }

    // allocate memory in heap for new node
    Node* newNode = new Node(data);

    newNode -> next = head;
    head -> prev = newNode;
    head = newNode;
}

void insertAtTail(Node* &head, Node* &tail, int data) {
    // if head and tail is null means linked list isn't exist
    if(tail == NULL) {
        createLL(head, tail, data);
        return ;
    }

    // allocate memory in heap for new node
    Node* newNode = new Node(data);

    newNode -> prev = tail;
    tail -> next = newNode;
    tail = newNode;
}

void insertInMiddle(Node* &head, Node* &tail, int data, int pos) {
    // allocate memory in heap for new node
    Node* newNode = new Node(data);

    // pos = 1 that is insert at head
    if(pos == 1) {
        insertAtHead(head, tail, data);
        return;
    } 

    // pos other that 1 (middle position)
    Node* tempNode = head;
    int tempPos = 1;

    while(tempPos < (pos - 1) && tempNode != NULL) {
        tempNode = tempNode -> next;
        tempPos++;
    }

    // if position is greater than current linked list size/length
    if(tempNode == NULL || pos <= 0) {
        cout << "--- please enter valid node pos ---" << endl;
        return ; 
    }

    // last position: insert at tail
    if(tempNode -> next == NULL) {
        insertAtTail(head, tail, data);
        return;
    }

    newNode -> next = tempNode -> next;
    tempNode -> next -> prev = newNode;
    tempNode -> next = newNode;
    newNode -> prev = tempNode;
}

void deleteNode(Node* &head, Node* &tail, int pos) {
    Node* currNode = head;

    // delete node from 1st position
    if(pos == 1) {
        if(head -> next == NULL) { // only one node present in LL
            head = NULL;
            tail = NULL;
        } else { // more than one nodes in LL
            head->next->prev = NULL;
            head = head->next;
        }
        currNode -> next = NULL;
        delete currNode;
        return;
    }

    Node* prevNode = NULL;
    // currNode = head; // already defined
    int cnt = 1;

    while(cnt < pos && currNode -> next != NULL) {
        prevNode = currNode;
        currNode = currNode -> next;
        cnt++;
    }

    if(cnt <= 0 || cnt != pos) {
        cout << "--- please enter valid position of node ---" << endl;
        return ;
    }

    if(currNode -> next == NULL)
        tail = prevNode; // Update tail if deleting the last node

    prevNode -> next = currNode -> next;

    if(currNode -> next != NULL)
        currNode -> next -> prev = currNode -> prev; // because last node's next is null so it's not applicable for last node.

    currNode -> next = NULL;
    currNode -> prev = NULL;
    delete currNode;
} 

void getLengthOfLL(Node* &head) {
    Node* temp = head;  
    int len = 0;

    while(temp != NULL) {
        len++;
        temp = temp -> next;
    }

    cout << "Lenth of linked list is " << len << endl;
}

void printLL(Node* &head, Node* &tail) {
    if(head == NULL) {
        cout << "linked list is empty or not exist :(" << endl;
        cout << "head node: " << head << "\t|\ttail node: " << tail << endl << endl;
        return;
    }

    Node* temp = head; // It's good for readability. otherwise I also can able to directly use head by passing it by value.
    cout << "printing LL: ";
    while(temp != NULL) {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << "NULL" << endl;
    cout << "head node: " << head -> data << "\t|\ttail node: " << tail -> data << endl << endl;
}

int main() {

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 10);
    printLL(head, tail);

    insertAtTail(head, tail, 20);
    printLL(head, tail);

    insertInMiddle(head, tail, 30, 2);
    printLL(head, tail);

    insertInMiddle(head, tail, 40, 1);
    // insertInMiddle(head, tail, 50, 6);
    insertInMiddle(head, tail, 60, 7);
    insertInMiddle(head, tail, 70, 0);
    printLL(head, tail);

    deleteNode(head, tail, 5);
    deleteNode(head, tail, 4);
    deleteNode(head, tail, 3);
    deleteNode(head, tail, 1);
    deleteNode(head, tail, 1);
    printLL(head, tail);

    return 0;
}