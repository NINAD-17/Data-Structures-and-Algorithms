#include <iostream>
using namespace std;

void reachHome(int src, int dest) {
    // Base Case
    if(src == dest) {
        cout << "Reached to destination" << endl;
        return;
    }
    
    cout << "Walk 1 step -- source: " << src << " ; destination: " << dest << endl;

    reachHome(src + 1, dest);
}

int main() {
    int src = 1;
    int dest = 10;

    reachHome(src, dest);

    return 0;
}