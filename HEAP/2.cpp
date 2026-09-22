#include <bits/stdc++.h>
using namespace std;

// Heapify
// Time Complexity: O(log n)
// Space Complexity: O(log n) recursive stack

void heapify(int arr[], int n, int i) {
    int largest = i;

    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right <= n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

int main() {
    int arr[] = {0, 10, 20, 15, 30, 40};
    int n = 5;

    heapify(arr, n, 2);

    cout << "Max Heap: ";

    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}