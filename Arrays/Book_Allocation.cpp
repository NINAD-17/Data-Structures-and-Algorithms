#include <iostream> 
#include <climits>
using namespace std;

// Problem Link: https://www.codingninjas.com/studio/library/book-allocation-problem

// Brute Force Solution
// Time Complexity: O(n^2)
int bookAllocation_bruteForce(int *books, int noOfBooks) {
    int ans = INT_MAX, sum1 = 0;
    
    for(int i = 0; i < noOfBooks - 1; i++) {
        sum1 += books[i];
        int sum2 = 0, currAns = 0;

        for(int j = i + 1; j < noOfBooks; j++)
            sum2 += books[j];

        // Find Max Book Pages Allocation
        if(sum1 > sum2) 
            currAns = sum1;
        else    
            currAns = sum2;

        // Update Actual Ans
        if(currAns < ans)
            ans = currAns;
    }

    return ans;
}

int main() {
    int books[10], noOfBooks;

    cout << "Enter total number of books: ";
    cin >> noOfBooks;

    cout << "Enter total pages of each book: ";
    for(int i = 0; i < noOfBooks; i++)
        cin >> books[i];

    cout << "The minimum of the maximum number of pages assigned is " << bookAllocation_bruteForce(books, noOfBooks) << endl;
    return 0;
}