// check if its a binary tree or not
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

bool isComplete(Node* root) {
    queue<Node*> q;
    q.push(root);

    bool nullFound = false;

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr == NULL) {
            nullFound = true;
        }
        else {
            if (nullFound)
                return false;

            q.push(curr->left);
            q.push(curr->right);
        }
    }

    return true;
}

bool isMaxHeap(Node* root) {
    if (root == NULL)
        return true;

    if (root->left && root->data < root->left->data)
        return false;

    if (root->right && root->data < root->right->data)
        return false;

    return isMaxHeap(root->left) && isMaxHeap(root->right);
}

bool isHeap(Node* root) {
    return isComplete(root) && isMaxHeap(root);
}

int main() {
    Node* root = new Node(50);

    root->left = new Node(30);
    root->right = new Node(40);

    root->left->left = new Node(10);
    root->left->right = new Node(20);

    if (isHeap(root))
        cout << "It is a Heap";
    else
        cout << "It is not a Heap";

    return 0;
}