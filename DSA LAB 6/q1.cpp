#include <iostream>
using namespace std;

struct DNode { int data; DNode *prev,*next; };
struct CNode { int data; CNode *next; };

int main() {
    DNode *dh = NULL;
    CNode *ch = NULL, *ct = NULL;
    int op, v, k;

    while (1) {
        cout << "\n--- DOUBLY LINKED LIST ---\n";
        cout << "1. Insert First\n";
        cout << "2. Insert Last\n";
        cout << "3. Insert After Node\n";
        cout << "4. Insert Before Node\n";
        cout << "5. Delete Node\n";
        cout << "6. Search Node\n";
        cout << "7. Display List\n\n";

        cout << "--- CIRCULAR LINKED LIST ---\n";
        cout << "8. Insert First\n";
        cout << "9. Insert Last\n";
        cout << "10. Insert After Node\n";
        cout << "11. Insert Before Node\n";
        cout << "12. Delete Node\n";
        cout << "13. Search Node\n";
        cout << "14. Display List\n";
        cout << "15. Exit\n";

        cout << "Enter choice: ";
        cin >> op;

        if (op == 15) break;

        // === DOUBLY LINKED LIST OPERATIONS ===
        if (op >= 1 && op <= 7) {
            if (op == 1) {
                cout << "Enter value: "; cin >> v;
                DNode *p = new DNode; p->data = v; p->next = dh; p->prev = NULL;
                if (dh) dh->prev = p; dh = p;
            }
            if (op == 2) {
                cout << "Enter value: "; cin >> v;
                DNode *p = new DNode; p->data = v; p->next = NULL;
                if (!dh) { dh = p; }
                else { DNode *t = dh; while (t->next) t = t->next; t->next = p; p->prev = t; }
            }
            if (op == 3) {
                cout << "Enter key and value: "; cin >> k >> v;
                DNode *t = dh; while (t && t->data != k) t = t->next;
                if (t) {
                    DNode *p = new DNode; p->data = v; p->next = t->next; p->prev = t;
                    if (t->next) t->next->prev = p; t->next = p;
                } else cout << "Key not found!\n";
            }
            if (op == 4) {
                cout << "Enter key and value: "; cin >> k >> v;
                DNode *t = dh; while (t && t->data != k) t = t->next;
                if (t) {
                    DNode *p = new DNode; p->data = v; p->prev = t->prev; p->next = t;
                    if (t->prev) t->prev->next = p; else dh = p; t->prev = p;
                } else cout << "Key not found!\n";
            }
            if (op == 5) {
                cout << "Enter value to delete: "; cin >> v;
                DNode *t = dh; while (t && t->data != v) t = t->next;
                if (t) {
                    if (t->prev) t->prev->next = t->next; else dh = t->next;
                    if (t->next) t->next->prev = t->prev; delete t;
                } else cout << "Value not found!\n";
            }
            if (op == 6) {
                cout << "Enter value to search: "; cin >> v;
                DNode *t = dh; while (t && t->data != v) t = t->next;
                cout << (t ? "Found" : "Not found") << endl;
            }
            if (op == 7) {
                DNode *t = dh; while (t) { cout << t->data << " "; t = t->next; } cout << endl;
            }
        }

        // === CIRCULAR LINKED LIST OPERATIONS ===
        else if (op >= 8 && op <= 14) {
            int cop = op - 7; // map 8→1, 9→2, etc.
            if (cop == 1) {
                cout << "Enter value: "; cin >> v;
                CNode *p = new CNode; p->data = v;
                if (!ch) { ch = ct = p; p->next = ch; }
                else { ct->next = p; p->next = ch; ch = p; }
            }
            if (cop == 2) {
                cout << "Enter value: "; cin >> v;
                CNode *p = new CNode; p->data = v;
                if (!ch) { ch = ct = p; p->next = ch; }
                else { ct->next = p; p->next = ch; ct = p; }
            }
            if (cop == 3) {
                cout << "Enter key and value: "; cin >> k >> v;
                CNode *t = ch;
                if (ch) do { if (t->data == k) break; t = t->next; } while (t != ch);
                if (t && t->data == k) {
                    CNode *p = new CNode; p->data = v; p->next = t->next; t->next = p;
                } else cout << "Key not found!\n";
            }
            if (cop == 4) {
                cout << "Enter key and value: "; cin >> k >> v;
                CNode *t = ch, *pr = NULL;
                if (ch) do { if (t->data == k) break; pr = t; t = t->next; } while (t != ch);
                if (t && t->data == k) {
                    CNode *p = new CNode; p->data = v; p->next = t;
                    if (pr) pr->next = p; else ch = p;
                } else cout << "Key not found!\n";
            }
            if (cop == 5) {
                cout << "Enter value to delete: "; cin >> v;
                if (!ch) { cout << "List empty!\n"; continue; }
                CNode *t = ch, *pr = NULL;
                do { if (t->data == v) break; pr = t; t = t->next; } while (t != ch);
                if (t->data == v) {
                    if (t->next == t) { delete t; ch = NULL; }
                    else { if (pr) pr->next = t->next; else ch = t->next; delete t; }
                } else cout << "Value not found!\n";
            }
            if (cop == 6) {
                cout << "Enter value to search: "; cin >> v;
                bool found = false;
                if (ch) { CNode *t = ch; do { if (t->data == v) found = true; t = t->next; } while (t != ch); }
                cout << (found ? "Found" : "Not found") << endl;
            }
            if (cop == 7) {
                if (!ch) { cout << "(empty)\n"; continue; }
                CNode *t = ch;
                do { cout << t->data << " "; t = t->next; } while (t != ch);
                cout << ch->data << endl;
            }
        }
        else {
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}