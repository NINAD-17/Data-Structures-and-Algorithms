#include <iostream>
using namespace std;

// STACK IMPLEMENTATION USING ARRAY
// all operations are using O(1) time complexity

class Stack {
    // properties
    public: 
        int *arr;
        int top;
        int size;

        // behaviour
        // constructor
        Stack(int size) {
            this -> size = size; // size of stack
            arr = new int[size]; // allocate memory of size comes from parameter in heap memory
            top = -1;
        }

        void push(int element) {
            // is size available?
            if(size - top > 1) {
                top++;
                arr[top] = element;
            } else {
                cout << "oops! stack overflow" << endl;
            }
        }

        void pop() {
            // if at-least one element is present
            if(top >= 0) {
                top--;
            } else {    
                cout << "oops! stack underflow" << endl;
            }
        }

        int peak() {
            if(top >= 0)
                return arr[top];
            else {
                cout << "stack is empty" << endl;
                return -1;
            }
        }

        bool isEmpty() {
            if(top == -1)
                return true;
            else 
                return false;
        }
};

// note: below logic will not work in stack<int>
// below logic is written by considering stack is implemented with array
// but in stack you can't traverse back means you can able to access element like array
// you only know about top of stack element
// so below logic can be modified by removing s.top() at each iteration
// see example in '../[02] Problems/2_Reverse_a_string_using_stack.cpp'
void printStack(Stack &st) { 
    // check if stack is empty or not
    if(st.isEmpty()) {
        cout << "stack is empty!" << endl;
        return ;
    }

    cout << "printing stack elements: \n";
    cout << "\t\ttop" << endl;
    int topOfStack = st.top;
    while(topOfStack != -1) {
        cout << "\t\t" << st.arr[topOfStack] << "\n";
        topOfStack--;
    }
    cout << "\t\tbottom" << endl << endl;
}

int main() {

    // create stack of size 5
    Stack st(5);
    printStack(st);

    st.push(22);
    printStack(st);

    st.push(43);
    printStack(st);

    st.push(65);
    printStack(st);
    cout << "top of stack: " << st.peak() << endl;

    st.pop();
    printStack(st);
    cout << "top of stack: " << st.peak() << endl;

    st.pop();
    cout << "top of stack: " << st.peak() << endl;

    st.pop();
    cout << "top of stack: " << st.peak() << endl;

    st.pop(); // stack underflow

    if(st.isEmpty())
        cout << "stack is empty" << endl;
    else 
        cout << "stack isn't empty" << endl;

    st.push(22);
    st.push(43);
    st.push(65);
    st.push(22);
    st.push(43);
    st.push(65); // stack overflow
    cout<< "peak: " << st.peak() << endl;

    printStack(st);

    return 0;
}