// Problem: Shortest Job First (SJF)
// Time Complexity: O(n log n)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int SJF(vector<int>& bt) {
    sort(bt.begin(), bt.end());

    int wait = 0;
    int total = 0;

    for(int i = 0; i < bt.size(); i++) {
        total += wait;
        wait += bt[i];
    }

    return total / bt.size();
}

int main() {
    vector<int> bt = {4, 3, 7, 1, 2};

    cout << SJF(bt);

    return 0;
}