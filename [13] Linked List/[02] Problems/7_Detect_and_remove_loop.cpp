#include <iostream>
#include <map>
#include "../lib/circular_linkedlist.cpp"
using namespace std;

// 1. DETECT CYCLE IN LINKED LIST
// 2. REMOVE CYCLE FROM LINKED LIST
// 3. GIVE START NODE OF LOOP IN LINKED LIST

// -------------- floyd's cycle detection algorithm --------------
// time complexity: O(n)
// space complexity: O(1)
Node* detectLoop(Node* &tail) {
    if(tail == NULL) return NULL;

    Node* slow = tail;
    Node* fast = tail;
    while(fast != NULL) {
        fast = fast -> next;
        if(fast != NULL) 
            fast = fast -> next;
        slow = slow -> next;

        if(slow == fast)
            return fast;
    }

    return NULL;
}

Node* getStartingNode(Node* &tail) {
    if(tail == NULL) return NULL;

    Node* intersection = detectLoop(tail);
    Node* slow = tail;

    cout << "inter: " << intersection -> data << endl;
    if(intersection == NULL) return NULL;

    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }

    return slow; // both pointers reached to the same node (starting node)
}

void removeLoop_floyd(Node* &tail) {
    if(tail == NULL) return;

    Node* startOfLoop = getStartingNode(tail);
    Node* tempNode = startOfLoop;

    while(tempNode -> next != startOfLoop) {
        tempNode = tempNode -> next;
    }

    tempNode -> next = NULL;
}

// -------------- optimised approach -----------------------
// time complexity: O(n)
// space complexity: O(1)
void removeCycle_2(Node* &tail) {
    if(tail == NULL) return;

    Node* tempNode = tail -> next;
    while(tempNode != tail) {
        tempNode = tempNode -> next;
    }

    tail -> next = NULL;
}

Node* detectCycle_2(Node* &tail) {
    if(tail == NULL) return NULL; // empty linked list

    // only one node present
    if(tail -> next == tail) return tail;

    Node* tempNode = tail -> next;
    while(tempNode != NULL && tempNode != tail) {
        tempNode = tempNode -> next;
    }

    if(tempNode == NULL)
        return NULL;
    
    if(tempNode -> next != NULL)
        return tail -> next;
}   

// -------------------- not optimised (using map) ----------------------
// time complexity: O(n)
// space complexity: O(n) .. to store each (n nodes) node in map.
void removeCycle(Node* &tail) {
    // if linkedlist is empty
    if(tail == NULL) return;

    Node* prevNode = NULL;
    Node* currNode = tail;
    map<Node*, bool> visited;

    while(currNode != NULL && visited[currNode] != true) {
        prevNode = currNode;
        currNode = currNode -> next;
        visited[currNode] = true;
    }

    if(visited[currNode]) 
        prevNode -> next = NULL;

    return;
}

Node* detectCycle(Node* &tail) {
    // if linkedlist is empty
    if(tail == NULL) return NULL;

    Node* tempNode = tail;
    map<Node*, bool> visited;

    while(tempNode != NULL && visited[tempNode] != true) {
        tempNode = tempNode -> next;
        visited[tempNode] = true;
    }

    if(visited[tempNode]) 
        return tempNode;
    
    return NULL;
}

int main() {
    Node* tail = NULL;

    insertNode(tail, 1, 10);
    insertNode(tail, 10, 20);
    insertNode(tail, 20, 30);
    Node* tempNode = tail; // node with data 30
    insertNode(tail, 30, 40);
    insertNode(tail, 40, 50);
    printLL(tail);
    
    tail -> next = tempNode; // making a loop
    // removeCycle_2(tail); // to remove loop present in the linked list

    // Node* loopHead = detectCycle(tail);
    // Node* loopHead = detectCycle_2(tail);
    // Node* loopHead = detectLoop(tail);
    cout << detectCycle(tail) -> data << endl;
    cout << detectLoop(tail) -> data << endl;
    Node* loopHead = getStartingNode(tail);
    if(loopHead != NULL) {
        cout << "starting node of the loop is " << loopHead -> data << endl;
        cout << "loop is present in the linked list" << endl;
    }
    else
        cout << "there's no loop in the linked list" << endl;

    return 0;
}