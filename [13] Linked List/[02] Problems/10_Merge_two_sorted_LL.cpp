#include <iostream>
#include "../lib/singly_linkedlist.cpp"
using namespace std;

// MERGE TWO SORTED LINKED LIST
// time complexity: O(n)
// space complexity: O(1)

// ----- 1. my method -------
// see the image from readme.md file - contain dry run for this code.
Node* merge2SortedLL(Node* &head1, Node* &head2) {
    // if 1st or 2nd list is empty
    if(head1 == NULL || head2 == NULL) return NULL;
    
    // we only need one prev and one forward because we're merging two linked list in one
    Node* prev = NULL;
    Node* nodeOf1 = head1;
    Node* nodeOf2 = head2;
    Node* forward = NULL; // to keep track of next node of currently changing node

    while(nodeOf1 != NULL && nodeOf2 != NULL) {
        if(nodeOf1 -> data >= nodeOf2 -> data) { // node1 >= node2 so we need to change the links between nodes so that node2 which is smaller than node1 will place before node1
            cout << "small found at: " << nodeOf1 -> data << " | " << nodeOf2 -> data << endl;
            if(nodeOf1 == head1) { // if the first element of node1 is greater than node1 means we need to process it. after processing node2 is first element and node1 is second so change head to node2
                head1 = nodeOf2;
                prev = nodeOf2;
            } else
                prev -> next = nodeOf2; // as the node1 is big and node2 element is small we need to add node2 element in between prev and node1
            
            forward = nodeOf2 -> next; 
            nodeOf2 -> next = nodeOf1; // prev is pointing to node2 so now we point node2 to node1 means it's now in between prev and node1 i.e sorted
            prev = nodeOf2;
            nodeOf2 = forward;
        } else { // here node1 is smaller than node2 it means there's no need to process means node1's element is at right position. so go to next node of node1
            prev = nodeOf1;
            nodeOf1 = nodeOf1 -> next;
        }
        printLL(head1); cout << endl;
    }

    // don't need to add condition for nodeOf1 != NULL because at this point don't need to traverse till NULL
    // if nodeOf1 isn't NULL but nodeOf2 is NULL in this case all is sorted. As you've attach all the nodes in node1 linked list you don't need to do anything now.
    while(nodeOf2 != NULL) { // in this stage nodeOf1 is now NULL but nodeOf2 isn't, so we need to add rest elements in linkedlist node1. So we're attaching all the elements at the end of node1 linked list
        prev -> next = nodeOf2;
    }

    return head1; // updated head of merged list
} 

// ----- 2. another method to solve -----
Node* solve(Node* first, Node* second) {
    // only one element present in the linkedlist whose 1st element is smaller than second linkedlist
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

// 3. 
// Note: see image from readme.md if you don't understand below merge code.
Node* mergeTwoSortedLL3(Node* &left, Node* &right) {
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

    head1 = merge2SortedLL(head2, head1);
    printLL(head1);

    return 0;
}