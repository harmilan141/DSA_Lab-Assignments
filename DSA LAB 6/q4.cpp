#include <iostream>
using namespace std;

struct Node { char data; Node *prev,*next; };

int main() {
    Node *head = NULL, *tail = NULL;
    char c;
    cout << "chars (end with .): ";
    while (cin >> c && c != '.') {
        Node *p = new Node; p->data = c; p->next = NULL;
        if (!head) head = tail = p;
        else { tail->next = p; p->prev = tail; tail = p; }
    }
    Node *l = head, *r = head;
    while (r && r->next) r = r->next;
    bool ok = true;
    while (l && r && l != r && l->prev != r) {
        if (l->data != r->data) { ok = false; break; }
        l = l->next; r = r->prev;
    }
    cout << (ok ? "True" : "False") << endl;
    return 0;
}