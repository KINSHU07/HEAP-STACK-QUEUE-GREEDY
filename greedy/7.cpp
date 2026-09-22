// Problem: N Meetings in One Room
// Time Complexity: O(n log n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

int maxMeetings(vector<int>& start, vector<int>& end) {
    int n = start.size();

    vector<pair<int, int>> meetings;

    for(int i = 0; i < n; i++)
        meetings.push_back({end[i], start[i]});

    sort(meetings.begin(), meetings.end());

    int ans = 0;
    int lastEnd = -1;

    for(int i = 0; i < n; i++) {
        if(meetings[i].second > lastEnd) {
            ans++;
            lastEnd = meetings[i].first;
        }
    }

    return ans;
}

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    cout << maxMeetings(start, end);

    return 0;
}