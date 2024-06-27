#include <iostream>
using namespace std;

void printArr(int *arr, int n) {
    for(int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void heapify(int *arr, int size, int index) {
    int largestElementIndex = index;
    int leftChildIndex = 2 * index;
    int rightChildIndex = 2 * index + 1;

    if(leftChildIndex <= size && arr[largestElementIndex] < arr[leftChildIndex])
        largestElementIndex = leftChildIndex;
    
    if(rightChildIndex <= size && arr[largestElementIndex] < arr[rightChildIndex])
        largestElementIndex = rightChildIndex;

    if(largestElementIndex != index) {
        swap(arr[largestElementIndex], arr[index]);
        heapify(arr, size, largestElementIndex);
    }
}

void heapSort(int *arr, int size) {
    int n = size; // using this for printing array. just for debugging

    while(size > 1) {
        // 1st element is greater in max heap so swap it with last element which is small
        swap(arr[1], arr[size]); // considering heap arr starts from index 1 and not from 0
        size--;

        printArr(arr, n);

        // after swapping, apply heapify function to move that element in correct position
        heapify(arr, size, 1); // 1st element in heapify 
    }
}

int main() {

    int arr[6] = {-1, 70, 60, 55, 45, 50};
    int size = 5;

    cout << "printing before heap sort: ";
    printArr(arr, size);

    heapSort(arr, size);

    cout << "printing after heap sort: ";
    printArr(arr, size);

    return 0;
}