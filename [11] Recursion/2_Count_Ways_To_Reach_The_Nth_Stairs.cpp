#include <iostream>
using namespace std;

// Problem Link: https://www.codingninjas.com/studio/problems/count-ways-to-reach-nth-stairs_798650?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_10&leftPanelTab=1

int countWays(int nStairs) {
    // Base Case -> if we're on ground stair or on 1st stair then there is only one way to climb it.
    if(nStairs == 0 || nStairs == 1) return 1;

    // Recursive Relation
    return countWays(nStairs - 1) + countWays(nStairs - 2);
}

int main() {
    int nStairs;

    cout << "Enter number of stairs: ";
    cin >> nStairs;

    cout << "You can have " << countWays(nStairs) << " ways to climb stairs." << endl;
    return 0;
}