#include <iostream>
using namespace std;

#define SIZE 100

class Stack {
    int arr[SIZE];
    int top;
public:
    Stack() { top = -1; }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == SIZE - 1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++top] = x;
        cout << x << " pushed into stack.\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return;
        }
        cout << arr[top--] << " popped from stack.\n";
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Top element: " << arr[top] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack st;
    int choice, val;
    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. isFull\n6. Display\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> val;
            st.push(val);
            break;
        case 2:
            st.pop();
            break;
        case 3:
            st.peek();
            break;
        case 4:
            cout << (st.isEmpty() ? "Stack is Empty\n" : "Stack is not Empty\n");
            break;
        case 5:
            cout << (st.isFull() ? "Stack is Full\n" : "Stack is not Full\n");
            break;
        case 6:
            st.display();
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}
