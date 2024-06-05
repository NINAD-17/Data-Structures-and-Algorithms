#include <iostream>
#include <map>
#include "../lib/circular_linkedlist.cpp"
using namespace std;

// IS THE LINKED LIST CIRCULAR OR NOT
// time complexity: O(n)
// space complexity: O(1)

bool isCircularLL(Node* &tail) {
    // empty linkedlist
    if(tail == NULL) {
        cout << "linkedlist is empty" << endl;
        return 0;
    }

    Node* tempNode = tail -> next;
    while(tempNode != NULL && tempNode != tail) 
        tempNode = tempNode -> next;

    // if(tempNode == NULL) 
    //     return false;
    
    if(tempNode == tail)
        return true;
}

// time complexity: O(n)
// space complexity: O(n) .. to store each (n nodes) node in map
bool isCircularUsingMap(Node* &tail) {
    // empty linkedlist
    if(tail == NULL) {
        cout << "linkedlist is empty" << endl;
        return 0;
    }

    Node* tempNode = tail -> next;
    map<Node*, bool> isVisited;
    while(tempNode != NULL && isVisited[tempNode] != true) {
        tempNode = tempNode -> next;
        isVisited[tempNode] = true;
    }

    if(isVisited[tempNode])
        return true;
    
    return false;
}

// singular linkedlist's print function
void printLLL(Node* &head) { // We're passing it by reference to not create another node for head (for efficiency)
    if(head == NULL) {
        cout << "linked list is empty or not exist :(" << endl;
        cout << "head node: " << head << endl << endl;
        return;
    }

    Node* temp = head;
    cout << "Printing LinkedList: ";
    while(temp != NULL) { // If you write 'temp -> next != NULL' then it will stop before printing last node.
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }

    cout << "NULL" << endl;
}

int main() {
    Node* tail = NULL;

    // circular linkedlist
    insertNode(tail, 0, 3);
    insertNode(tail, 3, 2);
    insertNode(tail, 2, 7);
    insertNode(tail, 7, 8);
    insertNode(tail, 8, 9);
    insertNode(tail, 9, 10);
    
    // to check is the code is correct or not make it singly linkedlist
    // tail -> next = NULL;
    // printLLL(tail);

    printLL(tail); // circular linkedlist's printLL function

    // is it circular
    if(isCircularUsingMap(tail))
        cout << "it's a circular linked list" << endl;
    else
        cout << "it's not a circular linked list" << endl;

    return 0;
}