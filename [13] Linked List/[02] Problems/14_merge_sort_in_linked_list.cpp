#include <iostream>
#include "../lib/singly_linkedlist.cpp"
using namespace std;

// (IMP) learn: Why Quick Sort preferred for Arrays and Merge Sort for Linked Lists?
// link of artical: https://www.geeksforgeeks.org/why-quick-sort-preferred-for-arrays-and-merge-sort-for-linked-lists/

// MERGE SORT IN LINKED LIST
// data replacement isn't allowed, only change the links between nodes

// time complexity: O(n log(n))
// space complexity: O(log n)

Node* findMid(Node* &head) {
    // make fast and slow pointer
    Node* slow = head;
    Node* fast = head -> next;

    while(fast != NULL && fast -> next != NULL) {
        fast = fast -> next;
        if(fast != NULL) 
            fast = fast -> next;
        slow = slow -> next;
    }

    return slow;
}

// Note: see image from readme.md if you don't understand below merge code.
Node* mergeTwoSortedLL(Node* &left, Node* &right) {
    // if one of the part (left or right) is null then return other part
    if(left == NULL)
        return right;
    
    if(right == NULL)
        return left;

    Node* ans = new Node(-1);
    Node* temp = ans;

    // merge two sorted linked list
    while(left != NULL && right != NULL) {
        if(left -> data < right -> data) {
            temp -> next = left;
            temp = left;
            left = left -> next;
        } else {
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }

    while(left != NULL) {
        temp -> next = left;
        temp = left;
        left = left -> next;
    }

    while(right != NULL) {
        temp -> next = right;
        temp = right;
        right = right -> next;
    }

    // as first node is -1,
    ans = ans -> next;
    return ans;
}

Node* mergeSort(Node* &head) {
    // base case: only one or no element present in the linked list
    if(head == NULL || head -> next == NULL)
        return head;

    // find mid
    Node* mid = findMid(head);

    // make two part of linked list as we do in merge sort
    Node* left = head;
    Node* right = mid -> next;
    mid -> next = NULL; // mid node is the last node in left part so we've to unlink it from right part by pointing its next to NULL

    // recursive call to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    // merge two sorted linked list (left and right)
    Node* result = mergeTwoSortedLL(left, right);

    // return the head of sorted linked list
    return result;
}

int main() {

    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 6);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 2);
    printLL(head);

    Node* ans = mergeSort(head);
    printLL(ans);

    return 0;
}