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

    bool isEmpty() {
        return front > rear;
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

    int getFront() {
        return items[front];
    }

    int size() {
        return rear - front + 1;
    }
};

class Stack {
    Queue q1, q2;

public:
    void push(int val) {
        q2.enqueue(val);
        while (!q1.isEmpty()) {
            q2.enqueue(q1.dequeue());
        }
        swap(q1, q2);
    }

    void pop() {
        if (q1.isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Popped " << q1.dequeue() << endl;
    }

    void display() {
        if (q1.isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        for (int i = q1.front; i <= q1.rear; i++) {
            cout << q1.items[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    int choice, val;
    do {
        cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                s.push(val);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);
    return 0;
}
