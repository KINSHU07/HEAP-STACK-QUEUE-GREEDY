#include <bits/stdc++.h>
using namespace std;

// LeetCode 57: Insert Interval
// Time Complexity: O(n)
// Space Complexity: O(n)

vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int n = intervals.size();
    vector<vector<int>> res;
    int i = 0;

    // Add intervals before newInterval
    while (i < n && intervals[i][1] < newInterval[0]) {
        res.push_back(intervals[i]);
        i++;
    }

    // Merge overlapping intervals
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }

    // Add merged interval
    res.push_back(newInterval);

    // Add remaining intervals
    while (i < n) {
        res.push_back(intervals[i]);
        i++;
    }

    return res;
}

int main() {
    vector<vector<int>> intervals = {
        {1, 3},
        {6, 9}
    };

    vector<int> newInterval = {2, 5};

    vector<vector<int>> ans = insertInterval(intervals, newInterval);

    for (auto interval : ans) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }

    return 0;
}