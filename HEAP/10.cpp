#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    int row;
    int col;

    Node(int d, int r, int c) {
        data = d;
        row = r;
        col = c;
    }
};

// Min heap comparator
class Compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

vector<int> mergeKArrays(vector<vector<int>>& arr, int K) {

    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Put first element of every array
    for (int i = 0; i < K; i++) {
        if (!arr[i].empty()) {
            pq.push(new Node(arr[i][0], i, 0));
        }
    }

    vector<int> ans;

    while (!pq.empty()) {

        Node* temp = pq.top();
        pq.pop();

        int value = temp->data;
        int row = temp->row;
        int col = temp->col;

        ans.push_back(value);

        // Insert next element from same array
        if (col + 1 < arr[row].size()) {
            pq.push(new Node(arr[row][col + 1], row, col + 1));
        }

        delete temp;
    }

    return ans;
}

int main() {

    int K;
    cin >> K;

    vector<vector<int>> arr(K);

    for (int i = 0; i < K; i++) {
        int n;
        cin >> n;

        arr[i].resize(n);

        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    vector<int> ans = mergeKArrays(arr, K);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}