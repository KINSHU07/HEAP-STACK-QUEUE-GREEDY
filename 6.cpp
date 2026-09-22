//merge 2 binary tree

#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

vector<int> mergeHeaps(vector<int>& a, vector<int>& b) {
    vector<int> ans = a;

    for (int x : b)
        ans.push_back(x);

    int n = ans.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(ans, n, i);

    return ans;
}

int main() {
    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};

    vector<int> ans = mergeHeaps(a, b);

    for (int x : ans)
        cout << x << " ";

    return 0;
}