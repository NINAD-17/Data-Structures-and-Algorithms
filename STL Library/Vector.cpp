#include <iostream>
#include <vector>
using namespace std;

void printArrOfVector(vector<int> v[], int n) {
    for(int i = 0; i < n; i++) {
        cout << i << "th vector: ";
        for(int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printNestedVector(vector<pair<int, int>> v) {
    for(int i = 0; i < v.size(); i++) 
        cout << v[i].first << " " << v[i].second << endl;
    cout << endl;
}

void printVector(vector<int> v) {
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

int main() {

    vector<int> v;

    cout << "Size -> " << v.size() << endl; // Size means total element present in vector
    cout << "Capacity -> " << v.capacity() << endl << endl; // Capacity means how much memory is allocated/ for how many elements memory is allocated.

    v.push_back(1); // To insert element
    cout << "Size -> " << v.size() << endl;
    cout << "Capacity -> " << v.capacity() << endl << endl;

    v.push_back(2);
    cout << "Size -> " << v.size() << endl;
    cout << "Capacity -> " << v.capacity() << endl << endl;

    v.push_back(3);
    cout << "Size -> " << v.size() << endl;
    cout << "Capacity -> " << v.capacity() << endl << endl;

    v.push_back(4);
    cout << "Size -> " << v.size() << endl;
    cout << "Capacity -> " << v.capacity() << endl << endl;


    // Previously total capacity of vector was 4 but when we add another element '5' it doubled its capacity to '8 (4 * 2)'
    v.push_back(5);
    cout << "Size -> " << v.size() << endl;
    cout << "Capacity -> " << v.capacity() << endl << endl;

    cout << "Element at 2nd index: " << v.at(2) << endl;
    cout << "1st element: " << v.front() << endl;
    cout << "2nd element: " << v.back() << endl;

    // pop_back: It used to remove last element
    cout << "Before pop: ";
    printVector(v);
    v.pop_back();
    cout << "After pop: ";
    printVector(v);
    
    
    // Clear
    cout << "Before Clear - size & Capacity => " << v.size() << " & " << v.capacity() << endl;
    v.clear();
    cout << "After Clear - size & Capacity => " << v.size() << " & " << v.capacity() << endl;


    // To initialize vector with any value
    vector<int> v1(5, 10); // v1(sizeOfArr, value)
    cout << "\nVector v1: ";
    printVector(v1);


    // To copy vector in another vector (it's not referring like Arrays therefore time complexity: O(n))
    vector<int> last(v1);
    cout << "Vector last: ";
    printVector(last);


    // Add element from user input
    // vector<int> userIp;
    // int n;
    // cout << "Enter size of vector: ";
    // cin >> n;

    // for(int i = 0; i < n; i++) {
    //     int element;
    //     cout << "Enter " << i + 1 << "th element: ";
    //     cin >> element;
    //     userIp.push_back(element);
    // }
    // cout << "userIp Vector: ";
    // printVector(userIp);



    // -------------------------------------------------
    // -------------------------------------------------
    // Nested Vectors
    vector<pair<int, int>> v_pair = {{1, 2}, {3, 4}, {4, 5}};
    cout << "\n\nv_pair: \n";
    printNestedVector(v_pair);


    // Array of Vectors:
    // int numVectors;
    // cout << "\nHow many vectors you want? ";
    // cin >> numVectors;
    // vector<int> v_arr[10]; // How many vectors you want? means array's size (fixed value)
    // for(int i = 0; i < numVectors; i++) {
    //     int n;
    //     cout << "Enter size of vector: ";
    //     cin >> n; // Enter size of one vector
    //     for(int j = 0; j < n; j++) {
    //         int x;
    //         cin >> x; // Individual values
    //         v_arr[i].push_back(x);
    //     }
    // }
    // printArrOfVector(v_arr, numVectors);


    // Vector of Vectors
    int numVect;
    cout << "\n\nEnter how many vectors you want? ";
    cin >> numVect;
    vector<vector<int>> v_vect;
    for(int i = 0; i < numVect; i++) {
        int n;
        cout << "Enter size of " << i << "th vector";
        cin >> n; 
        vector<int> temp;
        cout << "Enter " << n << " elements";
        for(int i = 0; i < n; i++) {
            int x; 
            cin >> x; // element
            temp.push_back(x);
        }
        v_vect.push_back(temp);
    }

    for(int i = 0; i < numVect; i++) {
        printVector(v_vect[i]);
    }

    return 0;
}