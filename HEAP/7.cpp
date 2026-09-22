//minimum cost to connect ropes
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minCost(vector<int>& ropes) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int x : ropes)
        pq.push(x);

    int cost = 0;

    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();

        int sum = a + b;
        cost += sum;

        pq.push(sum);
    }

    return cost;
}

int main() {
    vector<int> ropes = {4, 3, 2, 6};

    cout << minCost(ropes);

    return 0;
}