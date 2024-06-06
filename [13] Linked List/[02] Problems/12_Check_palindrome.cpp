#include <iostream>
#include "../lib/singly_linkedlist.cpp"
using namespace std;

// CHECK IF LINKED LIST IS PALINDROME

// --- 1. by reversing linkedlist from middle ---
// time complexity: O(n)
// space complexity: O(1)
Node* reverseLL(Node* head) {
    // base case
    if(head == NULL || head -> next == NULL)
        return head;
    
    Node* newHead = reverseLL(head -> next);
    head -> next -> next = head;
    head -> next = NULL;

    return newHead;
}

// get mid using floyd's algorithm
Node* getMid(Node* &head) {
    Node* slow = head;
    Node* fast = head -> next;

    while(fast != NULL && fast -> next != NULL) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }

    return slow;
}

bool isPalin(Node* &head) {
    // empty linkedlist
    if(head == NULL) return false;

    // only one node present
    if(head -> next == NULL) return true;

    // step 1: get mid
    Node* midNode = getMid(head);

    // step 2: reverse list after mid node
    Node* tempNode = midNode -> next;
    midNode -> next = reverseLL(tempNode);

    // step 3: compare both halves
    Node* head1 = head;
    Node* head2 = midNode -> next;

    while(head2 != NULL) {
        if(head1 -> data != head2 -> data)
            return false;
        head1 = head1 -> next;
        head2 = head2 -> next;
    }

    // step 4: (optional) make linked list as it is (original) by reversing back the second halve
    midNode -> next = reverseLL(tempNode);

    return true;
}

// --- 2. using the help of array ---
// time complexity: O(n)
// space complexity: O(n) because we create n size of array (size of linkedlist)
bool check(int* arr, int size) {
    int st = 0;
    int en = size;

    while(st <= en) {
        if(arr[st++] != arr[en--])
            return false;
    }

    return true;
}

bool isPalindrome(Node* &head) {
    // empty linkedlist
    if(head == NULL) return false;

    // only one node present
    if(head -> next == NULL) return true;

    Node* tempNode = head;
    int listSize = getLengthOfLL(head);

    // note: if you don't want to get size of linked list and make array then you can use vector<int>
    int *arr = new int[listSize]; // create new array of size listSize
    int i = 0;

    while(tempNode != NULL) {
        arr[i++] = tempNode -> data;
        tempNode = tempNode -> next;
    }

    bool result = check(arr, listSize - 1); // because arr starts from 0
    delete arr; // delete allocated memory from heap

    return result;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 1);

    printLL(head);

    if(isPalin(head))
        cout << "given linked list is palindrome" << endl;
    else    
        cout << "given linked list isn't a palindrome" << endl;
        
    return 0;
}