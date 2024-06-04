#include <iostream>
#include "../lib/singly_linkedlist.cpp"
using namespace std;

// REVERSE A LINKED LIST USING RECURSIVE WAY
// time complexity: O(n) // n is total number of nodes
// space complexity: O(n) // each function (n functions) in recursive stack will take constant space. therefore O(k * n) = O(n) ... k = constant

Node* recursiveCall_2(Node* head) {
    // base case
    if(head == NULL || head -> next == NULL)
        return head;
    
    Node* newHead = recursiveCall_2(head -> next);
    head -> next -> next = head;
    head -> next = NULL;

    return newHead;
}

void recursiveCall(Node* &head, Node* curr, Node* prev) {
    // base case
    if(curr == NULL) {
        head = prev;
        return;
    }

    Node* forward = curr -> next;
    recursiveCall(head, forward, curr);
    curr -> next = prev;
}

void reverseLL(Node* &head, Node* &tail) {
    Node* prev = NULL;
    Node* curr = head;

    // recursiveCall(head, curr, prev);
    head = recursiveCall_2(head);
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