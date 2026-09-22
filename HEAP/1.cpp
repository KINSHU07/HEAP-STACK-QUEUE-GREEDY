#include <bits/stdc++.h>
using namespace std;

// Insert element into Max Heap
void insert(int arr[], int &size, int value) {
    size++;
    int index = size;

    arr[index] = value;

    // Move element upward
    while (index > 1) {
        int parent = index / 2;

        if (arr[parent] < arr[index]) {
            swap(arr[parent], arr[index]);
            index = parent;
        }
        else {
            break;
        }
    }
}

// Delete root element from Max Heap
void deleteHeap(int arr[], int &size) {
    if (size == 0) {
        cout << "Heap is empty" << endl;
        return;
    }

    // Put last element at root
    arr[1] = arr[size];
    size--;

    int index = 1;

    // Move element downward
    while (index <= size) {
        int left = 2 * index;
        int right = 2 * index + 1;
        int largest = index;

        if (left <= size && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right <= size && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != index) {
            swap(arr[index], arr[largest]);
            index = largest;
        }
        else {
            break;
        }
    }
}

// Print Heap
void printHeap(int arr[], int size) {
    for (int i = 1; i <= size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    int arr[100];
    int size = 0;

    // Insert elements
    insert(arr, size, 50);
    insert(arr, size, 55);
    insert(arr, size, 53);
    insert(arr, size, 52);
    insert(arr, size, 54);

    cout << "Heap after insertion: ";
    printHeap(arr, size);

    // Delete root
    deleteHeap(arr, size);

    cout << "Heap after deletion: ";
    printHeap(arr, size);

    return 0;
}