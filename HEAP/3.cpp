#include <bits/stdc++.h>
using namespace std;

// Heap Sort
// Time Complexity: O(n log n)
// Space Complexity: O(log n) due to recursive heapify

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[left] > arr[largest])
        largest = left;

    if (right <= n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {

    // Build Max Heap
    for (int i = n / 2; i >= 1; i--) {
        heapify(arr, n, i);
    }

    // Remove elements one by one
    for (int i = n; i > 1; i--) {
        swap(arr[1], arr[i]);
        heapify(arr, i - 1, 1);
    }
}

int main() {

    // 1-based indexing
    int arr[] = {0, 10, 5, 20, 2, 15};
    int n = 5;

    heapSort(arr, n);

    cout << "Sorted array: ";

    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}