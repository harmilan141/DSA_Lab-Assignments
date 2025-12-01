// 6. Priority Queue using Heap (Max Heap)

#include <iostream>
using namespace std;

class PriorityQueue {
    int* heap;
    int capacity;
    int size;

public:
    PriorityQueue(int cap) {
        capacity = cap;
        size = 0;
        heap = new int[cap];
    }

    void push(int val) {
        if (size == capacity) {
            cout << "Full\n";
            return;
        }
        heap[size] = val;
        int i = size++;
        while (i > 0) {
            int parent = (i-1)/2;
            if (heap[parent] < heap[i]) {
                swap(heap[parent], heap[i]);
                i = parent;
            }
            else break;
        }
    }

    void pop() {
        if (size == 0) return;
        heap[0] = heap[--size];
        int i = 0;
        while (true) {
            int left = 2*i + 1;
            int right = 2*i + 2;
            int largest = i;

            if (left < size && heap[left] > heap[largest])
                largest = left;
            if (right < size && heap[right] > heap[largest])
                largest = right;

            if (largest != i) {
                swap(heap[i], heap[largest]);
                i = largest;
            }
            else break;
        }
    }

    int top() {
        if (size == 0) return -1;
        return heap[0];
    }

    bool empty() {
        return size == 0;
    }
};

int main() {
    PriorityQueue pq(10);

    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);
    pq.push(40);

    cout << "Top: " << pq.top() << endl;
    pq.pop();
    cout << "After pop, top: " << pq.top() << endl;

    return 0;
}