#include <iostream>
#include "../lib/singly_linkedlist.cpp"
using namespace std;

// MIDDLE OF LINKED LIST

// optimised approach
// time complextity: O(n)
Node* getMiddleOfLL_2(Node* &head) {
    // empty linked list || only one node
    if(head == NULL || head -> next == NULL) return head;

    Node* slow = head;
    Node* fast = head; // YT tut: you can use fast = head -> next
    while(fast != NULL && fast -> next != NULL) { // YT tut: only one condition -> fast != NULL
        // fast = fast -> next -> next; // you're not checking if the node is null or not
        fast = fast -> next;
        if(fast != NULL) fast = fast -> next;
        slow = slow -> next;
    }

    return slow;
}

// time complexity: O(n)
Node* getMiddleOfLL(Node* head) {
    if(head == NULL) return NULL; // empty linked list
    int middleNode = (getLengthOfLL(head) / 2) + 1;

    int cnt = 1;
    while(cnt != middleNode) { 
        head = head -> next;
        cnt++;
    }

    return head; // middle node
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);
    insertAtTail(head, tail, 60);
    printLL(head);

    cout << "middle node of linked list is node with data " << getMiddleOfLL(head) -> data << endl;
    cout << "middle node of linked list is node with data " << getMiddleOfLL_2(head)->data << endl;
    return 0;
}