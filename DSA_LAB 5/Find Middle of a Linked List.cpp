#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insert(int val) {
    Node* newNode = new Node{val, head};
    head = newNode;
}

void findMiddle() {
    if (!head) return;
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "Middle Node: " << slow->data << endl;
}

int main() {
    insert(5); insert(4); insert(3); insert(2); insert(1);  // List = 1->2->3->4->5
    findMiddle();
}
