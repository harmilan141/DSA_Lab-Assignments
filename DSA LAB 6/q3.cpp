#include <iostream>
using namespace std;

struct DNode { int data; DNode *prev,*next; };
struct CNode { int data; CNode *next; };

int main() {
    DNode *dh = NULL, *dt = NULL;
    CNode *ch = NULL, *ct = NULL;
    int n, x;

    cout << "DLL n: "; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        DNode *p = new DNode; p->data = x; p->next = NULL;
        if (!dh) dh = dt = p;
        else { dt->next = p; p->prev = dt; dt = p; }
    }
    int ds = 0; DNode *t = dh; while (t) { ds++; t = t->next; }
    cout << "DLL size: " << ds << endl;

    cout << "CLL n: "; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        CNode *p = new CNode; p->data = x;
        if (!ch) ch = ct = p;
        else { ct->next = p; ct = p; }
    }
    if (ch) ct->next = ch;
    int cs = 0; if (ch) { CNode *t = ch; do { cs++; t = t->next; } while (t != ch); }
    cout << "CLL size: " << cs << endl;
    return 0;
}