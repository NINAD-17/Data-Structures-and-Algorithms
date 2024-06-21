#include <iostream>
using namespace std;

class Node {
    public: 
        int data;
        Node* next;
        Node* child;

        // constructor
        Node(int data) {
            this -> data = data;
            this -> next = NULL;
            this -> child = NULL;
        }
};

void flattenTheLL(Node* &head) {
    Node* tempNode = head;

    while(tempNode != NULL) {
        if(tempNode -> child != NULL) {
            Node* curr = tempNode;
            Node* forward = tempNode -> next;
            Node* childPtr = tempNode -> child;
            while(tempNode -> child -> next != NULL)
                childPtr = childPtr -> next;
            childPtr -> next = tempNode -> next;
            curr -> next = curr -> child;
        }

        tempNode = tempNode -> next;
    }
}

void printLLChild(Node* &head) { // We're passing it by reference to not create another node for head (for efficiency)
    if(head == NULL) {
        cout << "linked list is empty or not exist :(" << endl;
        cout << "head node: " << head << endl << endl;
        return;
    }

    Node* temp = head;
    cout << "Printing Linked List with each node's children" << endl;
    while(temp != NULL) { // If you write 'temp -> next != NULL' then it will stop before printing last node.
        cout << temp -> data << " -> ";
        while(temp -> child != NULL) {
            cout << temp -> child -> data << " -> ";
            temp -> child = temp -> child -> next;
        }
        cout << "NULL" << endl;
        cout << "⬇" << endl;
        temp = temp -> next;
    }

    cout << "NULL" << endl << endl;
}

void printLL(Node* &head) { // We're passing it by reference to not create another node for head (for efficiency)
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

    Node* node1 = new Node(1);
    Node* node2 = new Node(4);
    Node* node3 = new Node(7);
    Node* node4 = new Node(9);
    Node* node5 = new Node(20);

    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;

    Node* child1 = new Node(2);
    Node* child2 = new Node(3);
    Node* child3 = new Node(5);
    Node* child4 = new Node(6);
    Node* child5 = new Node(8);
    Node* child6 = new Node(12);

    node1 -> child = child1;
    child1 -> next = child2;

    node2 -> child = child3;
    child3 -> next = child4;

    node3 -> child = child5;
    node4 -> child = child6;

    printLLChild(node1);

    flattenTheLL(node1);
    printLL(node1);

    return 0;
}