#include <bits/stdc++.h>
using namespace std;

// Minimum Number of Platforms
// Time Complexity: O(n log n)
// Space Complexity: O(1) apart from sorting

int findPlatform(vector<int>& arrival, vector<int>& departure) {
    int n = arrival.size();

    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    int i = 0;
    int j = 0;

    int platforms = 0;
    int maxPlatforms = 0;

    while (i < n && j < n) {

        // New train arrives before previous train departs
        if (arrival[i] <= departure[j]) {
            platforms++;
            maxPlatforms = max(maxPlatforms, platforms);
            i++;
        }
        else {
            // A train has departed
            platforms--;
            j++;
        }
    }

    return maxPlatforms;
}

int main() {

    vector<int> arrival = {900, 940, 950, 1100, 1500, 1800};

    vector<int> departure = {910, 1200, 1120, 1130, 1900, 2000};

    cout << "Minimum platforms required: "
         << findPlatform(arrival, departure);

    return 0;
}