
#include <iostream>
#include<climits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

bool isBST(Node* root, long minVal, long maxVal) {
    if (root == NULL) return true;
    if (root->data <= minVal || root->data >= maxVal) return false;

    return isBST(root->left, minVal, root->data) &&
           isBST(root->right, root->data, maxVal);
}

bool checkBST(Node* root) {
    return isBST(root, LONG_MIN, LONG_MAX);
}

Node* insert(Node* root, int d) {
    if (root == NULL) return new Node(d);
    if (d < root->data)
        root->left = insert(root->left, d);
    else
        root->right = insert(root->right, d);
    return root;
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    if (checkBST(root))
        cout << "Yes, it is a BST" << endl;
    else
        cout << "Not a BST" << endl;

    return 0;
}