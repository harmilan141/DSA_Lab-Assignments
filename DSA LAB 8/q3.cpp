#include <iostream>
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

Node* insertIntoBST(Node* root, int d) {
    if (root == NULL) {
        return new Node(d);
    }
    if (d < root->data) {
        root->left = insertIntoBST(root->left, d);
    }
    else if (d > root->data) {
        root->right = insertIntoBST(root->right, d);
    }
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;

        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int maxDepth(Node* root) {
    if (root == NULL) return 0;
    int leftH = maxDepth(root->left);
    int rightH = maxDepth(root->right);
    return 1 + max(leftH, rightH);
}

int minDepth(Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL) return 1 + minDepth(root->right);
    if (root->right == NULL) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void takeInput(Node* &root) {
    int data;
    cout << "Enter data (-1 to stop): ";
    cin >> data;
    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

int main() {
    Node* root = NULL;
    takeInput(root);

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 50);
    cout << "After deleting 50: ";
    inorder(root);
    cout << endl;

    cout << "Max Depth: " << maxDepth(root) << endl;
    cout << "Min Depth: " << minDepth(root) << endl;

    return 0;
}