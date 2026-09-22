#include <iostream>
#include <vector>
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

void inorder(Node* root, vector<int>& arr) {
    if (root == NULL)
        return;

    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

void preorder(Node* root, vector<int>& arr, int& i) {
    if (root == NULL)
        return;

    root->data = arr[i++];
    preorder(root->left, arr, i);
    preorder(root->right, arr, i);
}

void convertToMinHeap(Node* root) {
    vector<int> arr;

    inorder(root, arr);

    int i = 0;
    preorder(root, arr, i);
}

void printPreorder(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    convertToMinHeap(root);

    printPreorder(root);

    return 0;
}       