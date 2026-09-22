#include <iostream>
using namespace std;

class Queue {
    int arr[100];
    int front, rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    void enqueue(int x) {
        if (rear == 99) {
            cout << "Queue Overflow\n";
            return;
        }

        arr[++rear] = x;
    }

    void dequeue() {
        if (front > rear) {
            cout << "Queue Underflow\n";
            return;
        }

        front++;
    }

    int peek() {
        if (front > rear) {
            cout << "Queue Empty\n";
            return -1;
        }

        return arr[front];
    }

    bool empty() {
        return front > rear;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.peek() << endl;  // 10

    q.dequeue();

    cout << q.peek() << endl;  // 20

    return 0;
}