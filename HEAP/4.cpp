#include <bits/stdc++.h>
using namespace std;

// Kth Largest Element in an Array
// Time Complexity: O(n + k log n)
// Space Complexity: O(n)

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq;

    // Put all elements into max heap
    for (int i = 0; i < nums.size(); i++) {
        pq.push(nums[i]);
    }

    // Remove k-1 largest elements
    for (int i = 0; i < k - 1; i++) {
        pq.pop();
    }

    return pq.top();
}

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    cout << "Kth largest element: "
         << findKthLargest(nums, k);

    return 0;
}