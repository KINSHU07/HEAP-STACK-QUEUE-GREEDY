// Problem: Job Sequencing Problem
// Time Complexity: O(n log n + n * maxDeadline)
// Space Complexity: O(maxDeadline)

#include <bits/stdc++.h>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

pair<int, int> jobScheduling(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), [](Job a, Job b) {
        return a.profit > b.profit;
    });

    int maxDeadline = 0;

    for(auto job : jobs)
        maxDeadline = max(maxDeadline, job.deadline);

    vector<int> slot(maxDeadline + 1, -1);

    int count = 0;
    int profit = 0;

    for(int i = 0; i < jobs.size(); i++) {
        for(int j = jobs[i].deadline; j >= 1; j--) {
            if(slot[j] == -1) {
                slot[j] = i;
                count++;
                profit += jobs[i].profit;
                break;
            }
        }
    }

    return {count, profit};
}

int main() {
    vector<Job> jobs = {
        {'a', 2, 100},
        {'b', 1, 19},
        {'c', 2, 27},
        {'d', 1, 25},
        {'e', 3, 15}
    };

    pair<int, int> ans = jobScheduling(jobs);

    cout << "Jobs: " << ans.first << endl;
    cout << "Maximum Profit: " << ans.second << endl;

    return 0;
}