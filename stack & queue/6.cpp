#include <bits/stdc++.h>
using namespace std;

class Queue {
    stack<int> s1, s2;

public:

    // Push element into queue
    void push(int x) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // Remove element
    int pop() {
        if (s1.empty()) {
            return -1;
        }

        int x = s1.top();
        s1.pop();

        return x;
    }

    // Get front element
    int peek() {
        if (s1.empty()) {
            return -1;
        }

        return s1.top();
    }

    // Check empty
    bool empty() {
        return s1.empty();
    }
};

int main() {

    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << q.peek() << endl;  // 10

    q.pop();

    cout << q.peek() << endl;  // 20

    return 0;
}