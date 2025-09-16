#include <iostream>
using namespace std;

#define SIZE 100

class Queue {
public:
    int items[SIZE];
    int front, rear;

    Queue() {
        front = 0;
        rear = -1;
    }

    void enqueue(int val) {
        rear++;
        items[rear] = val;
    }

    int dequeue() {
        int val = items[front];
        front++;
        return val;
    }

    bool isEmpty() {
        return front > rear;
    }

    int size() {
        return rear - front + 1;
    }

    void display() {
        for (int i = front; i <= rear; i++) {
            cout << items[i] << " ";
        }
        cout << endl;
    }
};

void interleaveQueue(Queue &q) {
    int n = q.size();
    int half = n / 2;
    Queue first, second, result;

    for (int i = 0; i < half; i++) {
        first.enqueue(q.dequeue());
    }
    while (!q.isEmpty()) {
        second.enqueue(q.dequeue());
    }

    while (!first.isEmpty() && !second.isEmpty()) {
        result.enqueue(first.dequeue());
        result.enqueue(second.dequeue());
    }
    while (!first.isEmpty()) {
        result.enqueue(first.dequeue());
    }
    while (!second.isEmpty()) {
        result.enqueue(second.dequeue());
    }

    cout << "Interleaved Queue: ";
    result.display();
}

int main() {
    Queue q;
    int n, val;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        q.enqueue(val);
    }
    interleaveQueue(q);
    return 0;
}
