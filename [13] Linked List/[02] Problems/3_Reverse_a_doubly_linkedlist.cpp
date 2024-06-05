#include <iostream>
#include "../lib/doubly_linkedlist.cpp"
using namespace std;

// 1. REVERSE A DOUBLY LINKED LIST USING ITERATIVE APPROACH
// time complexity: O(n)
// space complexity: O(1)

void reverseDoublyLL(Node* &head, Node* &tail) {
    // zero or one nodes
    if(head == NULL || head -> next == NULL)
        return ;
    
    tail = head; // update tail

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr -> next;

    while(curr != NULL) {
        forward = curr -> next;
        curr -> prev = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }

    head = prev;
}

// 2. REVERSE A DOUBLY LINKED LIST USING RECURSIVE APPROACH
Node* reverseDLL(Node* head) {
    // base case
    if(head == NULL || head -> next == NULL) 
        return head;
    
    Node* newHead = reverseDLL(head -> next);
    head -> prev = head -> next;
    head -> next -> next = head;
    head -> next = NULL;

    return newHead;
}

// 3. USING RECURSIVE APPROACH 2
void reverseDLL_2(Node* &head, Node* prev, Node* curr) {
    // base case
    if(curr == NULL) {
        head = prev;
        return ;
    }

    Node* forward = curr -> next;
    reverseDLL_2(head, curr, forward);
    curr -> prev = curr -> next;
    curr -> next = prev;
}


int main() {

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);
    printLL(head, tail);

    reverseDoublyLL(head, tail);
    printLL(head, tail);

    head = reverseDLL(head);
    printLL(head, tail);

    reverseDLL_2(head, NULL, head);
    printLL(head, tail);

    return 0;
}