#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

class Compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

Node* mergeKLists(vector<Node*>& lists) {

    priority_queue<Node*, vector<Node*>, Compare> pq;

    // First node of every list
    for (int i = 0; i < lists.size(); i++) {
        if (lists[i] != NULL)
            pq.push(lists[i]);
    }

    Node* head = NULL;
    Node* tail = NULL;

    while (!pq.empty()) {

        Node* temp = pq.top();
        pq.pop();

        if (head == NULL) {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }

        // Next node from same list
        if (temp->next != NULL)
            pq.push(temp->next);
    }

    return head;
}