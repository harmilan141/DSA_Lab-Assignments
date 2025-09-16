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

    int size() {
        return rear - front + 1;
    }

    int getFront() {
        return items[front];
    }

    void display() {
        for (int i = front; i <= rear; i++) {
            cout << items[i] << " ";
        }
        cout << endl;
    }
};

class Stack {
    Queue q;

public:
    void push(int val) {
        int s = q.size();
        q.enqueue(val);
        for (int i = 0; i < s; i++) {
            q.enqueue(q.dequeue());
        }
    }

    void pop() {
        if (q.isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Popped " << q.dequeue() << endl;
    }

    void display() {
        if (q.isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        q.display();
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
