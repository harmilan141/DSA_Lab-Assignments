#include <iostream>
using namespace std;

#define SIZE 100

class Queue {
public:
    char items[SIZE];
    int front, rear;

    Queue() {
        front = 0;
        rear = -1;
    }

    void enqueue(char val) {
        rear++;
        items[rear] = val;
    }

    char dequeue() {
        char val = items[front];
        front++;
        return val;
    }

    char getFront() {
        return items[front];
    }

    bool isEmpty() {
        return front > rear;
    }

    void display() {
        for (int i = front; i <= rear; i++) {
            cout << items[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int count[256] = {0};
    string input;
    cout << "Enter characters separated by space (end with newline):\n";
    char ch;
    while (cin >> ch) {
        q.enqueue(ch);
        count[ch]++;
        // Find first non-repeating
        while (!q.isEmpty() && count[q.getFront()] > 1) {
            q.dequeue();
        }
        if (!q.isEmpty()) {
            cout << q.getFront() << " ";
        } else {
            cout << "-1 ";
        }
    }
    cout << endl;
    return 0;
}
