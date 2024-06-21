#include <iostream>
using namespace std;

class Node {
    public:
        int data; // data in that node
        Node* next; // pointer of node type

        // constructor
        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }

        // destructor
        ~Node() {
            int data = this -> data;
            // memory free
            if(this -> next != NULL) {
                delete next;
                this -> next = NULL;
            }
            cout << "memory freed for node with data " << data << endl;
        }
};

void createNewLL(Node* &head, Node* &tail, int data) {
    // allocate memory in heap for new node
    Node* newNode = new Node(data);

    // set head and tail points to newNode
    head = newNode;
    tail = newNode;
}

void insertAtHead(Node* &head, Node* &tail, int data) { // 'pass by reference' otherwise it will not change the actual head in main function
    // allocate memory in heap for new node
    Node* newNode = new Node(data);

    // if head is null, means linkedlist doesn't exist then,
    if(head == NULL) {
        // head = newNode;
        // tail = newNode;
        // return; // if you forget to return then due to further logic "newNode -> next = head (it must be NULL)" therefore while printing it will get stuck in an infinite loop

        createNewLL(head, tail, data);
        return;
    }
    
    // attaching it to 1st position of LinkedList
    newNode -> next = head;
    head = newNode; // If you 'passed it by value' then this change is temporarily and you don't able to print updated linked list
}

void insertAtTail(Node* &head, Node* &tail, int data) {
    // allocate memory in heap for new node
    Node* newNode = new Node(data);

    // if tail is NULL, it means linked list is not exist so create one,
    if(tail == NULL) {
        createNewLL(head, tail, data);
        return;
    }
    
    // attaching new node at the tail of LL
    tail -> next = newNode;
    tail = newNode; // Or you can write `tail = tail -> next;`
}

void insertInMiddle(Node* &head, Node* &tail, int data, int pos) {
    // allocate memory in heap for new node
    Node* newNode = new Node(data);

    // if head == NULL, linked list not exist. Although without this logic it will not get stuck because of further code. But it will not create new linked list. It will show message that tells "please enter valid position"
    if(head == NULL) {
        createNewLL(head, tail, data);
        return ;
    }

    // if pos is 1, means insert at head
    if(pos == 1) {
        insertAtHead(head, tail, data);
        return ;
    }

    // for other pos we will traverse LL to get that (pos - 1) node
    int tempPos = 1;
    Node* tempNode = head;
    while(tempPos < (pos - 1) && tempNode != NULL) { // `tempNode != NULL` used to prevent it to traverse out of the linkedlist.
        tempNode = tempNode -> next;
        tempPos++;
    }
    // note: in above while function <= is for input "pos = 0" and "tempNode != NULL" is for input "pos" which is greater that size of linked list.

    // if position is greater than current linked list size/length
    if(tempNode == NULL || pos <= 0) {
        cout << "---- please enter valid position  ---" << endl;
        return;
    }

    // if tempNode is tail node then use insertAtTail
    if(tempNode -> next == NULL) {
        insertAtTail(head, tail, data); // need this to update tail node otherwise code will work fine
        return ;
    }

    // if it's middle node then,
    newNode -> next = tempNode -> next;
    tempNode -> next = newNode;
}

void deleteNode(Node* &head, Node* &tail, int pos) {
    Node* temp = head;

    // 1st Node to delete
    if(pos == 1) {
        if(head -> next == NULL) { // only one element is in linkedlist. after deletion head and tail must be NULL
            head = NULL;
            tail = NULL;
        } else {
            head = head -> next;
        }
        temp -> next = NULL;
        delete temp;
        return ;
    }

    // other pos node to delete
    Node* prev = NULL;
    Node* curr = head;

    int cnt = 1;
    while(cnt < pos && curr -> next != NULL) {
        prev = curr;
        curr = curr -> next;
        cnt++;
    }

    // if the pos is greater than size of LL
    if(cnt != pos) { // after last iteration cnt should be equal to pos
        cout << "--- please enter valid node pos to delete ---" << endl;
        return ;
    }

    // tail node update
    if(curr -> next == NULL)
        tail = prev;

    prev -> next = curr -> next;
    curr -> next = NULL;
    delete curr;
}

void deleteNodeWithData(Node* &head, Node* &tail, int data) {
    int cnt = 1;
    Node* curr = head;

    // if node found on 1st position (head)
    if(data == head -> data) {
        if(head -> next == NULL) {
            head = NULL;
            tail = NULL;
        } else {
            head = head -> next;
        }
        curr -> next = NULL;
        delete curr;
        return ;
    }

    // node found in middle
    Node* prev = NULL;
    curr = head;

    while(curr -> data != data && curr -> next != NULL) {
        prev = curr;
        curr = curr -> next;
    }

    // data found
    if(curr -> data == data) {
        if(curr -> next == NULL) 
            tail = prev; // update tail
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    } else {
        cout << data << " not found in linked list :(" << endl;
    }
}

void getLengthOfLL(Node* &head) {
    if(head == NULL) {
        cout << "linked list is empty" << endl;
        return;
    }

    Node* temp = head;  
    int len = 0;

    while(temp != NULL) {
        len++;
        temp = temp -> next;
    }

    cout << "Lenth of linked list is " << len << endl;
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

    /* ------- learn what if head and tail is null (creation of new linked list) [my implementation] ----- */
    // Node* head = NULL;
    // Node* tail = NULL;

    // // insertAtHead(head, tail, 10);
    // // insertAtTail(head, tail, 50);
    // // insertInMiddle(head, tail, 30, 1);
    // printLL(head);


    /* ------ learn with the flow of youtube video -----*/
    // --- allocate memory in heap for Node
    Node* node1 = new Node(10); // we used Node() and not Node only because if we don't use () then it will not call default constructor automatically unlike we're doing initialization while static allocation. "Node h;"
    // using only Node; give you random value and not default one.

    // --- printing data and address of next node 
    cout << "Data: " << node1 -> data << endl;
    cout << "Address: " << node1 -> next << endl;

    // --- head pointer (starting node of linked list)
    Node* head = node1;
    Node* tail = node1;
    // cout << "Data of head: " << head -> data << endl;
    // cout << "Next node's address: " << head -> next << endl << endl;

    // --- insert node at 1st position (as a starting node)
    insertAtHead(head, tail, 20);
    printLL(head);

    // --- insert node at the tail of LL
    insertAtTail(head, tail, 30);
    printLL(head);

    // --- insert node in middle
    insertInMiddle(head, tail, 40, 0); // 0th position case
    // insertInMiddle(head, tail, 40, 5); // pos greater than orinal length of LL case

    insertInMiddle(head, tail, 60, 2);
    printLL(head);

    // deleteNode(head, tail, 5); // deleting at pos greater than actual length of LL
    deleteNode(head, tail, 4);
    deleteNode(head, tail, 2);
    deleteNodeWithData(head, tail, 20);
    // deleteNodeWithData(head, tail, 60);
    // deleteNodeWithData(head, tail, 10);
    printLL(head);

    // deleteNodeWithData(head, tail, 10);
    deleteNode(head, tail, 1);
    printLL(head);
    // cout << "head: " << head -> data << endl;
    // cout << "tail: " << tail -> data << endl;
    getLengthOfLL(head);

    return 0;
}