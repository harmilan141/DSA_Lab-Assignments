#include <iostream>
using namespace std;

struct CNode { int data; CNode *next; };

int main() {
    CNode *head = NULL, *tail = NULL;
    int n, x;
    cout << "n: "; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        CNode *p = new CNode; p->data = x;
        if (!head) head = tail = p;
        else { tail->next = p; tail = p; }
    }
    if (head) tail->next = head;
    if (head) {
        CNode *t = head;
        do { cout << t->data << " "; t = t->next; } while (t != head);
        cout << head->data << endl;
    }
    return 0;
}