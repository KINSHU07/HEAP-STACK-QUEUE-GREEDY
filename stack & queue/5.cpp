#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q;

public:

    void push(int x) {
        q.push(x);

        // Move previous elements behind x
        int n = q.size();

        for (int i = 0; i < n - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack Underflow\n";
            return;
        }

        q.pop();
    }

    int top() {
        if (q.empty()) {
            return -1;
        }

        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {

    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.top() << endl; // 30

    s.pop();

    cout << s.top() << endl; // 20

    return 0;
}