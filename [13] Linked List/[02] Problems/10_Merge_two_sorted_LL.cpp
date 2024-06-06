#include <iostream>
#include "../lib/singly_linkedlist.cpp"
using namespace std;

// MERGE TWO SORTED LINKED LIST
// time complexity: O(n)
// space complexity: O(1)

// ----- 1. my method -------
Node* merge2SortedLL(Node* &head1, Node* &head2) {
    // if 1st or 2nd list is empty
    if(head1 == NULL || head2 == NULL) return NULL;
    
    Node* prev = NULL;
    Node* nodeOf1 = head1;
    Node* nodeOf2 = head2;
    Node* forward = NULL; // to keep track of next node of currently changing node

    while(nodeOf1 != NULL && nodeOf2 != NULL) {
        if(nodeOf1 -> data >= nodeOf2 -> data) {
            cout << "small found at: " << nodeOf1 -> data << " | " << nodeOf2 -> data << endl;
            if(nodeOf1 == head1) {
                head1 = nodeOf2;
                prev = nodeOf2;
            } else
                prev -> next = nodeOf2;
            
            forward = nodeOf2 -> next;
            nodeOf2 -> next = nodeOf1;
            prev = nodeOf2;
            nodeOf2 = forward;
        } else {
            prev = nodeOf1;
            nodeOf1 = nodeOf1 -> next;
        }
        printLL(head1); cout << endl;
    }

    // don't need to add condition for nodeOf1 != NULL because at this point don't need to traverse till NULL
    if(nodeOf2 != NULL) {
        prev -> next = nodeOf2;
    }

    return head1; // updated head of merged list
} 

// ----- 2. another method to solve -----
Node* solve(Node* first, Node* second) {
    // only one element present
    if(first -> next == NULL) {
        first -> next = second;
        return first;
    }
    
    Node* curr1 = first;
    Node* next1 = first -> next;
    Node* curr2 = second;
    Node* next2 = NULL;

    while(next1 != NULL && curr2 != NULL) {
        if((curr2 -> data >= curr1 -> data) && (curr2 -> data <= next1 -> data)) {
            next2 = curr2 -> next;
            curr1 -> next = curr2;
            curr2 -> next = next1;
            curr1 = curr2;
            curr2 = next2;
        } else {
            curr1 = next1;
            next1 = next1 -> next;

            if(next1 == NULL) {
                curr1 -> next = curr2;
                return first;
            } 
        }
    }

    return first;
}

Node* sortTwoLists(Node* first, Node* second) {
    // if 1st or 2nd list is empty
    if(first == NULL || second == NULL) return NULL;

    if(first -> data <= second -> data) {
        solve(first, second);
    } else {
        solve(second, first);
    }
}

int main() {

    // head and tail of linkedlist 1
    Node* head1 = NULL;
    Node* tail1 = NULL;

    // head and tail of linkedlist 2
    Node* head2 = NULL;
    Node* tail2 = NULL;

    insertAtTail(head1, tail1, 1);
    insertAtTail(head1, tail1, 4);
    insertAtTail(head1, tail1, 5);

    insertAtTail(head2, tail2, 2);
    insertAtTail(head2, tail2, 3);
    insertAtTail(head2, tail2, 5);

    printLL(head1);
    printLL(head2);

    head1 = merge2SortedLL(head1, head2);
    printLL(head1);

    return 0;
}