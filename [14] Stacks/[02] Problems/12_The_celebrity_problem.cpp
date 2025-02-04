#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// THE CELEBRITY PROBLEM (medium/hard)

// ---- optimized approach using stack ----
// time complexity: O(n)
// space complexity: O(n)
bool knows(vector<vector<int>> &persons, int a, int b) {
    if(persons[a][b] == 1) // if a knows b then it's 1 in a matrix
        return true;
    else 
        return false;
}

int searchCelebrity(vector<vector<int>> &persons) {
    // find total number of persons (total rows or cols)
    int totalPersons = persons.size();

    stack<int> st; // to put all the elements (persons) inside the stack

    // step 1: push all the elements (persons) in the stack
    for(int i = 0; i < totalPersons; i++)
        st.push(i);

    // step 2: untill stack isn't left with one element (person), pop the elements
    while(st.size() != 1) {
        // store two elements (persons) in variable 'a' and 'b'. they represents two different persons
        int a = st.top();
        st.pop();

        int b = st.top();
        st.pop();

        // check if one person knows other or not
        if(knows(persons, a, b))
            st.push(b); // 'a' knows 'b' so discard it (that person because he's not a celebrity as he knows other person) and push 'b' in stack
        else 
            st.push(a); // same as above but 'b' isn't celebrity
    }

    // step 3: single element left in stack. it can be a potential celebrity element
    // verify: (1) does he know someone? (ans should be "NO", to be a celebrity)
    //         (2) do other people know him? (ans should be "YES", to be a celebrity)
    int candidate = st.top();

    // 1. row check: all elements should be zero
    bool rowCheck = false;
    int zeroCount = 0;
    for(int i = 0; i < totalPersons; i++) {
        if(persons[candidate][0] == 0)
            zeroCount++;
    }

    if(zeroCount == totalPersons)
        rowCheck = true;

    // 2. col check: all cols should be 1 except diagonal element
    bool colCheck = false;
    int oneCount = 0;

    for(int i = 0; i < totalPersons; i++) {
        if(persons[i][candidate] == 1)
            oneCount++;
    }

    if(oneCount == totalPersons - 1)
        colCheck = true;

    // Check whether both conditions are satisfied.
    if(rowCheck && colCheck)
        return candidate;
    else
        return -1;
}

// ---- brute force approach ----
// time complexity: O(n^2)
// space complexity: O(1)
int findCelebrity(vector<vector<int>> &persons) {
    // find total number of persons (total rows or cols)
    int totalPersons = persons.size();

    // check each person for
    // --> 1. is he knows anybody from party?
    // --> 2. are the other persons from party know him?
    //     -- if he knows nobody and all other persons knows him then he is a celebrity
    for(int i = 0; i < totalPersons; i++) {
        bool isCelebrity = true; // assuming person is a celebrity 

        // row: if all row elements are 0 then the person can be a celebrity
        for(int j = 0; j < persons[i].size(); j++) {
            if(i == j) // don't see diagonal elements
                continue;
            else if(persons[i][j] != 0) {
                isCelebrity = false; // if any one element found without zero means he's not celebrity so break this loop
                break;
            }
        }

        if(!isCelebrity)
            continue; // if the person not satisfy above loop then no need to check col for it. continue to next person

        // col: if all elements are 1 in a column except the diagonal element then he's a celebrity because he passed both conditions
        for(int k = 0; k < persons[i].size(); k++) {
            if(i == k)
                continue;
            
            if(persons[k][i] != 1) {
                isCelebrity = false;
                break;
            }
        }

        // celebrity found :)
        if(isCelebrity)
            return i; // index of celebrity
    }

    return -1; // if there's no celebrity
}

int main() {

    vector<vector<int>> persons = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};

    cout << "celebrity is person whose index is " << findCelebrity(persons) << endl;
    cout << "celebrity is person whose index is " << searchCelebrity(persons) << endl;

    return 0;
}