#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Build BST recursively
node* buildTree(node* root) {
    int data;
    cout << "Enter Data: ";
    cin >> data;

    if (data == -1) return nullptr;

    root = new node(data);

    cout << "Enter data for inserting in left of " << data << ": ";
    root->left = buildTree(root->left);

    cout << "Enter data for inserting in right of " << data << ": ";
    root->right = buildTree(root->right);

    return root;
}

// (a) Search a given item (Recursive)
bool searchItemRecursive(node* root, int key) {
    if (root == nullptr) return false;
    if (root->data == key) return true;

    if (key < root->data)
        return searchItemRecursive(root->left, key);
    else
        return searchItemRecursive(root->right, key);
}

// (a) Search a given item (Iterative)
bool searchItemIterative(node* root, int key) {
    node* curr = root;
    while (curr != nullptr) {
        if (key == curr->data) return true;
        else if (key < curr->data) curr = curr->left;
        else curr = curr->right;
    }
    return false;
}

// (b) Maximum element of the BST
int max(node* root) {
    if (root == nullptr) return -1;
    while (root->right != nullptr)
        root = root->right;
    return root->data;
}

// (c) Minimum element of the BST
int min(node* root) {
    if (root == nullptr) return -1;
    while (root->left != nullptr)
        root = root->left;
    return root->data;
}

// Helper: leftmost node
node* leftmost(node* n) {
    while (n && n->left) n = n->left;
    return n;
}

// Helper: rightmost node
node* rightmost(node* n) {
    while (n && n->right) n = n->right;
    return n;
}

// (d) In-order successor of a given node
node* inOrderSuccessor(node* root, node* p) {
    if (!root || !p) return nullptr;

    // Case 1: p has right child → leftmost of right subtree
    if (p->right) return leftmost(p->right);

    // Case 2: No right child → go up from root to find lowest ancestor
    node* succ = nullptr;
    node* curr = root;

    while (curr) {
        if (p->data < curr->data) {
            succ = curr;
            curr = curr->left;
        }
        else if (p->data > curr->data) {
            curr = curr->right;
        }
        else break;
    }
    return succ;
}

// (e) In-order predecessor of a given node
node* inorderPredecessor(node* root, node* p) {
    if (!root || !p) return nullptr;

    // Case 1: p has left child → rightmost of left subtree
    if (p->left) return rightmost(p->left);

    // Case 2: No left child → find lowest ancestor where p is in right subtree
    node* pred = nullptr;
    node* curr = root;

    while (curr) {
        if (p->data > curr->data) {
            pred = curr;
            curr = curr->right;
        }
        else if (p->data < curr->data) {
            curr = curr->left;
        }
        else break;
    }
    return pred;
}

// Main function with menu
int main() {
    node* root = nullptr;
    int choice, key;

    cout << "Build Tree (enter -1 for NULL):\n";
    root = buildTree(root);

    while (true) {
        cout << "\n=== BST Operations ===\n";
        cout << "1. Recursive Search\n";
        cout << "2. Iterative Search\n";
        cout << "3. Maximum Element\n";
        cout << "4. Minimum Element\n";
        cout << "5. In-order Successor\n";
        cout << "6. In-order Predecessor\n";
        cout << "7. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 7) {
            cout << "Exiting...\n";
            break;
        }

        switch (choice) {
            case 1: {
                cout << "Enter key to search: ";
                cin >> key;
                cout << (searchItemRecursive(root, key) ? "Found" : "Not Found") << endl;
                break;
            }
            case 2: {
                cout << "Enter key to search: ";
                cin >> key;
                cout << (searchItemIterative(root, key) ? "Found" : "Not Found") << endl;
                break;
            }
            case 3: {
                int mx = max(root);
                cout << (mx == -1 ? "Tree is empty!" : "Maximum: " + to_string(mx)) << endl;
                break;
            }
            case 4: {
                int mn = min(root);
                cout << (mn == -1 ? "Tree is empty!" : "Minimum: " + to_string(mn)) << endl;
                break;
            }
            case 5: {
                cout << "Enter node value for successor: ";
                cin >> key;
                node* p = root;
                while (p && p->data != key) {
                    p = (key < p->data) ? p->left : p->right;
                }
                if (!p) { cout << "Node not found!\n"; break; }
                node* succ = inOrderSuccessor(root, p);
                cout << "Successor: " << (succ ? to_string(succ->data) : "NONE") << endl;
                break;
            }
            case 6: {
                cout << "Enter node value for predecessor: ";
                cin >> key;
                node* p = root;
                while (p && p->data != key) {
                    p = (key < p->data) ? p->left : p->right;
                }
                if (!p) { cout << "Node not found!\n"; break; }
                node* pred = inorderPredecessor(root, p);
                cout << "Predecessor: " << (pred ? to_string(pred->data) : "NONE") << endl;
                break;
            }
            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}