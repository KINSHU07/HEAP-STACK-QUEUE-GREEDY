#include <bits/stdc++.h>
using namespace std;

int kthLargestSubarraySum(vector<int>& arr, int k) {
    int n = arr.size();

    priority_queue<int, vector<int>, greater<int>> pq;

    // Generate all subarray sums
    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = i; j < n; j++) {
            sum += arr[j];

            pq.push(sum);

            // Keep only k largest sums
            if (pq.size() > k) {
                pq.pop();
            }
        }
    }

    return pq.top();
}

int main() {
    int n, k;

    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> k;

    cout << kthLargestSubarraySum(arr, k) << endl;

    return 0;
}