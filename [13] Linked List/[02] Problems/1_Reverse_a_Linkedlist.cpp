#include <iostream>
#include "../lib/singly_linkedlist.cpp"
using namespace std;

// REVERSE A LINKED LIST USING ITERATIVE WAY
// time complexity: O(n) // n is total number of nodes
// space complexity: O(1) // constant space

void reverseLL(Node* &head, Node* &tail) {
    // empty linked list
    if(head == NULL) {
        cout << "linked list is empty!" << endl;
        return ;
    }

    // only one node exist
    if(head -> next == NULL) 
        return ;

    // more than one nodes are exist
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    tail = curr; // update tail

    while(curr != NULL) {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }

    // update head pointer
    head = prev;
}

int main() {

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);
    printLL(head);

    reverseLL(head, tail);
    printLL(head);

    return 0;
}