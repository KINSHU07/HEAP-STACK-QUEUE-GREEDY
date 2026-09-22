// Problem: Assign Cookies
// Time Complexity: O(n log n + m log m)
// Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int i = 0;

    for(int j = 0; j < s.size() && i < g.size(); j++) {
        if(s[j] >= g[i])
            i++;
    }

    return i;
}

int main() {
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};

    cout << findContentChildren(g, s);

    return 0;
}