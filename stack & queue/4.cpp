#include <iostream>
#include <list>
using namespace std;

class Queue {
    list<int> l;

public:
    void enqueue(int x) {
        l.push_back(x);
    }

    void dequeue() {
        if (l.empty()) {
            cout << "Queue Underflow\n";
            return;
        }

        l.pop_front();
    }

    int peek() {
        if (l.empty()) {
            return -1;
        }

        return l.front();
    }

    bool empty() {
        return l.empty();
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.peek() << endl; // 10

    q.dequeue();

    cout << q.peek() << endl; // 20
}