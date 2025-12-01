#include <iostream>
using namespace std;

struct Node { int data; Node *next; };

int main() {
    Node *head = NULL, *tail = NULL;
    int n, x, make;
    cout << "n: "; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        Node *p = new Node; p->data = x;
        if (!head) head = tail = p;
        else { tail->next = p; tail = p; }
    }
    cout << "make circular (1/0): "; cin >> make;
    if (make && head) tail->next = head;

    bool circ = false;
    if (head) {
        Node *s = head, *f = head;
        while (f && f->next) {
            s = s->next; f = f->next->next;
            if (s == f) { circ = true; break; }
        }
    }
    cout << (circ ? "True" : "False") << endl;
    return 0;
}